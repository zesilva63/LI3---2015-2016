/**
 * @file leituras.h
 * @brief Ficheiro que contem a API relativa á implementação das leituras.
 */

#ifndef _leituras_h_
#define _leituras_h_

#include <stdio.h>
#include "produtos.h"
#include "clientes.h"
#include "venda.h"
#include "catalogo.h"
#include "faturacao.h"
#include "filial.h"
#include "global.h"

/**
 * Recebe as estruturas inicializadas e os ficheiros ja abertos e copia a informação dos ficheiros para as estruturas.
 * @param Cat_Clientes costumers.
 * @param Cat_Produtos products.
 * @param Faturacao contas.
 * @param Filiais filiais.
 * @param FILE *f_clients.
 * @param FILE *f_prods.
 * @param FILE* f_sales. 
 * @param char* f_cname.
 * @param char* f_pname.
 * @param char* f_vname
 * @param int estado.
 */
void leitura_ficheiros(Cat_Clientes costumers, Cat_Produtos products, Faturacao contas, Filial filiais[], FILE *f_clients, FILE *f_prods, FILE* f_sales, char* f_cname, char* f_pname, char* f_vname);

#endif /* _leituras_h_ */
