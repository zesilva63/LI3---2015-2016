/**
 * @file queries.h
 * @brief Ficheiro que contem a API relativa á implementação das Queries.
 */

#ifndef _queries_h_
#define _queries_h_

#include "global.h"
#include "avl.h"
#include "heap.h"
#include "produtos.h"
#include "clientes.h"
#include "faturacao.h"
#include "filial.h"
#include "array_dinamico.h"

/**
 * Ler os 3 ficheiros (Produtos, Clientes e Vendas), cujos nomes poderão ser introduzidos pelo utilizador ou, opcionalmente, assumidos por omissão. 
 * @param Cat_Produtos produtos.
 * @param Cat_Clientes clientes.
 * @param Faturacao faturas.
 * @param Filiais filiais.
 * @param int modo.
*/
int querie_1(Cat_Produtos produtos, Cat_Clientes clientes, Faturacao faturas, Filial filiais[], int modo);

/**
 * Determina a lista e o total de produtos cujo código se inicia por uma dada letra.
 * @param Cat_Produtos produtos.
 * @return int. 
*/
int querie_2(Cat_Produtos produtos);

/**
 * Dado um mês e um código de produto, apresentar o número total de vendas e o total facturado com esse produto em tal mês. 
 * @param Faturacao faturas.
 * @return int.
 */
int querie_3(Faturacao faturas);

/*
 * Determina a lista ordenada dos códigos dos produtos que ninguém comprou. 
 * @param Faturacao faturas.
 * @return int.
*/
int querie_4(Faturacao faturas);

/**
 * Dado um código de cliente, criar uma tabela com o numero total de produtos comprados mês a mês 
 * @param Filiais filial
 * @return int
*/
int querie_5(Filial filiais[]);

/**
 * Dado um intervalo fechado de meses, determinar o total de vendas registadas nesse intervalo e o total facturado.
 * @param Faturacao faturas.
 * @return int.
*/
int querie_6(Faturacao faturas);

/**
 * Determinar a lista ordenada de códigos de clientes que realizaram compras em todas as filiais.
 * @param Filiais filial.
 * @return int.
*/
int querie_7(Filial filiais[]);

/**
 * Dado um código de produto e uma filial, determinar os códigos, distinguindo entre compra N e compra P.
 * @param Filiais filial.
 * @return int.
*/
int querie_8(Filial filiais[]);

/**
 * Dado um código de cliente e um mês, determinar a lista de códigos de produtos que mais comprou.
 * @param Filiais filial.
 * @return int.
*/
int querie_9(Filial filiais[]);

/**
 *Cria uma lista dos N produtos mais vendidos em todo o ano.
 * @param Filiais filial.
 * @return int.
*/
int querie_10(Filial filiais[]);

/**
 * Dado um código de cliente determinar quais os códigos dos 3 produtos em que tenho gasto mais.
 * @param Filiais filial
 * @return int
*/
int querie_11(Filial filiais[]);

/**
 * Determina o número de clientes registados que não realizaram compras bem como o número de produtos que ninguém comprou.
 * @param Filiais filial.
 * @param Faturacao faturas.
 * @return int.
*/
int querie_12(Filial filiais[], Faturacao faturas);

/**
 * Apresentação de uma página.
 * @param p Pagina a apresentar
 * @return int com a proxima acção.
*/
void apresenta_Pagina(Pagina p);

#endif /* _queries_h_ */