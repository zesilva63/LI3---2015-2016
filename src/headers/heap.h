/**
 * @file heap.h
 * @brief Ficheiro que contem a API relativa á implementação de Max Heap's.
 */

#ifndef _heap_h_
#define _heap_h_

#include "global.h"

typedef struct heap *Heap;


/**
 * Inicia uma nova AVL.
 * @return Nova AVL nula
 */
Heap initHeap();

/**
 * Insere na Heap tendo como referência a quantidade de um produto.
 * @param heap Heap onde insere.
 * @param produto char *.
 * @param quantidade int.
 * @param custo float.
 * @param modo int com opcao de verificação de existencia ou não.
 * @param ordenacao determina se a heap se ordena por quantidade ou por custo.
 * @return Heap com o novo membro adicionado.
 */
Heap heap_push(Heap heap,char *produto,int quantidade, float custo, int modo, char ordenacao);

/**
 * Devolve o produto com maior quantidade.
 * @param heap Heap com todos os produtos.
 * @param ordenacao determina se a heap se ordena por quantidade ou por custo.
 * @return char * com o nome do produto.
 */
char *heap_pop(Heap heap, char ordenacao);

/**
 * Devolve o tamanho (quantidade de elementos) de uma Heap passada como argumento.
 * @param heap Heap da qual se pretende o tamanho.
 * @return Int com numero de elementos da Heap.
 */
int heap_count(Heap heap);

/**
 * Função com o objetivo de limpar da memória uma dada Heap.
 * @param Heap a limpar da memória.
 */
void heap_free(Heap heap);


#endif /* _heap_h_ */