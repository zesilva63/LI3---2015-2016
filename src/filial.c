#include "./headers/filial.h"

#include <stdlib.h>
#include <string.h>


struct filial {
    Catalogo clientes;
    Catalogo produtos;
};

/*Estrutura inserida em cada nodo referente a um cliente */

typedef struct nodo_clientes {
    AVL meses_produtos[12]; /* catálogo com 12 avl's para inserção dos produtos com base no mês */
    int total_quantidades[12];
} *Nodo_Clientes;


/* Estrutura inserida em cada produto associado a cada cliente */

typedef struct lista_produtos {
	int quantidade;
	double faturacao;
	char* produto;
} *Lista_Produtos;


/*Estrutura inserida em cada nodo referente a um produto */

typedef struct nodo_produtos{
	int quantidade;
	Conj_Filiais clientes_N;
	Conj_Filiais clientes_P;
} *Nodo_Produtos;



struct conjunto_filiais {
	Array lista;
};


struct heap_filial {
	Heap heap;
};


static Nodo_Clientes init_Nodo_Clientes();
static Lista_Produtos init_Lista_Produtos();
static Nodo_Produtos init_Nodo_Produtos();
static HEAP converte_Heap_clientes_aux(HEAP h, NODO n, char ordenacao);
static HEAP converte_Heap_produtos_aux(HEAP h, NODO n);
static HEAP converte_Heap_clientes(HEAP h, AVL a, char ordenacao);
static HEAP converte_Heap_produto(HEAP h, AVL a);
static Boolean existe_Conj_Filiais(Conj_Filiais c, char* valor);
static void free_Nodo_Produtos(void* n);
static void free_Nodo_Clientes(void* x);
static void free_Lista_Produtos(void* n);


Filial cria_Dados_Filial(Filial filial, Cat_Produtos produtos, Cat_Clientes clientes) {
    filial->produtos = get_Catalogo_Produtos(produtos, filial->produtos);
    filial->clientes = get_Catalogo_Clientes(clientes, filial->clientes);
    return filial;
}


Filial init_Filial() {
	Filial f = (Filial) malloc(sizeof(struct filial));
	return f;
}


Filial adiciona_Venda_Filial(Filial f, Venda v) {
	
	char* prod = malloc(8*sizeof(char));
	prod = getNomeProduto(getProduto(v),prod);
	char* cli = malloc(7*sizeof(char));
	cli = getNomeCliente(getCliente(v),cli);
	int quant = getQuantidade(v);
	char promocao = getPromocao(v);
	int promo = (promocao == 'N') ? NORMAL : PROMOCAO;
	int mes = getMes(v) - 1;
	double price = getPreco(v);
	double faturado = quant * price;
	
	/* INFO DOS PRODUTOS */
	
	Nodo_Produtos nodo_p = getEstrutura_Catalogo(f->produtos,prod);
	
	if(!nodo_p) {
		nodo_p = init_Nodo_Produtos();
	}	
	
	nodo_p->quantidade += quant;

	if(promo == NORMAL && (existe_Conj_Filiais(nodo_p->clientes_N,cli) == false)) nodo_p->clientes_N = adiciona_Nome(nodo_p->clientes_N,cli);
	else if(existe_Conj_Filiais(nodo_p->clientes_P,cli) == false) nodo_p->clientes_P = adiciona_Nome(nodo_p->clientes_P,cli);
		
	f->produtos = atualiza_Catalogo(f->produtos,prod,nodo_p);
	

	/* INFO DOS CLIENTES */
	
	Nodo_Clientes nodo_c = getEstrutura_Catalogo(f->clientes,cli);

	if(!nodo_c) {
		nodo_c = init_Nodo_Clientes();
	}

	nodo_c->total_quantidades[mes] += quant;
	
	Lista_Produtos prod_c = avl_getEstrutura(nodo_c->meses_produtos[mes],prod);

	if(!prod_c) {
		prod_c = init_Lista_Produtos();
		prod_c->produto = malloc((strlen(prod)+1)*sizeof(char));
		strcpy(prod_c->produto,prod);
	}

	prod_c->faturacao += faturado;
	prod_c->quantidade += quant;

	nodo_c->meses_produtos[mes] = avl_insert(nodo_c->meses_produtos[mes],prod,prod_c);

	f->clientes = atualiza_Catalogo(f->clientes,cli,nodo_c);

	free(prod);
	free(cli);

	return f;
}


void free_Filial(Filial f) {
	remove_Catalogo(f->clientes,free_Nodo_Clientes);
	remove_Catalogo(f->produtos,free_Nodo_Produtos);
	free(f);
}

Boolean verifica_cliente_comprado(Filial f, char* c) {
	Nodo_Clientes n = getEstrutura_Catalogo(f->clientes,c);
	if(n) return true;
	else return false;
}


Boolean filial_existe_Cliente(Filial f, char* cliente) {
	return existe_Catalogo(f->clientes,cliente);
}


Boolean filial_existe_Produto(Filial f,char* produto) {
	return existe_Catalogo(f->produtos,produto);
}


static Nodo_Produtos init_Nodo_Produtos() {
	
	Nodo_Produtos produto = (Nodo_Produtos) malloc(sizeof(struct nodo_produtos));
	
	produto->quantidade = 0;
	produto->clientes_N = init_Conj_Filiais(10);
	produto->clientes_P = init_Conj_Filiais(10);

	return produto;
}


static void free_Nodo_Produtos(void* n) {
	Nodo_Produtos x = (Nodo_Produtos) n;
	free_Conj_Filiais(x->clientes_P);
	free_Conj_Filiais(x->clientes_N);
	free(x);
}


int getQuantidadeProduto(Filial f, char* produto) {
	Nodo_Produtos nodo_p = getEstrutura_Catalogo(f->produtos,produto);
	if(nodo_p != NULL) return nodo_p->quantidade;
	return 0;
}


int nr_clientes_de_um_produto(Filial f, char* produto) {
	int nr_clientes = 0;
	Nodo_Produtos nodo_p = getEstrutura_Catalogo(f->produtos,produto);
	if(nodo_p != NULL) {
		nr_clientes = filiais_nr_elementos_diferentes(nodo_p->clientes_N,nodo_p->clientes_P);
	}
	return nr_clientes;
}


static Nodo_Clientes init_Nodo_Clientes() {
	int i;
	Nodo_Clientes cliente = (Nodo_Clientes) malloc(sizeof(struct nodo_clientes));
	for(i = 0; i < 12; i++) {
		cliente->meses_produtos[i] = initAVL();
		cliente->total_quantidades[i] = 0;
	}
	return cliente;
}


static void free_Nodo_Clientes(void * x) {
	Nodo_Clientes n = (Nodo_Clientes) x;
	int i;
	for(i = 0; i < 12; i++) {
		avl_free(n->meses_produtos[i],free_Lista_Produtos);
	}
	free(n);
}


static Lista_Produtos init_Lista_Produtos() {
	Lista_Produtos l = (Lista_Produtos) malloc(sizeof(struct lista_produtos));
	l->quantidade = 0;
	l->faturacao = 0;
	return l;
}


static void free_Lista_Produtos(void* n) {
	Lista_Produtos l = (Lista_Produtos) n;
	free(l->produto);
	free(l);
}


Conj_Filiais init_Conj_Filiais(int n) {
	Conj_Filiais c = (Conj_Filiais) malloc(sizeof(struct conjunto_filiais));
	c->lista = init_Array(n);
	return c;
}


Conj_Filiais adiciona_Nome(Conj_Filiais c, char* nome) {
	c->lista = adiciona_array(c->lista,nome);
	return c;
}


void free_Conj_Filiais(Conj_Filiais c) {
	free_Array(c->lista);
	free(c);
}


Lista get_Lista_Filial(Conj_Filiais c) {
	return get_Lista_Array(c->lista);
}


int filial_getPos(Conj_Filiais conjunto) {
	return catalogo_getPos(conjunto->lista);
}


char* filial_get_elemento_lista(Conj_Filiais conjunto, int pos) {
	return catalogo_getElemento(conjunto->lista,pos);
}


int filiais_nr_elementos_diferentes(Conj_Filiais a, Conj_Filiais b) {
	return catalogo_nr_elementos_diferentes(a->lista,b->lista);
}


static Boolean existe_Conj_Filiais(Conj_Filiais c, char* valor) {
	return existe_Array(c->lista,valor);
}


HEAP init_HEAP() {
	HEAP h = (HEAP) malloc(sizeof(struct heap_filial));
	h->heap = initHeap();
	return h;
}


void free_HEAP(HEAP h) {
	heap_free(h->heap);
	free(h);
}


HEAP lista_codigos_de_clientes(Filial f, HEAP h, char* cliente, int mes, char ordenacao) {
	
	Nodo_Clientes nodo_c = getEstrutura_Catalogo(f->clientes,cliente);
	if(nodo_c) {
		h = converte_Heap_clientes(h,nodo_c->meses_produtos[mes-1],ordenacao);
	}
	return h;
}


static HEAP converte_Heap_clientes(HEAP h, AVL a, char ordenacao) {
	h = converte_Heap_clientes_aux(h,getNodo(a),ordenacao);
	return h;
}


static HEAP converte_Heap_clientes_aux(HEAP h, NODO n, char ordenacao) {
	if(n) {
		h = converte_Heap_clientes_aux(h,getNodoEsq(n),ordenacao);
		char* p = getString(n);
		Lista_Produtos prod_c = getCont(n);
		if(!prod_c) {
			h->heap = heap_push(h->heap,p,0,0,1,ordenacao);
		} else {
			h->heap = heap_push(h->heap,p,prod_c->quantidade,prod_c->faturacao,1,ordenacao);
		}
		h = converte_Heap_clientes_aux(h,getNodoDir(n),ordenacao);
	}
	return h;
}


HEAP top3_clientes(Filial f, HEAP h, char* cliente, char ordenacao) {
	int i;
	Nodo_Clientes nodo_c = getEstrutura_Catalogo(f->clientes,cliente);
	if(nodo_c) {
		for(i = 0; i < NR_MESES; i++) {
			h = converte_Heap_clientes(h,nodo_c->meses_produtos[i],ordenacao);
		}
	}
	return h;
}


Conj_Filiais lista_top3(Conj_Filiais c, HEAP h, char ordenacao) {
	int i = 0, j = 0;
	char* prod;
	while(i < 3 && j < heap_count(h->heap)) {
		prod = heap_pop(h->heap,ordenacao);
		c = adiciona_Nome(c,prod);
		i++;
	}
	return c;
}


Conj_Filiais convert_Heap_Lista(Conj_Filiais c, HEAP h, char ordenacao) {
	int i = 0;
	char* prod;
	while(i < heap_count(h->heap)) {
		prod = heap_pop(h->heap,ordenacao);
		c = adiciona_Nome(c,prod);
	}
	return c;
}


HEAP heap_produtos_mais_vendidos(Filial f, HEAP h) {
	int i;
	AVL aux;
	
	for(i = 0; i < NR_LETRAS; i++) {
		aux = catalogo_getAVL(f->produtos,i);
		h = converte_Heap_produto(h,aux);
	}
	return h;
}


static HEAP converte_Heap_produto(HEAP h, AVL a) {
	h = converte_Heap_produtos_aux(h,getNodo(a));
	return h;
}


static HEAP converte_Heap_produtos_aux(HEAP h, NODO n) {
	if(n) {
		h = converte_Heap_produtos_aux(h,getNodoEsq(n));
		char* p = getString(n);
		Nodo_Produtos prod_c = getCont(n);
		if(prod_c) {
			h->heap = heap_push(h->heap,p,prod_c->quantidade,0,0,'Q');
		}
		else{
			h->heap = heap_push(h->heap,p,0,0,0,'Q');
		}
		h = converte_Heap_produtos_aux(h,getNodoDir(n));
	}
	return h;
}


Conj_Filiais retira_N_Produtos(Conj_Filiais c, HEAP h, int n) {
	int i = 0;
	char* prod;
	while(i < n) {
		prod = heap_pop(h->heap,'Q');
		c = adiciona_Nome(c,prod);
		i++;
	}
	return c;
}


Conj_Filiais lista_clientes_compraram_filial(Conj_Filiais c, Filial f) {
	c->lista = catalogo_clientes_compraram_filial(c->lista, f->clientes);
	return c;
}


Conj_Filiais lista_clientes_de_produto(Filial f, char* produto, char promo) {
	Nodo_Produtos nodo_p = getEstrutura_Catalogo(f->produtos,produto);
	if(!nodo_p) return NULL;
	else {
		if(promo == 'N') return nodo_p->clientes_N;
		else return nodo_p->clientes_P;
	}
}


int nr_total_unidades_compradas(Filial f, char* cliente, int mes) {

	Nodo_Clientes nodo_c = getEstrutura_Catalogo(f->clientes,cliente);

	if(!nodo_c) {
		return 0;
	}
	else {
		return nodo_c->total_quantidades[mes-1];
	}
}


Conj_Filiais converte_total_clientes(Conj_Filiais c, Filial f) {
	c->lista = catalogo_lista_total(c->lista,f->clientes);
	return c;
}


int heap_tamanho(HEAP h) {
	return heap_count(h->heap);
}