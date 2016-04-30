#include "./headers/leituras.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAXBUFFERCLIENTES 32
#define MAXBUFFERPRODUTOS 64
#define MAXBUFFERVENDAS 128


static Cat_Clientes converte_clientes(Cat_Clientes costumers, FILE *f_clients, char* file_name);
static Cat_Produtos converte_produtos(Cat_Produtos products, FILE *f_prods, char* file_name);
static void converte_vendas(Cat_Produtos products, Cat_Clientes costumers, Faturacao faturas, Filial filiais[], FILE *fp,char* file_name);


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
void leitura_ficheiros(Cat_Clientes costumers, Cat_Produtos products, Faturacao contas, Filial filiais[3], FILE *f_clients, FILE *f_prods, FILE* f_sales, char* f_cname, char* f_pname, char* f_vname) {
   int i;
   char continua[10];
   time_t begin, end;
   double time_spent;

   time(&begin);

   system("clear");
   printf("\tLeitura dos ficheiros\n\n");
   costumers = converte_clientes(costumers,f_clients,f_cname);
   products = converte_produtos(products,f_prods,f_pname);
   contas = cria_Dados_Faturacao(contas,products);
   for(i = 0; i < 3; i++) filiais[i] = cria_Dados_Filial(filiais[i],products,costumers);

   converte_vendas(products,costumers,contas,filiais,f_sales,f_vname);
   
   time(&end);
   time_spent = difftime(end, begin);
   
   printf(" Tempo total de leitura: %f segundos\n",time_spent);
   putchar('\n');
   printf("Prima uma tecla para continuar >> ");
   int input = scanf("%s",continua);
}



static Cat_Clientes converte_clientes(Cat_Clientes costumers, FILE *f_clients, char* file_name) {
   
   time_t begin, end;
   double time_spent;

   time(&begin);

   char *information;
   char line[MAXBUFFERCLIENTES];
   
   int clientes_validos = 0, total = 0;
   Cliente client = criaCliente();

   while(fgets(line,MAXBUFFERCLIENTES,f_clients)) {
      
      information = strtok(line,"\n\r");
      
      if(information != NULL) {
         client = altera_Cliente(client,information);
         costumers = insere_Cliente(costumers, client);   
         clientes_validos++;
      }

      total++;
   }
   free_cliente(client);
   
   time(&end);
   time_spent = difftime(end, begin);
   
   printf(" Nome do Ficheiro: %s\n",file_name);
   printf(" Número de linhas lidas: %d\n",total);
   printf(" Número de linhas válidas: %d\n",clientes_validos);
   printf(" Tempo de Leitura: %f segundos\n",time_spent);
   putchar('\n');

   fclose(f_clients);
   
   return costumers;
}



static Cat_Produtos converte_produtos(Cat_Produtos products, FILE *f_prods, char* file_name) {

   time_t begin, end;
   double time_spent;

   time(&begin);

   char *information;
   char line[MAXBUFFERPRODUTOS];
   int produtos_validos = 0, total = 0;

   Produto prod = criaProduto();
   
   while(fgets(line,MAXBUFFERPRODUTOS,f_prods)) {
      
      information = strtok(line,"\n\r");
      
      if(information != NULL) {
         prod = altera_Produto(prod,information);
         products = insere_produto(products, prod);
         produtos_validos++;
      }
      total++;
   }

   free_produto(prod);
   time(&end);
   time_spent = difftime(end, begin);

   printf(" Nome do Ficheiro: %s\n",file_name);
   printf(" Número de linhas lidas: %d\n",total);
   printf(" Número de linhas válidas: %d\n",produtos_validos);
   printf(" Tempo de Leitura: %f segundos\n",time_spent);
   putchar('\n');


   fclose(f_prods);
   return products;
}



static void converte_vendas(Cat_Produtos cat_produtos, Cat_Clientes cat_clientes, Faturacao faturas, Filial filiais[3], FILE *f_sales, char* file_name) {
   
   time_t begin, end;
   double time_spent;

   time(&begin);

   char line[MAXBUFFERVENDAS];
   char* information;
   
   int i, vendas_validas = 0, total = 0;
   Boolean verify;

   char* product;
   double price;
   int ammount; 
   char type;
   char* client;
   int month;
   int shop;
   
   Venda venda = initVenda();
      
   while(fgets(line,MAXBUFFERVENDAS,f_sales)) {

      information = strtok(line,"\n\r");
      information = strtok(information," ");
      for(i = 0; information != NULL; i++) {
         switch(i) {
            case 0: product = information; break;
            case 1: price = atof(information); break;
            case 2: ammount = atoi(information); break; 
            case 3: type = information[0]; break;
            case 4: client = information; break;
            case 5: month = atoi(information); break;
            case 6: shop = atoi(information); break;
            default: break;
         }
         information = strtok(NULL," ");
      }
      
      venda = change_sale(venda,product,price,ammount,type,client,month,shop);
      /* Verifica a existencia do produto e do cliente de uma dada venda */
      
      verify = validate_sale(cat_produtos,cat_clientes,venda);
      /* Caso verifique adiciona á estrutura das vendas a venda validada nessa iteração */
      if(verify) {
         faturas = adiciona_Fatura(faturas,venda);
         filiais[shop-1] = adiciona_Venda_Filial(filiais[shop-1],venda);
         vendas_validas++;
         total++;
      } else {
         total++;
      }
   }
   
   free_Venda(venda);
   time(&end);
   time_spent = difftime(end, begin);

   
   printf(" Nome do Ficheiro: %s\n",file_name);
   printf(" Número de linhas lidas: %d\n",total);
   printf(" Número de linhas válidas: %d\n",vendas_validas);
   printf(" Número de vendas inválidas: %d\n",total-vendas_validas);
   printf(" Tempo de Leitura: %lf segundos\n",time_spent);
   putchar('\n');   

   fclose(f_sales);   
}
