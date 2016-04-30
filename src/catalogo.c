#include "./headers/catalogo.h"

#include <stdlib.h>


struct catalogo {
   AVL indice[NR_LETRAS];
};


struct array_catalogo {
  Lista list;
};


Catalogo init_Catalogo() {
  int i;
  Catalogo cat = malloc(sizeof(struct catalogo));
  for(i = 0; i < NR_LETRAS; i++) {
      cat->indice[i] = initAVL();
  }
  return cat;
}


Boolean existe_Catalogo(Catalogo catalogo, char* key) {
   int index = key[0] - 'A';
  if(index >= 0 && index < 26) {
    Boolean existe = avl_lookUp(catalogo->indice[index],key);
    return existe;
  }
  else return false;
}


Catalogo insere_Catalogo(Catalogo catalogo, char* key, void* estrutura) {
    int index = key[0] - 'A';
    catalogo->indice[index] = avl_insert(catalogo->indice[index], key, estrutura);
    return catalogo;
}


Catalogo atualiza_Catalogo(Catalogo catalogo, char* key, void* estrutura) {
  int index = key[0] - 'A';
    catalogo->indice[index] = atualiza_avl(catalogo->indice[index], key, estrutura);
    
    return catalogo;
}


int total_elems_Catalogo(Catalogo catalogo) {
  
  int i, total = 0;
  
  for(i = 0; i < NR_LETRAS; i++) {
    total += avl_count(catalogo->indice[i]);
  }
  
  return total;
}


int total_elems_letra(Catalogo catalogo, char letra) {
  
  int total = 0;
  int index = letra - 'A';
   
  total += avl_count(catalogo->indice[index]);

  return total;
}


Catalogo clone_Catalogo(Catalogo catalogo, Catalogo novo) {
  int i;  
  novo = (Catalogo) malloc(sizeof(struct catalogo));
  for(i = 0; i < NR_LETRAS; i++) {
    novo->indice[i] = avl_clone(catalogo->indice[i],novo->indice[i]);
  }
  return novo;
}


void* getEstrutura_Catalogo(Catalogo catalogo, char* key) {
  int index = key[0] - 'A';
  return avl_getEstrutura(catalogo->indice[index],key);
}


AVL catalogo_getAVL(Catalogo catalogo, int index) {
  return catalogo->indice[index];
}


void remove_Catalogo(Catalogo catalogo, Funcao f) {
  int i;

  for(i = 0; i < NR_LETRAS; i++) {
    avl_free(catalogo->indice[i],f);
  }
  free(catalogo);
}


Array init_Array(int capacidade) {
    
    Array lista = (Array) malloc(sizeof(struct array_catalogo));
    lista->list = init_Lista(capacidade);
    
    return lista;
}


Array lista_catalogo_letra(Array lista,Catalogo catalogo, char letra) {
  
  int index = letra - 'A';
  lista->list = lista_converte(lista->list,catalogo->indice[index]);
  
  return lista;
}


Array adiciona_array(Array lista,char* info) {
  
  lista->list = lista_insert(lista->list,info);
  
  return lista;
}


void free_Array(Array lista) {
  free_Lista(lista->list);
  free(lista);
}

Array catalogo_produtos_nao_comprados_totais(Array lista, Catalogo catalogo) {
  int i;
  
  for(i = 0; i < NR_LETRAS; i++) {
    lista->list = produtos_nao_comprados_totais(lista->list,catalogo->indice[i]);
  }
  
  return lista;
}


Lista get_Lista_Array(Array lista) {
  return lista->list;
}


Array catalogo_lista_total(Array lista,Catalogo catalogo) {
  int i;
  for(i = 0; i < 26; i++) {
    lista->list = lista_converte(lista->list,catalogo->indice[i]);
  }
  return lista;
}


char* catalogo_getElemento(Array lista, int pos) {
  return lista_getNome(lista->list,pos);
}


int catalogo_getPos(Array lista) {
  return lista_getPos(lista->list);
}


Boolean existe_Array(Array lista, char* valor) {
  return existe_Lista(lista->list,valor);
}


Array catalogo_clientes_compraram_filial(Array lista, Catalogo catalogo) {
  int i;
  
  for(i = 0; i < NR_LETRAS; i++) {
    lista->list = clientes_compraram_filial(lista->list,catalogo->indice[i]);
  }
  
  return lista;
}


int catalogo_nr_elementos_diferentes(Array a, Array b) {
  return lista_nr_elementos_diferentes(a->list,b->list);
}