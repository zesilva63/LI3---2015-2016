#include "./headers/queries.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int querie_1(Cat_Produtos produtos,Cat_Clientes clientes,Faturacao faturas, Filial filiais[], int modo) {
	
	int input;
	char opcao[10];
	char f_clientes[50];
	char f_produtos[50];
	char f_vendas[50];
	FILE *file_clientes = NULL;
	FILE *file_produtos = NULL;
	FILE *file_vendas = NULL;

		if(modo == 1) {

			strcpy(f_clientes,"./Clientes.txt");
            strcpy(f_produtos,"./Produtos.txt");
            strcpy(f_vendas,"./Vendas_1M.txt");
            
            file_clientes = fopen(f_clientes,"r");
            file_produtos = fopen(f_produtos,"r");
            file_vendas = fopen(f_vendas,"r");
			if(file_clientes && file_produtos && file_vendas) {
				leitura_ficheiros(clientes,produtos,faturas,filiais,file_clientes,file_produtos,file_vendas,f_clientes,f_produtos,f_vendas);
			}else {
				printf("Ficheiros inválidos! Prima qualquer tecla para voltar ao menú >> ");
				input = scanf("%s",opcao);
				return 10;
			}
		} else if(modo == 2) {

			strcpy(f_clientes,"./Clientes.txt");
            strcpy(f_produtos,"./Produtos.txt");
            strcpy(f_vendas,"./Vendas_3M.txt");
            
            file_clientes = fopen(f_clientes,"r");
            file_produtos = fopen(f_produtos,"r");
            file_vendas = fopen(f_vendas,"r");
			if(file_clientes && file_produtos && file_vendas) {
				leitura_ficheiros(clientes,produtos,faturas,filiais,file_clientes,file_produtos,file_vendas,f_clientes,f_produtos,f_vendas);
			} else {
				printf("Ficheiros inválidos! Prima qualquer tecla para voltar ao menú >> ");
				input = scanf("%s",opcao);
				return 10;
			}
		} else if(modo == 3) {

			strcpy(f_clientes,"./Clientes.txt");
            strcpy(f_produtos,"./Produtos.txt");
            strcpy(f_vendas,"./Vendas_5M.txt");
            
            file_clientes = fopen(f_clientes,"r");
            file_produtos = fopen(f_produtos,"r");
            file_vendas = fopen(f_vendas,"r");
			if(file_clientes && file_produtos && file_vendas) {
				leitura_ficheiros(clientes,produtos,faturas,filiais,file_clientes,file_produtos,file_vendas,f_clientes,f_produtos,f_vendas);
			} else {
				printf("Ficheiros inválidos! Prima qualquer tecla para voltar ao menú >> ");
				input = scanf("%s",opcao);
				return 10;
			}
		} else {
			system("clear");
			printf("_____________________________________________\n");
			printf("\n\t   Leitura de Ficheiros\n");
			printf("_____________________________________________\n");
			while(file_clientes == NULL) {
				printf("\nIndique o nome do ficheiro de clientes >> ");
				input = scanf("%s",f_clientes);
				file_clientes = fopen(f_clientes,"r");
				if(file_clientes == NULL) printf("\nFicheiro de Clientes Inválido\n");
			}
			while(file_produtos == NULL) {
				printf("\nIndique o nome do ficheiro de produtos >> ");
				input = scanf("%s",f_produtos);
				file_produtos = fopen(f_produtos,"r");
				if(file_produtos == NULL) printf("Ficheiro de Produtos Inválido\n");
			}
			while(file_vendas == NULL) {
				printf("\nIndique o nome do ficheiro de vendas >> ");
				input = scanf("%s",f_vendas);
				file_vendas = fopen(f_vendas,"r");
				if(file_vendas == NULL) printf("Ficheiro de Vendas Inválido\n");
			}
			leitura_ficheiros(clientes,produtos,faturas,filiais,file_clientes,file_produtos,file_vendas,f_clientes,f_produtos,f_vendas);
		}
	return 10;
}


int querie_2(Cat_Produtos produtos) {
	
	int estado = 1, input;
	char opcao[20];
	char letra;
	Conj_Produtos lista_produtos = init_Conjunto(1000);
	
	int pagina = 1;

	while(estado) {
		system("clear");
		printf( "_____________________________________________\n" );
		printf( "\tListagem de Produtos - QUERIE 2\n\n" );	
		printf("Diga a letra a procurar >> ");
	
		input = scanf("%s",opcao);
			
		if(isalpha(opcao[0])) {
			char letra = toupper(opcao[0]);
			lista_produtos = converte_Produtos(lista_produtos,produtos,letra);
			while(pagina) {
				Pagina p = init_Pagina(TAMANHO_PAGINA);
				p = getPagina(p,get_Lista_Produtos(lista_produtos),pagina);
				pagina = apresentaPagina(p);
				free_Pagina(p);
			}
			
			free_Conj_Produtos(lista_produtos);
			return estado;
		}
	}
	return 1;
}



int querie_3(Faturacao faturas) {
	
	int estado = 1, input, voltar = 1;
	char produto[20];
	char opcao[10];
	char opcao2[10];
	char meses[10];
	int mes = 0;
	char letra;
	
	while(estado) {
		voltar = 1;
		system("clear");
		printf( "_____________________________________________\n" );
		printf( "   Vendas e Faturacao dado mês - QUERIE 3\n\n" );
		
		printf("Diga o mês a procurar >> ");
		input = scanf("%s",meses);
		mes = atoi(meses);
		
		printf("\nDiga o produto a procurar >> ");
		input = scanf("%s",produto);
		
		while(voltar) {

			printf("\nPretende valor T (Total) ou F (Filiais) >> ");
			input = scanf("%s",opcao2);
			
			if(opcao2[0] == 'T') {
				int total_quant_mes_normal = get_total_vendas_mes_produto(faturas,produto,mes,'N');
				int total_quant_mes_promo = get_total_vendas_mes_produto(faturas,produto,mes,'P');
				double total_preco_mes_normal = get_total_precos_mes_produto(faturas,produto,mes,'N');
				double total_preco_mes_promo = get_total_precos_mes_produto(faturas,produto,mes,'P');
				
				system("clear");
				printf( "_____________________________________________\n" );
				printf( "   Vendas e Faturacao dado mês - QUERIE 3\n" );
				printf( "    Vendas no mês %d do Produto %s\n",mes,produto);
				printf( "_____________________________________________\n" );
				printf( "     Vendas\t\t   Faturação\n");
				printf( "_____________________________________________\n" );
				printf(" Normal\tPromoção\tNormal\tPromoção\n");
				printf(" %5d\t%5d\t\t%6.2f\t%6.2f\n",total_quant_mes_normal,total_quant_mes_promo,total_preco_mes_normal,total_preco_mes_promo);
				printf( "_____________________________________________\n" );
				printf( "  V - Voltar\t\tQ - Sair:\n" );
				printf("\nEscolha uma opção >> ");
				
				input = scanf("%s",opcao);
				
				switch(opcao[0]) {
					case 'V': return estado; break;
					
					case 'Q': return 0; break;
					
					default: break;
				}

			}

			if(opcao2[0] == 'F') {
				int total_quant_mes_normal_1 = get_total_vendas_mes_produto_filial(faturas,produto,mes,'N',1);
				int total_quant_mes_normal_2 = get_total_vendas_mes_produto_filial(faturas,produto,mes,'N',2);
				int total_quant_mes_normal_3 = get_total_vendas_mes_produto_filial(faturas,produto,mes,'N',3);

				int total_quant_mes_promo_1 = get_total_vendas_mes_produto_filial(faturas,produto,mes,'P',1);
				int total_quant_mes_promo_2 = get_total_vendas_mes_produto_filial(faturas,produto,mes,'P',2);
				int total_quant_mes_promo_3 = get_total_vendas_mes_produto_filial(faturas,produto,mes,'P',3);
				
				double total_preco_mes_normal_1 = get_total_precos_mes_produto_filial(faturas,produto,mes,'N',1);
				double total_preco_mes_normal_2 = get_total_precos_mes_produto_filial(faturas,produto,mes,'N',2);
				double total_preco_mes_normal_3 = get_total_precos_mes_produto_filial(faturas,produto,mes,'N',3);
				
				double total_preco_mes_promo_1 = get_total_precos_mes_produto_filial(faturas,produto,mes,'P',1);
				double total_preco_mes_promo_2 = get_total_precos_mes_produto_filial(faturas,produto,mes,'P',2);
				double total_preco_mes_promo_3 = get_total_precos_mes_produto_filial(faturas,produto,mes,'P',3);
				
				system("clear");
				printf( "\tVendas no mês %d do produto %s\n",mes,produto);
				printf( "______________________________________________________\n" );
				printf( "\t\tVendas\t\t   Faturação\n");
				printf( "______________________________________________________\n" );
				printf("\t  Normal  Promoção\tNormal    Promoção\n");
				printf("Filial 1 %5d \t%5d \t\t%7.2f\t  %7.2f\n",total_quant_mes_normal_1, total_quant_mes_promo_1, total_preco_mes_normal_1, total_preco_mes_promo_1);
				printf("Filial 2 %5d \t%5d \t\t%7.2f\t  %7.2f\n",total_quant_mes_normal_2, total_quant_mes_promo_2, total_preco_mes_normal_2, total_preco_mes_promo_2);
				printf("Filial 3 %5d \t%5d \t\t%7.2f\t  %7.2f\n",total_quant_mes_normal_3, total_quant_mes_promo_3, total_preco_mes_normal_3, total_preco_mes_promo_3);
				printf( "______________________________________________________\n" );
				printf( "  V - Voltar\t\tQ - Sair:\n" );
				
				printf("Escolha uma opção >> ");
				
				input = scanf("%s",opcao);
				
				switch(opcao[0]) {
					case 'V': return estado; break;
					
					case 'Q': return 0; break;
					
					default: break;
				}	
			}
		}
	}

	return estado;
}



int querie_4(Faturacao faturas) {

	int estado = 1, input, filial = 0, pagina = 1;
	char opcao[10];
	char fil[10];
	
	while(estado) {
		system("clear");
		printf( "_____________________________________________\n" );
		printf( "   Produtos não comprados - QUERIE 4\n\n" );
		printf( "_____________________________________________\n" );
		printf(" Escolha uma das seguintes opções:\n\n");
		printf("  1. Valores Totais\n");
		printf("  2. Valores por filiais\n");
		printf("_____________________________________________\n" );
		printf( "  V - Voltar\t\tQ - Sair:\n" );
		printf( "_____________________________________________\n" );

		printf("\nEscolha uma opção >> ");
		input = scanf("%s",opcao);
		
		switch(opcao[0]) {
			case 'Q': return 0; break;

			case 'V': return estado; break;

			default: break;
		}

		if(opcao[0] == '1') { 
			Conj_Faturas nao_comprados = init_Lista_Faturacao(1000);
			nao_comprados = faturas_produtos_nao_comprados_totais(nao_comprados,faturas);
			if(faturacao_getPos(nao_comprados) == 0) { 
				printf("\n Todos os produtos foram comprados em todas as filiais!\n");
				printf("\nPrima qualquer tecla para continuar ou Q para sair >> ");
				input = scanf("%s",opcao);
		
				switch(opcao[0]) {
					case 'Q': return 0; break;

					case 'V': return estado; break;

					default: return estado; break;
				}
			}

			while(pagina) {
				Pagina p = init_Pagina(TAMANHO_PAGINA);
				p = getPagina(p,apresenta_faturas(nao_comprados),pagina);
				pagina = apresentaPagina(p);
				free_Pagina(p);
			}
			
			free_Conj_Faturas(nao_comprados);
			return estado;
		}		
		else if(opcao[0] == '2') { 
			
			Conj_Faturas totais = init_Lista_Faturacao(1000);
			Conj_Faturas nao_comprados_1 = init_Lista_Faturacao(1000); 
			Conj_Faturas nao_comprados_2 = init_Lista_Faturacao(1000); 
			Conj_Faturas nao_comprados_3 = init_Lista_Faturacao(1000); 
			
			totais = cria_lista_total(totais,faturas);
			
			nao_comprados_1 = faturas_nao_comprado_filial(totais,nao_comprados_1,faturas,1);
			nao_comprados_2 = faturas_nao_comprado_filial(totais,nao_comprados_2,faturas,2);
			nao_comprados_3 = faturas_nao_comprado_filial(totais,nao_comprados_3,faturas,3);
			
			system("clear");
			printf("\n_____________________________________________\n" );
			printf("   Produtos não comprados - QUERIE 4\n\n" );
			printf("\n Produtos não comprados na Filial 1 -> %d\n",faturacao_getPos(nao_comprados_1));
			printf("\n Produtos não comprados na Filial 2 -> %d\n",faturacao_getPos(nao_comprados_2));
			printf("\n Produtos não comprados na Filial 3 -> %d\n",faturacao_getPos(nao_comprados_3));

			while(filial < 1 || filial > 3) {
				printf("\nInsira a filial que pretende >> ");
				input = scanf("%s",fil);
				filial = atoi(fil);
			}

			if(filial == 1) { 
				while(pagina) {
					Pagina p = init_Pagina(TAMANHO_PAGINA);
					p = getPagina(p,apresenta_faturas(nao_comprados_1),pagina);
					pagina = apresentaPagina(p);
					free_Pagina(p);
				}
			}
			if(filial == 2) { 
				while(pagina) {
					Pagina p = init_Pagina(TAMANHO_PAGINA);
					p = getPagina(p,apresenta_faturas(nao_comprados_2),pagina);
					pagina = apresentaPagina(p);
					free_Pagina(p);
				}
			}
			if(filial == 3) { 
				while(pagina) {
					Pagina p = init_Pagina(TAMANHO_PAGINA);
					p = getPagina(p,apresenta_faturas(nao_comprados_3),pagina);
					pagina = apresentaPagina(p);
					free_Pagina(p);
				}
			}

			free_Conj_Faturas(totais);
			free_Conj_Faturas(nao_comprados_1);
			free_Conj_Faturas(nao_comprados_2);
			free_Conj_Faturas(nao_comprados_3);
			return estado;
		}
	}
	
	return estado;
}



int querie_5(Filial filiais[]) {

	int estado = 1, input, j, i;
	int resultado[12][3];
	char cliente[10];
	char opcao[10];
	Boolean existe = false;
	
	while(estado) {
		system("clear");
		printf( "_____________________________________________\n" );
		printf( "  Números de unidades Compradas - QUERIE 5\n\n" );
		
		while (existe == false) {
			printf(" Insira o codigo do cliente >> ");
			input = scanf("%s",cliente);
			existe = filial_existe_Cliente(filiais[0],cliente);
			if(!existe) printf("O Cliente não é válido, insira de novo\n\n");
		}

		for(i = 0; i < 12; i++) {
			for(j = 0; j < 3; j++) {
				resultado[i][j] = nr_total_unidades_compradas(filiais[j],cliente,i+1);
			}
		}

		system("clear");	
		printf( "\n    Quantidades do cliente |%s| - Querie 5\n",cliente);
		printf( "_________________________________________________\n" );
		printf("\t   Filial 1    Filial 2    Filial 3\n");
		
		for(i = 0; i != 12; i++) {
			printf("Mês %d \t %5d \t    %5d \t %5d\n", i+1, resultado[i][0],resultado[i][1],resultado[i][2]);
		}
		printf( "_________________________________________________\n" );
		printf( "  V - Voltar\t\tQ - Sair:\n" );
		
		printf("\nEscolha uma opção >> ");	
		input = scanf("%s",opcao);
		switch(opcao[0]) {
			case 'V': return estado; break;

			case 'Q': return 0; break;
					
			default: break;
		}
	}
	return estado;
}	
	


int querie_6(Faturacao faturas) {


	int estado = 1, input, mes1 = 50, mes2 = 50;
	int voltar = 1;
	double total_faturado_intervalo;
	int total_vendas_intervalo;
	char opcao[10];
	char m1[10];
	char m2[10];
	
	while(estado) {
		
		system("clear");
		printf( "_____________________________________________\n" );
		printf( " Valores totais num intervalo - QUERIE 6\n\n" );
		
		printf("\nInsira o primeiro mês do intervalo >> ");
		
		while(mes1 < 1 || mes1 > 12) {
			input = scanf("%s",m1);
			mes1 = atoi(m1);
			if(mes1 < 1 || mes1 > 12) { 
				printf("\nMês inserido invalido\n");
				printf("\nInsira o primeiro mês do intervalo >> ");
			}
		}

		printf("\nInsira o segundo mês do intervalo >> ");

		while(mes2 < 1 || mes2 > 12) {
			input = scanf("%s",m2);
			mes2 = atoi(m2);
			if(mes2 < 1 || mes2 > 12) { 
				printf("\nMês inserido invalido\n");
				printf("\nInsira o segundo mês do intervalo >> ");
			}
		}

		total_faturado_intervalo = get_total_faturado_intervalo(faturas,mes1,mes2);
		total_vendas_intervalo = get_total_vendas_intervalo(faturas,mes1,mes2);

		while(voltar) {
			system("clear");
			printf( "_____________________________________________\n" );
			printf( " Valores totais num intervalo - QUERIE 6\n" );
			printf( "\n  Total de vendas entre mês %d e o mês %d\n",mes1,mes2);
			printf( "_____________________________________________\n" );
			printf( "\tVendas\t\tFaturação\n");
			printf("\t%7d\t%10.2f\n",total_vendas_intervalo,total_faturado_intervalo);
			printf( "_____________________________________________\n" );
			printf( "  V - Voltar\t\tQ - Sair:\n" );
			printf( "_____________________________________________\n" );
			
			
			printf("Escolha uma opção >> ");
			
			input = scanf("%s",opcao);
			
			switch(opcao[0]) {
				case 'V': return estado; break;
				
				case 'Q': return 0; break;
				
				default: break;
			}	
		}
	}
	return estado;
}



int querie_7(Filial filiais[]){
	
	int estado = 1, input,i,pagina = 1; 
	char *elem;
	char opcao[10];
	Conj_Filiais comprados_1 = init_Conj_Filiais(3000);
	Conj_Filiais comprados_total = init_Conj_Filiais(3000);

	comprados_1 = lista_clientes_compraram_filial(comprados_1,filiais[0]);
	int tamanho = filial_getPos(comprados_1);
	
	for(i = 0; i < tamanho; i++) {
		elem = filial_get_elemento_lista(comprados_1,i);
		if(verifica_cliente_comprado(filiais[1],elem) && verifica_cliente_comprado(filiais[2], elem)) adiciona_Nome(comprados_total,elem); 
	}
	
	while(pagina) {
		Pagina p = init_Pagina(TAMANHO_PAGINA);
		p = getPagina(p,get_Lista_Filial(comprados_total),pagina);
		pagina = apresentaPagina(p);
		free_Pagina(p);
	}

	free_Conj_Filiais(comprados_total);
	free_Conj_Filiais(comprados_1);
	
	return estado;
}



int querie_8(Filial filiais[]) {

	int estado = 1, input, filial = 0, pagina = 1, voltar = 1;
	
	char produto[10];
	char fil[10];
	char promo[10];
	Boolean existe = false;
	int total_N = 0, total_P = 0;

	Conj_Filiais normal;
	Conj_Filiais promocao;	

	while(estado) {
		system("clear");
		printf( "_____________________________________________\n" );
		printf( "   Clientes de um Produto - QUERIE 8\n\n" );

		while (existe == false) {
			printf(" Insira o codigo do produto >> ");
			input = scanf("%s",produto);
			existe = filial_existe_Produto(filiais[0],produto);
			if(!existe) printf("O Produto não é válido, insira de novo\n\n");
		}
		
		while(filial < 1 || filial > 3) {
			printf("\nInsira a filial que pretende >> ");
			input = scanf("%s",fil);
			filial = atoi(fil);
			if(filial < 1 || filial > 3) printf("A filial não é válida, insira de novo\n\n");
		}

		normal = lista_clientes_de_produto(filiais[filial-1],produto,'N');
		promocao = lista_clientes_de_produto(filiais[filial-1],produto,'P');
		
		if(normal != NULL) total_N = filial_getPos(normal);
		if(promocao != NULL) total_P = filial_getPos(promocao);


		while(voltar) {
			pagina = 1;
			system("clear");
			printf( "_____________________________________________\n" );
			printf( "   Clientes de um Produto - QUERIE 8\n\n");
			printf("\n  Total em modo N: %d\n",total_N);
			printf("  Total em modo P: %d\n\n",total_P);
			printf(" Indique a opção:\n\n"); 
			printf("  Lista de Clientes em modo Normal -> Prima N\n"); 
			printf("  Lista de Clientes em Promoção -> Prima P\n");
			printf("  Voltar -> Prima qualquer outra tecla\n");
			printf("\n  Opção >> ");
			input = scanf("%s",promo);

			if((promo[0] == 'N' || promo[0] == 'n') && total_N != 0) {
			
				while(pagina) {
					Pagina p = init_Pagina(TAMANHO_PAGINA);
					p = getPagina(p,get_Lista_Filial(normal),pagina);
					pagina = apresentaPagina(p);
					free_Pagina(p);
				}

			}else if((promo[0] == 'P' || promo[0] == 'p') && total_P != 0) { 
			
				while(pagina) {
					Pagina p = init_Pagina(TAMANHO_PAGINA);
					p = getPagina(p,get_Lista_Filial(promocao),pagina);
					pagina = apresentaPagina(p);
					free_Pagina(p);
				}

			}else return estado;

		}

	}
	return estado;
}



int querie_9(Filial filiais[]){
	int i;
	int estado = 1, input, m = 0, pagina = 1;
	
	char cliente[20];
	char mes[10];
	char promo[10];
	Boolean existe = false;

	Conj_Filiais valores = init_Conj_Filiais(100);	
	HEAP heap = init_HEAP();

	while(estado) {
		system("clear");
		printf( "_____________________________________________\n");
		printf( "  Produtos de um cliente num mês - QUERIE 9\n\n");
		
		while (existe == false) {
			printf(" Insira o codigo do cliente >> ");
			input = scanf("%s",cliente);
			existe = filial_existe_Cliente(filiais[0],cliente);
			if(!existe) printf("O Cliente não é válido, insira de novo\n\n");
		}

		while(m < 1 || m > 12) {
		printf("\nInsira o mês >> ");
			input = scanf("%s",mes);
			m = atoi(mes);
			if(m < 1 || m > 12) printf("O Mês não é válido, insira de novo\n\n");
		}

		for(i = 0; i < 3; i++) heap = lista_codigos_de_clientes(filiais[i],heap,cliente,m,'Q');
		
		valores = convert_Heap_Lista(valores,heap,'Q');
		
		while(pagina) {
			Pagina p = init_Pagina(TAMANHO_PAGINA);
			p = getPagina(p,get_Lista_Filial(valores),pagina);
			pagina = apresentaPagina(p);
			free_Pagina(p);
		}
		
		free_Conj_Filiais(valores);
		free_HEAP(heap);

		return estado;
	}
	return estado;
}



int querie_10(Filial filiais[]) {
	
	int i, pagina = 1, j;
	int estado = 1, input, nr = 0;
	char n_produtos[10];
	
	Conj_Filiais valores_1 = init_Conj_Filiais(1000);
	HEAP heap_1 = init_HEAP();
	heap_1 = heap_produtos_mais_vendidos(filiais[0],heap_1);
	
	Conj_Filiais valores_2 = init_Conj_Filiais(1000);
	HEAP heap_2 = init_HEAP();
	heap_2 = heap_produtos_mais_vendidos(filiais[1],heap_2);
	
	Conj_Filiais valores_3 = init_Conj_Filiais(1000);
	HEAP heap_3 = init_HEAP();
	heap_3 = heap_produtos_mais_vendidos(filiais[2],heap_3);
	
  
	system("clear");
	printf( "_____________________________________________\n" );
	printf( "   N Produtos mais comprados - QUERIE 10\n\n" );

	while(nr < 1 || nr > 171008) {
	printf("\nIndique o número de produtos mais vendidos que pretende ver >> ");
		input = scanf("%s",n_produtos);
		nr = atoi(n_produtos);
		if(nr < 1 || nr > 171008) printf("O valor não é válido, insira de novo\n\n");
	}
				
	valores_1 = retira_N_Produtos(valores_1,heap_1,nr);
	valores_2 = retira_N_Produtos(valores_2,heap_2,nr);	
	valores_3 = retira_N_Produtos(valores_3,heap_3,nr);


	Lista total = init_Lista(100);
	char buffer[256];
	sprintf(buffer,"\t\tFilial 1\t\tFilial 2\t\tFilial 3\n\t#\tProduto\tC\tQ\tProduto\tC\tQ\tProduto\tC\tQ");
	total = lista_insere_cabecalho(total,buffer);
	
	for(i = 0; i < nr; i++) {
			sprintf(buffer,"%s\t%d\t%d\t%s\t%d\t%d\t%s\t%d\t%d",filial_get_elemento_lista(valores_1,i),
            	nr_clientes_de_um_produto(filiais[0],filial_get_elemento_lista(valores_1,i)),
            	getQuantidadeProduto(filiais[0],filial_get_elemento_lista(valores_1,i)),
            	filial_get_elemento_lista(valores_2,i),nr_clientes_de_um_produto(filiais[1],
            	filial_get_elemento_lista(valores_2,i)),getQuantidadeProduto(filiais[1],
            	filial_get_elemento_lista(valores_2,i)),filial_get_elemento_lista(valores_3,i),
            	nr_clientes_de_um_produto(filiais[2],filial_get_elemento_lista(valores_3,i)),
            	getQuantidadeProduto(filiais[2],filial_get_elemento_lista(valores_3,i)));
		total = lista_insert(total,buffer);
	}

	while(pagina) {
		Pagina p = init_Pagina(TAMANHO_PAGINA);
		p = getPagina(p,total,pagina);
		pagina = apresentaPagina(p);
		free_Pagina(p);
	}
		

    return estado;
}



int querie_11(Filial filiais[]){
	
	int i;
	int estado = 1, input, pagina = 1;
	
	char cliente[10];
	Boolean existe = false;

	Conj_Filiais valores = init_Conj_Filiais(5);	
	HEAP heap = init_HEAP();

	system("clear");
	printf( "_____________________________________________\n" );
	printf( "   Top 3 de um Cliente - QUERIE 11\n\n" );

		
	while (existe == false) {
		printf(" Insira o codigo do cliente >> ");
		input = scanf("%s",cliente);
		existe = filial_existe_Cliente(filiais[0],cliente);
		if(!existe) printf("O Cliente não é válido, insira de novo\n\n");
	}
		
	for(i = 0; i < 3; i++) heap = top3_clientes(filiais[i],heap,cliente,'F');
	valores = lista_top3(valores,heap,'F');

	while(pagina) {
		Pagina p = init_Pagina(TAMANHO_PAGINA);
		p = getPagina(p,get_Lista_Filial(valores),pagina);
		pagina = apresentaPagina(p);
		free_Pagina(p);
	}

	free_Conj_Filiais(valores);
	free_HEAP(heap);
	
		
	return estado;
}



int querie_12(Filial filiais[], Faturacao faturas){
 
	int estado = 1, input, i, nr_clientes = 0, nr_produtos;
	char opcao[10];
	char* client;
	Conj_Faturas nao_comprados = init_Lista_Faturacao(1000);
	nao_comprados = faturas_produtos_nao_comprados_totais(nao_comprados,faturas);
	nr_produtos = faturacao_getPos(nao_comprados);
	free_Conj_Faturas(nao_comprados);

	Conj_Filiais clientes_nao_comprados_total = init_Conj_Filiais(1000);
	clientes_nao_comprados_total = converte_total_clientes(clientes_nao_comprados_total,filiais[0]);

	for(i = 0; i < filial_getPos(clientes_nao_comprados_total); i++) {
		client = filial_get_elemento_lista(clientes_nao_comprados_total,i); 
		if(verifica_cliente_comprado(filiais[0],client) == false && verifica_cliente_comprado(filiais[1],client) == false && verifica_cliente_comprado(filiais[2],client) == false) nr_clientes++;
	}
	free_Conj_Filiais(clientes_nao_comprados_total);

		system("clear");
		printf( "_____________________________________________\n" );
		printf( "   Elementos não comprados - QUERIE 12\n\n" );
		printf(" Número de Produtos não comprados: %d\n",nr_produtos);
		printf(" Número de Clientes que não compraram: %d\n", nr_clientes);
		printf("_____________________________________________\n" );
		printf( "  V - Voltar\t\tQ - Sair:\n" );
		printf( "_____________________________________________\n" );

		printf("\nEscolha uma opção >> ");
		input = scanf("%s",opcao);
		
		switch(opcao[0]) {
			case 'Q': 
	  				  return 0; 
	  				  break;

			case 'V': return estado; break;

			default: break;
		}	
	return estado;
}




int apresentaPagina(Pagina p) {
    int i, input;
    char opcao[10];
    system("clear");
    printf("\n");
    printf("Número total de elementos: %d\n\n",getNrElementosTotal(p));
    printf(" --- Página número |%d| de |%d| ---\n", getNrPagina(p),getNrPaginaTotal(p));
    
    if(getCabecalho(p)) {
    	printf("%s\n",getCabecalho(p));
    }

    for(i = 0; i < getNrElementosPag(p); i++) {
        printf("\t%d\t%s\n",(getNrPagina(p)-1)*20+(i+1),getStringPagina(p,i));
    }
    
    putchar('\n');
        printf(" 1 - [<<]  2 - [<]  3 - [>]  4 - [>>]   V - Voltar\n");
        putchar('\n');
        printf("Opcao numero > ");
        input = scanf("%s",opcao);

    switch(opcao[0]) {
        case 'V': return 0; break;

        case '1': return 1;

        case '2': if(getNrPagina(p) > 1) return getNrPagina(p)-1; break;

        case '3': if(getNrPagina(p) < getNrPaginaTotal(p)) return getNrPagina(p)+1; break;

        case '4': return getNrPaginaTotal(p); break;

        default: return getNrPagina(p); break;
    }
}
