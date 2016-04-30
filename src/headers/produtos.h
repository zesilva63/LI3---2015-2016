/**
 * @file produtos.h
 * @brief Ficheiro que contem a API relativa á implementação dos Produtos.
 */

#ifndef _produtos_h_
#define _produtos_h_

#include "catalogo.h"
#include "global.h"


typedef struct catalogo_produtos *Cat_Produtos;
typedef struct produto *Produto;
typedef struct conjunto_produtos *Conj_Produtos;


/**
 * Inicializa um catalogo de produtos.
 * @return Cat_Produtos.
 */
Cat_Produtos init_cat_produtos();

/**
 * Insere um produto no catalogo de produtos.
 * @param Cat_Produtos products.
 * @param Produto product.
 * @return Cat_Produtos.
 */
Cat_Produtos insere_produto(Cat_Produtos products, Produto prod);

/**
 * Retorna um clone do catalogo de produtos dentro da estrutura.
 * @param Cat_Produtos products.
 * @return Catalogo.
 */
Catalogo get_Catalogo_Produtos(Cat_Produtos products, Catalogo catalogo);

/**
 * Função que verifica se um dado produto existe no catalogo de produtos.
 * @param Cat_Produtos products.
 * @param Produto product.
 * @return Boolean com valor de verdade para a procura.
 */
Boolean existe_Produto(Cat_Produtos products, Produto product);

/**
 * Devolve o numero de produtos num catalogo.
 * @param Cat_Produtos products.
 * @return int com o valor.
 */
int total_Produtos(Cat_Produtos products);

/**
 * Devolve o número de produtos começados pela letra indicada.
 * @param Cat_Produtos products.
 * @param char letra.
 * @return int.
 */
int total_Produtos_letra(Cat_Produtos products, char letra);

/**
 * Liberta o espaço alocado em memoria pelo catalogo.
 * @param Cat_Produtos  products.
 */
void remove_Catalogo_Produtos(Cat_Produtos products);

/**
 * Aloca e retorna um novo Produto.
 * @return Produto.
 */
Produto criaProduto();

/**
 * Dado um Produto altera o nome do mesmo.
 * @param p Produto a alterar.
 * @param novo char* com o novo nome;
 */
Produto altera_Produto(Produto p, char* nome);

/**
 * Devolve uma cópia do código de um produto.
 * @param Produto product.
 * @param novo char* onde colocar a copia do nome do produto.
 * @return char* com a cópia do nome.
 */
char* getNomeProduto(Produto product, char* novo);

/**
 * Liberta o espaço alocado por um produto.
 * @param Produto product.
 */
void free_produto(Produto product);

/**
 * Inicializa um conjunto de produtos.
 * @param int capacidade.
 * @return Conj_Produtos.
 */
Conj_Produtos init_Conjunto(int capacidade);

/**
 * Converte elementos de um catalogo de produtos para um conjunto de produtos dada uma letra.
 * @param Conj_Produtos conjunto.
 * @param Cat_Produtos products.
 * @param char letra.
 * @return Conj_Produtos.
 */
Conj_Produtos converte_Produtos(Conj_Produtos lista, Cat_Produtos products, char letra);

/**
 * Remove da memória um dado Conj_Produtos.
 * @param c Conj_Produtos a limpar da memória.
 */
void free_Conj_Produtos(Conj_Produtos c);

/**
 * Retornar a lista com os produtos inseridos num Conj_Produtos.
 * @param Conj_Produtos conjunto.
 * @return Array.
 */
Lista get_Lista_Produtos(Conj_Produtos conjunto);

#endif /* _produtos_h_ */