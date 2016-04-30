#include "./headers/interpretador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int menu_leitura(Cat_Produtos produtos, Cat_Clientes clientes,Faturacao faturas,Filial filiais[]);
static int menu_catalogo(Cat_Produtos produtos);
static int menu_faturacao(Faturacao faturas);
static int menu_filiais(Filial filiais[], Faturacao faturas);

#define MENU_PRINCIPAL 1
#define SAIR_PROGRAMA 0
#define REFAZER_DADOS 2

/**
 * Função encarregue de imprimir o menu de interação principal com o utilizador e executar a sua primeira opção.
 * @param Cat_Protudos produtos.
 * @param Cat_Clientes clientes.
 * @param Faturacao faturas.
 * @param Filiais filiais.
 * @param int estado.
 * @return int.
 */
int menu_principal(Cat_Produtos produtos, Cat_Clientes clientes, Faturacao faturas, Filial filiais[3], int estado) {

	int input = 0;
	char opcao[20];
	
	if(estado == REFAZER_DADOS) {
		estado = menu_leitura(produtos,clientes,faturas,filiais);
	}

	while(estado) {
		system("clear");
		printf( "_______________________________________________\n" );
		printf( "\n\t\tMENU PRINCIPAL\n\n" );
		printf( "-----------------------------------------------\n" );
		printf(" Escolha uma das seguintes opções:\n\n" );
		printf("  1. Leitura de Ficheiros\n");
		printf("  2. Catálogo de Produtos\n");
		printf("  3. Faturação\n");
		printf("  4. Filiais\n");
		printf( "-----------------------------------------------\n" );
		printf( "\t\t\t\tQ - Sair\n" );
		printf( "_______________________________________________\n" );
		
		printf("\nEscolha uma opção >> ");
		
		input = scanf("%s",opcao);
		
		switch(opcao[0]) {
			
			case 'Q': estado = SAIR_PROGRAMA; break;
			
			case '1': if(!total_Produtos(produtos)) {
					  	estado = menu_leitura(produtos,clientes,faturas,filiais); break;
					  } else {
					  	printf(" Esta acção irá refazer os dados em memória, prima Q para cancelar >> ");
					  	input = scanf("%s",opcao);
					  	if(opcao[0] == 'Q') break;
					  	else {
					  		estado = REFAZER_DADOS;
					  		return estado;
					  	}
					  }
			case '2': if(total_Produtos(produtos)) estado = menu_catalogo(produtos);
					  else  {
					  	system("clear");
					  	printf("\n Ainda não foram lidos nenhuns dados!\n");
					  	printf("\n Prima qualquer tecla para voltar ao menu >> ");
						input = scanf("%s",opcao);			  	
					  }
					  break;
			case '3': if(total_Produtos(produtos)) estado = menu_faturacao(faturas);
					  else {
					  	system("clear");
					  	printf("\n Ainda não foram lidos nenhuns dados!\n");
					  	printf("\n Prima qualquer tecla para voltar ao menu >> ");
					  	input = scanf("%s",opcao);
					  }
					  break;
					  
			case '4': if(total_Produtos(produtos)) estado = menu_filiais(filiais,faturas);
					  else {
					  	system("clear");
					  	printf("\n Ainda não foram lidos nenhuns dados!\n");
					  	printf("\n Prima qualquer tecla para voltar ao menu >> ");
					  	input = scanf("%s",opcao);
					  }
					  break;

			default: break;
		}
	}
	return estado;
}


static int menu_leitura(Cat_Produtos produtos, Cat_Clientes clientes,Faturacao faturas,Filial filiais[3]) {

	int estado = 1, input = 0;
	char opcao[20];

	while(estado) {
	
		system("clear");
		printf("_______________________________________________\n");
		printf("\n\t\tMENU LEITURA\n\n");
		printf("-----------------------------------------------\n");
		printf(" Escolha uma das seguintes opções:\n\n");
		printf("  1. Carregar ficheiros para 1M\n");
		printf("  2. Carregar ficheiros para 3M\n");
		printf("  3. Carregar ficheiros para 5M\n");
		printf("  4. Introduzir ficheiros\n\n");
		printf("-----------------------------------------------\n");
		printf("  V - Voltar\t\t\tQ - Sair\n" );
		printf("_______________________________________________\n");
		
		printf("\nEscolha uma opção >> ");
		
		input = scanf("%s",opcao);
		
		switch(opcao[0]) {
			
			case 'Q': return SAIR_PROGRAMA; break;
			
			case '1': estado = querie_1(produtos,clientes,faturas,filiais,1);
					  return estado;
					  break;
			case '2': estado = querie_1(produtos,clientes,faturas,filiais,2);
					  return estado;
					  break;
			case '3': estado = querie_1(produtos,clientes,faturas,filiais,3);
					  return estado;
					  break;
			case '4': estado = querie_1(produtos,clientes,faturas,filiais,4);
					  return estado;
					  break;

			case 'V': return MENU_PRINCIPAL; break;

			default: break;
		}

	}
	return estado;
}



static int menu_catalogo(Cat_Produtos produtos) {

	int estado = 1, input = 0;
	char opcao[20];

	while(estado) {
	
		system("clear");
		printf("_______________________________________________\n");
		printf("\n\t\tMENU CATALOGOS\n\n");
		printf("-----------------------------------------------\n");
		printf(" Escolha uma das seguintes opções:\n\n");
		printf("  1. Listagem de Produtos por letra (2)\n\n");
		printf("-----------------------------------------------\n");
		printf("  V - Voltar\t\t\tQ - Sair\n" );
		printf("_______________________________________________\n");
		
		printf("\nEscolha uma opção >> ");
		
		input = scanf("%s",opcao);
		
		switch(opcao[0]) {
			
			case 'Q': return SAIR_PROGRAMA; break;
			
			case '1': estado = querie_2(produtos);
					  return MENU_PRINCIPAL;
					  break;
			
			case 'V': return MENU_PRINCIPAL; break;

			default: break;
		}

	}
	return estado;
}



static int menu_faturacao(Faturacao faturas) {

	int estado = 1, input = 0;
	char opcao[20];

	while(estado) {
	
		system("clear");
		printf("_______________________________________________\n");
		printf("\n\t\tMENU FATURACAO\n\n");
		printf("-----------------------------------------------\n");
		printf(" Escolha uma das seguintes opções:\n\n");
		printf("  1. Total de vendas/faturação dado um mês (3)\n");
		printf("  2. Produtos não comprados (4)\n");
		printf("  3. Vendas/faturação num intervalo de meses (6)\n\n");
		printf("-----------------------------------------------\n");
		printf("  V - Voltar\t\t\tQ - Sair\n");
		printf("_______________________________________________\n");
		
		printf("\nEscolha uma opção >> ");
		
		input = scanf("%s",opcao);
		
		switch(opcao[0]) {
			
			case 'Q': return SAIR_PROGRAMA; break;
			
			case '1': estado = querie_3(faturas);
					  return estado;
			          break;
			
			case '2': estado = querie_4(faturas);
					  return estado;
			          break;
			case '3': estado = querie_6(faturas);
					  return estado;
			          break;			
			case 'V': return MENU_PRINCIPAL; break;

			default: break;
		}
	}
	return estado;
}



static int menu_filiais(Filial filiais[3], Faturacao faturas) {

	int estado = 1, input = 0;
	char opcao[20];

	while(estado) {
	
		system("clear");
		printf("_______________________________________________\n");
		printf("\n\t\tMENU FILIAIS\n\n");
		printf("-----------------------------------------------\n");
		printf(" Escolha uma das seguintes opções:\n\n");
		printf("  1. Lista de produtos comprados mês a mês (5)\n");
		printf("  2. Lista de compradores em todas as filiais (7)\n");
		printf("  3. Compradores de um Produto por filial (8)\n");
		printf("  4. Produtos mais comprados de um Cliente (9)\n");
		printf("  5. Lista dos N Produtos mais vendidos (10)\n");
		printf("  6. Top 3 Produtos mais caros de um Cliente (11)\n");
		printf("  7. Clientes/Produtos sem registos de compra (12)\n\n");
		printf("-----------------------------------------------\n");
		printf("  V - Voltar\t\t\tQ - Sair\n");
		printf("_______________________________________________\n");
		
		printf("\nEscolha uma opção >> ");
		
		input = scanf("%s",opcao);
		
		switch(opcao[0]) {
			
			case 'Q': return SAIR_PROGRAMA; break;

			case '1': estado =querie_5(filiais);
			          return estado;
			          break;
			case '2': estado = querie_7(filiais);
					  return estado;
			          break;

			case '3': estado = querie_8(filiais);
		              return estado;
			          break;
			case '4': estado = querie_9(filiais);
			          return estado;
			          break;
		
			case '5': estado = querie_10(filiais); 
			          return estado;
			          break;
			
			case '6': estado = querie_11(filiais);
			          return estado;
			          break;
		
			case '7': estado = querie_12(filiais,faturas);
			          return estado;
			          break;
		
			case 'V': return MENU_PRINCIPAL; break;

			default: break;
		}
	}
}