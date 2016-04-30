#include "./headers/interpretador.h"
#include "./headers/clientes.h"
#include "./headers/produtos.h"
#include "./headers/faturacao.h"
#include "./headers/filial.h"



/**
 * Funcão main do programa que chamando auxiliares inicializa as estruturas, corre o programa e liberta o espaço alocado.
 * @return int.
 */
int main() {

    int estado = 1;
    int i;
    
    Cat_Clientes clientes;
    Cat_Produtos produtos;
    Faturacao faturacao;
    Filial filiais[NR_FILIAIS];

    while(estado) {
        
        clientes = init_cat_clientes();
        produtos = init_cat_produtos();
        faturacao = init_Faturacao();

        for(i = 0; i < NR_FILIAIS; i++) {
            filiais[i] = init_Filial();
        }
    
    	estado = menu_principal(produtos,clientes,faturacao,filiais,estado);
        
        if(total_Produtos(produtos)) {
    	   remove_Catalogo_Clientes(clientes);
    	   remove_Catalogo_Produtos(produtos);
    	   free_Faturacao(faturacao);
            for(i = 0; i < NR_FILIAIS; i++) free_Filial(filiais[i]);
        }
    }

    return 0;
}