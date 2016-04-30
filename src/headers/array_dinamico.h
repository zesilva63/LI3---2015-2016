/**
 * @file array_dinamico.h
 * @brief Ficheiro que contem a API relativa á implementação de um Array Dinâmico.
 */

#ifndef _array_dinamico_h_
#define _array_dinamico_h_

#include "avl.h"
#include "global.h"


typedef struct lista *Lista;
typedef struct pagina *Pagina;

/**
 * Inicia um novo array dinâmico.
 * @param size inteiro que determina a capacidade inicial do array dinâmico.
 * @return conjunto array dinâmico
 */
Lista init_Lista(int capacidade);

/**
 * Retorna uma lista resultante da conversão para lista de uma AVL dada.
 * @param list Lista (array dinâmico) onde serão inseridos os valores.
 * @param tree AVL de onde provêm os valores a colocar na Lista.
 * @return list.
 */
Lista lista_converte(Lista list, AVL tree);

/**
 * Adiciona um char* passado como argumento no array dinâmico.
 * @param conjunto Lista (array dinâmico) onde será inserido o valor pretendido.
 * @param valor char* a colocar na Lista.
 * @return conjunto array dinâmico após a inserção.
 */
Lista lista_insert(Lista conjunto ,char* valor);

/**
 * Retorna o campo Pos da estrutura Lista.
 * @param list Lista (array dinâmico).
 * @return int tamanho do array dinâmico.
 */
int lista_getPos(Lista list);

/**
 * Retorna o valor do array dinamico dada uma posição.
 * @param list Lista (array dinâmico).
 * @param pos posição de onde se pretende retirar o valor.
 * @return char* com o valor.
 */
char* lista_getNome(Lista list, int pos);

/**
 * Retorna um Boolean referente a um elemento se encontrar na lista ou não.
 * @param list Lista (array dinâmico).
 * @param valor char* a verificar a existência.
 * @return Boolean.
 */
Boolean existe_Lista(Lista list, char* valor);

/**
 * Remove da memória uma dada Lista.
 *@param list Lista a limpar da memória.
 */
void free_Lista(Lista list);

/**
 * Retorna uma Lista com os nomes dos produtos não comprados em nenhuma filial.
 * @param conjunto Lista (array dinâmico) a inserir valores.
 * @param tree AVL a procurar os valores.
 * @return conjunto array dinâmico após a inserção.
 */
Lista produtos_nao_comprados_totais(Lista list,AVL tree);

/**
 * Retorna uma Lista com os clientes que compraram numa filial.
 * @param list Lista a inserir os clientes.
 * @param tree AVL de onde são provenientes os dados.
 * @return Lista com os clientes.
 */
Lista clientes_compraram_filial(Lista list,AVL tree);

/**
 * Função responsável por retornar o numero de elementos diferentes entre duas listas.
 * @param a Lista a comparar.
 * @param b Lista a comparar com a primeira.
 * @return int com o valor.
 */
int lista_nr_elementos_diferentes(Lista a, Lista b);

/**
 * Inicia uma nova Pagina com um dado tamanho como parametro.
 * @param capacidade inteiro que determina o tamanho da página.
 * @return Pagina criada.
 */
Pagina init_Pagina(int capacidade);

/**
 * Insere dados numa página dada uma lista.
 * @param p Pagina onde serão inseridos os dados.
 * @param l Lista de onde serão provenientes os dados.
 * @param pagina int com a página pretendida.
 */
Pagina getPagina(Pagina p, Lista l, int pagina);

/**
 * Remove da memória uma dada Pagina.
 * @param p Pagina a limpar da memória.
 */
void free_Pagina(Pagina p);

/**
 * Retorna a string de uma dada posiçao de um Pagina.
 * @param p Pagina.
 * @param posicao int com a posição de onde se pretende a string.
 * @return char* com a string.
 */
char* getStringPagina(Pagina p, int posicao);

/**
 * Retorna o numero total de páginas que uma dada Pagina pode ter.
 * @param p Pagina.
 * @return int.
 */
int getNrPaginaTotal(Pagina p);

/**
 * Retorna o numero total de elementos possiveis que uma dada Pagina poderá mostrar.
 * @param p Pagina.
 * @return int.
 */
int getNrElementosTotal(Pagina p);

/**
 * Retorna o numero total de elementos que uma dada Pagina tem.
 * @param p Pagina.
 * @return int.
 */
int getNrElementosPag(Pagina p);

/**
 * Retorna o numero da página relativa aos dados que a Pagina contém.
 * @param p Pagina.
 * @return int.
 */
int getNrPagina(Pagina p);

/**
 * Insere um cabeçalho numa Lista.
 * @param l Lista.
 * @param titulo char* com o cabeçalho a colocar.
 * @return Lista com o cabeçalho inserido.
 */
Lista lista_insere_cabecalho(Lista l, char* titulo);

/**
 * Retorna o cabeçalho de uma página.
 * @param p Pagina.
 * @return char* com o cabeçalho.
 */
char* getCabecalho(Pagina p);

#endif /* _array_dinamico_h_ */