/** 
 * @file avl.h
 * @brief Ficheiro que contem a API relativa á implementação de AVL's.
 */

#ifndef _avl_h_
#define _avl_h_

#include "global.h"


typedef struct avl* AVL;
typedef struct nodeAVL *NODO;

typedef void* Estrutura;
typedef char* Valor;

typedef void(*Funcao)(void*);


/**
 * Inicia uma nova AVL.
 * @return Nova AVL nula
 */
AVL initAVL();

/**
 * Insere na arvore tree tendo como referência de posicionamento um char*.
 * @param tree AVL onde insere.
 * @param key char* a inserir.
 * @param estrutura Conteúdo/Estrutura a inserir.
 * @return AVL com o novo nodo adicionado.
 */
AVL avl_insert(AVL arvore, Valor key, Estrutura estrutura);

/**
 * Executa um clone de uma dada AVL.
 * @param node AVL a clonar.
 * @param novo AVL onde colocar o clone.
 * @return AVL nova, clonada da anterior.
 */
AVL avl_clone(AVL node, AVL novo);

/**
 * Insere uma nova estrutura na arvore tree tendo como referência de posicionamento um char* value.
 * @param tree AVL onde insere.
 * @param value char* a inserir.
 * @param estrutura Conteúdo/Estrutura a inserir.
 * @return AVL atualizada.
 */
AVL atualiza_avl(AVL tree, Valor value, Estrutura estrutura);

/**
 * Devolve um Boolean referente a ter encontrado ou não na AVL o Valor value.
 * @param tree AVL onde é efectuada a procura.
 * @param value valor a procurar na AVL.
 * @return Boolean com o resultado.
 */
Boolean avl_lookUp(AVL tree, Valor value);

/**
 * Devolve o tamanho (quantidade de nodos) de uma AVL passada como argumento.
 * @param tree AVL da qual se pretende o tamanho.
 * @return Int com tamanho da AVL.
 */
int avl_count(AVL tree);

/**
 * Função com o objetivo de limpar da memória uma dada AVL.
 * @param nodo AVL a limpar da memória.
 * @param f Funcao que liberta a memória da estrutura associada.
 */
void avl_free(AVL node, Funcao f);

/**
 * Devolve a estrutura associada a um nodo de uma AVL passada como argumento.
 * @param node AVL de onde será devolvida a estrutura.
 * @param value char* indicando o nodo a procurar onde estará a estrutura associada.
 * @return void* com apontador para a estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura avl_getEstrutura(AVL node, Valor value);

/**
 * Função que dada uma AVL retorna o nodo da sua raiz.
 * @param a AVL de onde se pretende o nodo.
 * @return NODO.
 */
NODO getNodo(AVL a);

/**
 * Função que dado um NODO retorna o nodo á sua esquerda.
 * @param n NODO.
 * @return NODO à esquerda.
 */
NODO getNodoEsq(NODO n);

/**
 * Função que dado um NODO retorna o nodo á sua direita.
 * @param n NODO.
 * @return NODO à direita.
 */
NODO getNodoDir(NODO n);

/**
 * Função que dado um NODO retorna uma copia da sua string.
 * @param n NODO.
 * @return char* com a cópia.
 */
char* getString(NODO n);

/**
 * Função que dado um NODO retorna o seu contéudo.
 * @param n NODO.
 * @return void*.
 */
void* getCont(NODO n);

/**
 * Limpa da memória um dado NODO.
 * @param node NODO a remover.
 */
void free_Nodo(NODO node);

#endif /* _avl_h_ */