/**
 * @file catalogo.h
 * @brief Ficheiro que contem a API relativa á implementação de um Catálogo.
 */

#ifndef _catalogo_h_
#define _catalogo_h_

#include "global.h"
#include "avl.h"
#include "array_dinamico.h"

typedef struct catalogo *Catalogo;
typedef struct array_catalogo *Array;

/**
 * Inicializa uma estrutura Catálogo.
 * @return Catalogo inicializado.
 */
Catalogo init_Catalogo();

/**
 * Insere uma estrutura num Catálogo retornando o catalogo com a inserção.
 * @param Catalogo catálogo.
 * @param key char* a inserir.
 * @param estrutura void* estrutura a inserir no nodo.
 * @return Catalogo com valor inserido.
 */
Catalogo insere_Catalogo(Catalogo catalogo, char* key, void* estrutura);

/**
 * Cria um clone do Catálogo dado, devolvendo uma copia deste.
 * @param catalogo a clonar.
 * @param catalogo que conterá o clone.
 * @return Catalogo novo, clone do dado como argumento.
 */
Catalogo clone_Catalogo(Catalogo catalogo, Catalogo novo);

/**
 * Atualiza uma estrutura num Catálogo retornando o catalogo atualizado.
 * @param Catalogo catálogo.
 * @param key char* a indicar onde atualizar.
 * @param estrutura void* estrutura a inserir no nodo.
 * @return Catalogo atualizado.
 */
Catalogo atualiza_Catalogo(Catalogo catalogo, char* key, void* estrutura);

/**
 * Liberta o espaço alocado na memória pelo Catálogo.
 * @param catalogo Catálogo a libertar.
 * @param f Funcao responsavel por remover a estrutura associada.
 */
void remove_Catalogo(Catalogo catalogo, Funcao f);

/**
 * Verifica se um valor existe no Catálogo retornando verdadeiro se existir e false no caso contrário.
 * @param catalogo Catalogo onde procurar.
 * @param key char* a procurar.
 * @return Boolean com valor verdadeiro ou falso referente à procura.
 */
Boolean existe_Catalogo(Catalogo catalogo, char* key);

/**
 * Devolve o número de elementos do catálogo dado.
 * @param Catalogo catalogo.
 * @return int com o número de elementos.
 */
int total_elems_Catalogo(Catalogo catalogo);

/**
 * Devolve o número de elementos do catalogo começados pela letra dada.
 * @param catalogo Catalogo.
 * @param char letra.
 * @return int com o número de elementos da dada letra.
 */
int total_elems_letra(Catalogo catalogo, char letra);

/**
 * Devolve a estrutura associada a um elemento dada a sua key.
 * @param catalogo Catalogo a procurar.
 * @return void* com apontador para estrutura.
 */
void* getEstrutura_Catalogo(Catalogo catalogo, char* key);

/**
 * Devolve uma AVL do catálogo.
 * @param catalogo Catalogo.
 * @param int index da AVL.
 * @return AVL pedida.
 */
AVL catalogo_getAVL(Catalogo catalogo, int index);

/**
 * Inicializa um array com a capacidade indicada.
 * @param int capacidade pretendida para o Array.
 * @return Array criado.
 */
Array init_Array(int capacidade);


/**
 * Adiciona um elemento a uma Lista.
 * @param Array lista que irá receber os dados.
 * @param info char* com string a adicionar na Lista.
 * @return Array com o elemento adicionado.
 */
Array adiciona_array(Array lista, char* info);


/**
 * Remove da memória um dado Array.
 *@param list Lista a limpar da memória.
 */
void free_Array(Array lista);

/**
 * Converte os elementos de um Catalogo começados por uma dada letra numa lista.
 * @param Array lista que irá receber os dados.
 * @param Catalogo catalogo onde estão os dados.
 * @param char letra, letra que indicará ao catalogo que elementos irão ser convertidos para a lista.
 * @return Array com os elementos.
 */
Array lista_catalogo_letra(Array lista,Catalogo catalogo, char letra);


/**
 * Retorna um Array com os produtos não comprados nas 3 filiais.
 * @param lista Array onde serão colocados os dados.
 * @param catalogo Catalogo de onde provêm os dados.
 * @return Array com os dados pretendidos.
 */
Array catalogo_produtos_nao_comprados_totais(Array lista, Catalogo catalogo);

/**
 * Converte catalogo para lista todos os elementos de um catálogo.
 * @param lista Array onde serão colocados os dados.
 * @param catalogo Catalogo a converter.
 * @return Array com os elementos.
 */
Array catalogo_lista_total(Array lista,Catalogo catalogo);

/**
 * Função responsavel por retornar a Lista inserida num Array.
 * @param Array lista de onde está inserida a lista.
 * @return Lista.
 */
Lista get_Lista_Array(Array lista);

/**
 * Devolve um elemento de uma lista dada uma posição.
 * @param lista Array onde se encontram os elementos.
 * @param pos int com posição pretendida.
 * @return char* com o elemento.
 */
char* catalogo_getElemento(Array lista, int pos);

/**
 * Devolve o numero de posições atuais na alocadas na lista
 * @param Array lista.
 * @return int com o tamanho de um Array.
 */
int catalogo_getPos(Array lista);

/**
 * Retorna um Boolean referente a um elemento se encontrar no Array ou não.
 * @param lista Array.
 * @param valor char* a verificar a existência.
 * @return Boolean com o resultado.
 */
Boolean existe_Array(Array lista, char* valor);

/**
 * Converte em lista os elementos.
 * @param lista Array onde serão colocados os dados.
 * @param catalogo Catalogo a converter.
 * @return Array com os elementos.
 */
Array catalogo_clientes_compraram_filial(Array lista, Catalogo catalogo);

/**
 * Função responsável por retornar o número de elementos diferentes entre dois Arrays.
 * @param a Array a comparar.
 * @param b Array a comparar com o primeiro.
 * @return int com o valor.
 */
int catalogo_nr_elementos_diferentes(Array a, Array b);

#endif /* _catalogo_h_ */