#include "./headers/clientes.h"

#include <stdlib.h>
#include <string.h> 


struct cliente {
  char *name;
};

struct catalogo_clientes {
  Catalogo catalogo;
};



Cliente criaCliente() {
  Cliente client = malloc(sizeof(struct cliente));
  client->name = NULL;
  return client;
}


Cliente altera_Cliente(Cliente c, char* novo) {
  if(c->name) {
    free(c->name);
  }
    c->name = malloc((strlen(novo)+1)*sizeof(char));
    strcpy(c->name,novo);
    
  return c;
}


char* getNomeCliente(Cliente client, char* novo) {
  strcpy(novo,client->name);
  return novo;
}


void free_cliente(Cliente client) {
  free(client->name);
  free(client);
}


Cat_Clientes init_cat_clientes() {
  Cat_Clientes catalog = malloc(sizeof(struct catalogo_clientes));
  catalog->catalogo = init_Catalogo();
  return catalog;
}


Boolean existe_Cliente(Cat_Clientes clients, Cliente client) {
  return existe_Catalogo(clients->catalogo,client->name);
}


Cat_Clientes insere_Cliente(Cat_Clientes clients, Cliente client) {
  clients->catalogo = insere_Catalogo(clients->catalogo,client->name,NULL);
  return clients;
}


int total_Clientes(Cat_Clientes clients) {
  return total_elems_Catalogo(clients->catalogo);
}


int total_Clientes_letra(Cat_Clientes clients, char letra) {
  return total_elems_letra(clients->catalogo,letra);
}


void remove_Catalogo_Clientes(Cat_Clientes clients) {
  remove_Catalogo(clients->catalogo,NULL);
  free(clients);
}

Catalogo get_Catalogo_Clientes(Cat_Clientes clientes, Catalogo novo) {
  novo = clone_Catalogo(clientes->catalogo, novo);
  return novo;
}