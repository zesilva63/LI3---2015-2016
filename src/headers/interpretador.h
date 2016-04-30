/**
 * @file interpretador.h
 * @brief Ficheiro que contem a API relativa á implementação do interpretador.
 */

#ifndef _interpretador_h_
#define _interpretador_h_

#include "produtos.h"
#include "clientes.h"
#include "faturacao.h"
#include "filial.h"
#include "global.h"


/**
 * Função encarregue de imprimir o menu de interação principal com o utilizador e executar a sua opção.
 * @param Cat_Protudos produtos.
 * @param Cat_Clientes clientes.
 * @param Faturacao faturas.
 * @param Filiais filiais.
 * @param int estado.
 * @return int.
 */
int menu_principal(Cat_Produtos produtos, Cat_Clientes clientes, Faturacao faturas, Filial filiais[], int estado);

#endif /* _interpretador_h_ */