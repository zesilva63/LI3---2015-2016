/**
 * @file clientes.h
 * @brief Ficheiro que contem a API relativa á implementação dos Clientes.
 */

#ifndef _clientes_h_
#define _clientes_h_

#include "catalogo.h"
#include "global.h"

typedef struct catalogo_clientes *Cat_Clientes;
typedef struct cliente *Cliente;


/**
 * Inicia um novo catálogo de clientes.
 * @return Cat_Clientes Novo catálogo de clientes alocado.
 */
Cat_Clientes init_cat_clientes();

/**
 * Insere no catálogo de clientes um novo cliente.
 * @param clients Cat_Clientes onde se pretende inserir.
 * @param client Cliente a inserir no catálogo.
 * @return Cat_Clientes catálogo de clientes com o novo cliente inserido.
 */
Cat_Clientes insere_Cliente(Cat_Clientes clients, Cliente client);

/**
 * Devolve um Boolean referente a ter encontrado ou não no catálogo de clientes o cliente pretendido.
 * @param clients Cat_Clientes onde é efectuada a procura.
 * @param client Cliente a procurar.
 * @return Boolean com o resultado.
 */
Boolean existe_Cliente(Cat_Clientes clients, Cliente client);

/**
 * Devolve o número de clientes que um catálogo de clientes contem.
 * @param clients Cat_Clientes da qual se pretende o número de elementos.
 * @return Int com numero de elementos.
 */
int total_Clientes(Cat_Clientes clients);

/**
 * Devolve o número de clientes que um catálogo de clientes contem cujo nome começa por uma dada letra.
 * @param clients Cat_Clientes da qual se pretende o número de elementos.
 * @param letra char que representa a letra a procurar.
 * @return Int com numero de clientes começados pela dada letra.
 */
int total_Clientes_letra(Cat_Clientes clients, char letra);

/**
 * Devolve um clone do catalogo inserido na estrutura do catálogo de clientes.
 * @param clients Cat_Clientes da qual se pretende o catálogo.
 * @return Catalogo.
 */
Catalogo get_Catalogo_Clientes(Cat_Clientes clientes, Catalogo novo);

/**
 * Função com o objetivo de limpar da memória um catálogo de clientes.
 * @param clients Cat_Clientes a limpar da memória.
 */
void remove_Catalogo_Clientes(Cat_Clientes clients);

/**
 * Inicia um novo cliente.
 * @param cliente char* com o nome do cliente.
 * @return Cliente novo cliente criado.
 */
Cliente criaCliente();

/**
 * Dado um cliente altera o nome do mesmo.
 * @param c Cliente a alterar.
 * @param novo char* com o novo nome;
 */
Cliente altera_Cliente(Cliente c, char* novo);

/**
 * Função que devolve o nome de um cliente.
 * @param client Cliente a consultar o nome.
 * @param novo char* onde colocar a copia do nome do cliente.
 * @return char* com uma copia do nome do cliente.
 */
char* getNomeCliente(Cliente client, char* novo);

/**
 * Função com o objetivo de limpar da memória um cliente.
 * @param client Cliente a limpar da memória.
 */
void free_cliente(Cliente client);

#endif /* _clientes_h_ */