#include "./headers/venda.h"

#include <stdlib.h>

struct venda {
    Produto produto;
    double preco;
    int quantidade; 
    char promocao;
    Cliente cliente;
    int mes;
    int filial;
};


Venda initVenda() {
    Venda sale = (Venda) malloc(sizeof(struct venda));
    sale->produto = criaProduto();
    sale->cliente = criaCliente();
    return sale;
}

void free_Venda(Venda v) {
    free_produto(v->produto);
    free_cliente(v->cliente);
    free(v);
}
 

Venda change_sale(Venda sale, char* product, double price, int quantity, char promotion, char* client, int month, int shop) {
    sale->produto = altera_Produto(sale->produto,product);
    sale->preco = price;
    sale->quantidade = quantity;
    sale->promocao = promotion;
    sale->cliente = altera_Cliente(sale->cliente,client);
    sale->mes = month;
    sale->filial = shop;
    return sale;
}


Produto getProduto(Venda sale) {
    return sale->produto;
}


Cliente getCliente(Venda sale) {
    return sale->cliente;
}


int getMes(Venda sale) {
    return sale->mes;
}


int getFilial(Venda sale) {
    return sale->filial;
}


int getQuantidade(Venda sale) {
    return sale->quantidade;
}


char getPromocao(Venda sale) {
    return sale->promocao;
}


double getPreco(Venda sale) {
    return sale->preco;
}


Boolean validate_sale(Cat_Produtos produtos, Cat_Clientes clientes, Venda venda) {
   return existe_Produto(produtos,getProduto(venda)) && existe_Cliente(clientes,getCliente(venda)) && 
            venda->mes >= 1 && venda->mes <= 12 && venda->quantidade > 0 && venda->quantidade <= 200 && venda->preco >= 0 && 
            venda->preco <= 999.99 && venda->filial > 0 && venda->filial < 4 && (venda->promocao == 'N' || venda->promocao == 'P');
}