/**
 * @file venda.h
 * @brief Ficheiro que contem a API relativa á implementação de uma Venda.
 */

#ifndef _venda_h_
#define _venda_h_

#include "clientes.h"
#include "produtos.h"
#include "global.h"

typedef struct venda *Venda;


/**
 * Inicializa a estrutura venda.
 * @return Venda.
 */
Venda initVenda();

/**
 * Remove da memória uma dada estrutura Venda.
 * @param v Venda a limpar.
 */
void free_Venda(Venda v);

/**
 * Atualiza uma estrutura venda.
 * @param char* product.
 * @param double price.
 * @param int quantity.
 * @param char promotion.
 * @param char *client.
 * @param int month.
 * @param int shop
 * @return Venda.
 */
Venda change_sale(Venda sale, char* product, double price, int quantity, char promotion, char* client, int month, int shop);

/**
 * Devolve o produto de uma venda.
 * @param Venda sale
 * @return Produto.
 */
Produto getProduto (Venda sale);

/**
 * Devolve o cliente de uma venda.
 * @param Venda sale
 * @return Produto.
 */
Cliente getCliente (Venda sale);

/**
 * Devolve o mês em que uma venda foi efectuada.
 * @param Venda sale
 * @return int com o mês respetivo.
 */
int getMes(Venda sale);

/**
 * Devolve a filial onde foi efectuada uma venda.
 * @param Venda sale
 * @return int com a filial respetiva.
 */
int getFilial(Venda sale);

/**
 * Devolve a quantidade numa venda de um dado produto.
 * @param Venda sale.
 * @return int com o valor.
 */
int getQuantidade(Venda sale);

/**
 * Devolve se a venda foi efetuada em P(romoção) ou N(ormal).
 * @param Venda sale.
 * @return char referente ao tipo de venda.
 */
char getPromocao(Venda sale);

/**
 * Devolve o preço unitário do produto de uma venda.
 * @param Venda sale.
 * @return double com o preço unitário.
 */
double getPreco(Venda sale);

/**
 * Valida a compra verificando todos os seus componentes.
 * @param Cat_Produtos produtos.
 * @param Cat_Clientes clientes.
 * @param Venda venda.
 * @return Boolean com valor de verdade.
 */
Boolean validate_sale(Cat_Produtos produtos, Cat_Clientes clientes, Venda venda);

#endif /* _venda_h_ */