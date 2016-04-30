#include "./headers/produtos.h"

#include <string.h>
#include <stdlib.h>


struct produto {
  char* prod;
};


struct catalogo_produtos{
  Catalogo catalogo;
};


struct conjunto_produtos {
  Array lista;
};


Cat_Produtos init_cat_produtos() {
  Cat_Produtos catalog = malloc(sizeof(struct catalogo_produtos));
  catalog->catalogo = init_Catalogo();
  return catalog;
}


Produto criaProduto() {
	Produto product = malloc(sizeof(struct produto));
  product->prod = NULL;
  return product;
}


Produto altera_Produto(Produto p, char* nome) {
  if(p->prod) {
    free(p->prod);
  }
    p->prod = malloc((strlen(nome)+1)*sizeof(char));
    strcpy(p->prod,nome);
  return p;
}


char* getNomeProduto(Produto product, char* novo) {
  strcpy(novo,product->prod);
  return novo;
}


void free_produto(Produto product) {
  free(product->prod);
  free(product);
}


Boolean existe_Produto(Cat_Produtos products, Produto product) {
  return existe_Catalogo(products->catalogo,product->prod);
}


Cat_Produtos insere_produto(Cat_Produtos products, Produto product) {
  products->catalogo = insere_Catalogo(products->catalogo,product->prod,NULL);
  return products;
}


int total_Produtos(Cat_Produtos products) {
  return total_elems_Catalogo(products->catalogo);
}


int total_Produtos_letra(Cat_Produtos products, char letra) {
  return total_elems_letra(products->catalogo,letra);
}


void remove_Catalogo_Produtos(Cat_Produtos products) {
  remove_Catalogo(products->catalogo,NULL);
  free(products);
}


Catalogo get_Catalogo_Produtos(Cat_Produtos products, Catalogo catalogo) {
  catalogo = clone_Catalogo(products->catalogo,catalogo);
  return catalogo;
}


Conj_Produtos init_Conjunto(int capacidade) {
  Conj_Produtos conjunto = (Conj_Produtos) malloc(sizeof(struct conjunto_produtos));
  conjunto->lista = init_Array(capacidade);
  return conjunto;
}


Conj_Produtos converte_Produtos(Conj_Produtos conjunto, Cat_Produtos products, char letra) {
  conjunto->lista = lista_catalogo_letra(conjunto->lista,products->catalogo,letra);
  return conjunto;
}


void free_Conj_Produtos(Conj_Produtos c) {
  free_Array(c->lista);
  free(c);
}


Lista get_Lista_Produtos(Conj_Produtos conjunto) {
  return get_Lista_Array(conjunto->lista);
}