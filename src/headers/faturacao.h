/**
 * @file faturacao.h
 * @brief Ficheiro que contem a API relativa ao modulo da Faturação Total.
 */

#ifndef _faturacao_h_
#define _faturacao_h_

#include "global.h"
#include "catalogo.h"
#include "venda.h"
#include "produtos.h"


typedef struct faturacao *Faturacao;
typedef struct conjunto_faturas *Conj_Faturas;


/**
 * Inicia uma nova estrutura Faturação.
 * @return Nova estrutura Faturação.
 */
Faturacao init_Faturacao();

/**
 * Função responsável por clonar o catalogo de produtos por forma a termos a informação previamente ordenada dos mesmos na faturação.
 * @param fat Faturação a inserir os dados.
 * @param produtos Cat_Produtos do qual provêm os dados.
 * @return Faturação com os dados já inseridos.
 */
Faturacao cria_Dados_Faturacao(Faturacao fat, Cat_Produtos produtos);

/**
 * Função adiciona_Fatura tem a responsabilidade da inserção dos dados provenientes de uma Venda na estrutura.
 * @param contas Faturacao onde será inserida a informação relativa á Venda.
 * @param venda Venda da qual provẽm os dados a inserir na Faturação.
 * @return contas Faturação após a inserção dos dados.
 */
Faturacao adiciona_Fatura(Faturacao contas, Venda venda);

/**
 * Função com o objetivo de limpar da memória uma estrutura Faturação.
 * @param faturacao Estrutura da Faturação a limpar da memória.
 */
void free_Faturacao(Faturacao faturacao);

/**
 * Devolve a faturação total de um produto num dado mês e numa dada filial em promoção ou em preço normal.
 * @param Faturacao fatura onde estão alocados os dados.
 * @param char* produto pretendido.
 * @param int mes pretendido.
 * @param char modo, se Normal ou Promoção.
 * @param int filial pretendida.
 * @return double com o valor.
 */
double get_total_precos_mes_produto_filial(Faturacao fatura, char* produto, int mes, char modo, int filial);

/**
 * Devolve o numero de vendas total de um produto num dado mês e numa dada filial em promoção ou em preço normal.
 * @param Faturacao fatura onde estão alocados os dados.
 * @param char* produto pretendido.
 * @param int mes pretendido.
 * @param char modo, se Normal ou Promoção.
 * @param int filial pretendida.
 * @return int com o valor.
 */
int get_total_vendas_mes_produto_filial(Faturacao fatura, char* produto, int mes, char modo, int filial);

/**
 * Devolve o total faturado com um produto num dado mês em promoção ou em preço normal.
 * @param Faturacao fatura.
 * @param char* produto pretendido.
 * @param int mes pretendido.
 * @param char modo, se Normal ou em Promoção.
 * @return int com o valor.
 */
double get_total_precos_mes_produto(Faturacao fatura, char* produto, int mes, char modo);

/**
 * Devolve o total de vendas de um produto num dado mês em promoção ou em preço normal.
 * @param Faturacao fatura onde se encontram os dados alocados.
 * @param char* produto pretendido.
 * @param int mes pretendido.
 * @param char modo, se Normal ou em Promoção.
 * @return int com o valor.
 */
int get_total_vendas_mes_produto(Faturacao fatura, char* produto, int mes, char modo);

/**
 * Devolve o total faturado num intervalo de meses.
 * @param Faturacao fatura onde estão os dados alocados.
 * @param int mes1, referente ao mês inicial.
 * @param int mes2, referente ao mes final.
 * @return double com o valor.
 */
double get_total_faturado_intervalo(Faturacao fatura, int mes1, int mes2);

/**
 * Devolve o total de vendas de produtos num intervalo de meses.
 * @param Faturacao fatura onde estão alocados os dados.
 * @param int mes1, referente ao mês inicial.
 * @param int mes2, referente ao mês final.
 * @return int com o valor.
 */
int get_total_vendas_intervalo(Faturacao fatura, int mes1, int mes2);

/**
 * Inicializa um Conj_Faturas.
 * @param int capacidade do conjunto.
 * @return Conj_Faturas criado.
 */
Conj_Faturas init_Lista_Faturacao(int capacidade);

/**
 * Cria um Conj_Faturas com os produtos não comprados numa dada filial.
 * @param Conj_Faturas conjuto com os produtos.
 * @param Conj_Faturas nao_comprados onde serão colocados os produtos não comprados numa dada filial.
 * @param Faturacao faturas.
 * @param int filial da qual se pretendem os valores.
 * @return Conj_Faturas com os dados pedidos.
 */
Conj_Faturas faturas_nao_comprado_filial(Conj_Faturas conjunto, Conj_Faturas nao_comprados,  Faturacao faturas, int filial);

/**
 * Adiciona ao conjuto de faturas um produto.
 * @param conjunto Conj_Faturas onde será adicionado.
 * @param info char* a adicionar.
 * @return Conj_Faturas com o valor adicionado.
 */
Conj_Faturas adiciona_Conjunto(Conj_Faturas conjunto, char* info);

/**
 * Remove da memória um dado Conj_Faturas.
 * @param c Conj_Faturas a limpar da memória.
 */
void free_Conj_Faturas(Conj_Faturas c);

/**
 * Devolve o Conj_Faturas com os produtos nunca comprados.
 * @param conjuto Conj_Faturas.
 * @param faturacao Faturacao com os dados a consultar.
 * @return conjunto Conj_Faturas com os produtos nunca comprados.
 */
Conj_Faturas faturas_produtos_nao_comprados_totais(Conj_Faturas conjunto, Faturacao faturacao);

/**
 * Devolve a lista referente a um Conk_Faturas.
 * @param conjuto Conj_Faturas.
 * @return Lista.
 */
Lista apresenta_faturas(Conj_Faturas conjunto);

/**
 * Cria uma lista com todos os produtos da estrutura.
 * @param conjunto Conj_Faturas.
 * @param faturacao Faturacao.
 * @return Conj_Faturas com os elementos.
 */
Conj_Faturas cria_lista_total(Conj_Faturas conjunto, Faturacao faturacao);

/**
 * Devolve um produto de um Conj_Faturas dada uma posição.
 * @param conjunto Conj_Faturas.
 * @param int pos com a posição pretendida.
 * @return char* com o nome do produto.
 */
char* get_elemento_lista(Conj_Faturas conjunto, int pos);

/**
 * Devolve o tamanho de um Conj_Faturas.
 * @param conjuto Conj_Faturas.
 * @return int com o valor.
 */
int faturacao_getPos(Conj_Faturas conjunto);

#endif /* _faturacao_h_ */