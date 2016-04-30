#include "./headers/heap.h"

#include <stdlib.h>
#include <string.h>


#define PAI(i) (i-1)/2
#define ESQUERDO(i) 2*i + 1
#define DIREITO(i) 2*i + 2

#define PAI_P(i) heap->produto[(i-1)/2]
#define PAI_Q(i) heap->quantidade[(i-1)/2]
#define PAI_C(i) heap->custo[(i-1)/2]

#define FILHO_E_P(i) heap->produto[2*i+1]
#define FILHO_E_Q(i) heap->quantidade[2*i+1]
#define FILHO_E_C(i) heap->custo[2*i+1]

#define FILHO_D_P(i) heap->produto[2*i+2]
#define FILHO_D_Q(i) heap->quantidade[2*i+2]
#define FILHO_D_C(i) heap->custo[2*i+2]

#define NODO_P(i) heap->produto[i]
#define NODO_Q(i) heap->quantidade[i]
#define NODO_C(i) heap->custo[i]


static Heap swap(Heap heap,int n1,int n2);
static Heap bubbleDown(Heap heap,int n, char ordenacao);
static Heap bubbleUp(Heap heap,int i, char ordenacao);


struct heap {
    int tamanho;
    int pos; 
    int *quantidade;
    float *custo;
    char **produto;
};


Heap initHeap(){
    Heap heap = malloc(sizeof(struct heap));
    heap->tamanho = 5;
    heap->pos = 0;
    heap->quantidade = (int*) malloc(5 *sizeof(int));
    heap->custo = malloc(5 *sizeof(float));
    heap->produto = (char**) malloc(5 *sizeof(char *));
    return heap;
}


Heap heap_push(Heap heap,char *produto, int quantidade, float custo, int modo, char ordenacao){
    int index;
    if(modo == 1) {
        index = existe_heap(heap,produto);
        if(heap->tamanho-1 == heap->pos) {
            heap->tamanho *= 2; 
            heap->quantidade = realloc(heap->quantidade,heap->tamanho *sizeof(int));
            heap->custo = realloc(heap->custo,heap->tamanho *sizeof(float));
            heap->produto = realloc(heap->produto,heap->tamanho *sizeof(char*));
        }

        if(index != -1) {
            heap->quantidade[index] += quantidade;
            heap->custo[index] += custo;
            heap = bubbleUp(heap,index,ordenacao);
        } else {
            NODO_Q(heap->pos) = quantidade;
            NODO_C(heap->pos) = custo;
            NODO_P(heap->pos) = malloc(8);
            strcpy(heap->produto[heap->pos],produto);
            heap = bubbleUp(heap,heap->pos,ordenacao);
            heap->pos++;
        }
    return heap;
    
    }else {
        if(heap->tamanho-1 == heap->pos) {
            heap->tamanho *= 2; 
            heap->quantidade = realloc(heap->quantidade,heap->tamanho *sizeof(int));
            heap->custo = realloc(heap->custo,heap->tamanho *sizeof(float));
            heap->produto = realloc(heap->produto,heap->tamanho *sizeof(char*));
        }
        
        NODO_Q(heap->pos) = quantidade;
        NODO_C(heap->pos) = custo;
        NODO_P(heap->pos) = malloc(8);
        strcpy(heap->produto[heap->pos],produto);
        heap = bubbleUp(heap,heap->pos,ordenacao);
        heap->pos++;

        return heap;
    }
}


int existe_heap(Heap heap, char* valor) {
    int i;
    int resultado = -1;
    for(i = 0; i < heap->pos; i++) {
        if( strcmp(heap->produto[i],valor) == 0) return i;
    }
    return resultado;
}


char *heap_pop(Heap heap, char ordenacao) {
    if(heap->pos==0) return 0;
    char *string = NODO_P(0);
    heap->pos--;
    NODO_P(0)=NODO_P(heap->pos);
    NODO_Q(0)=NODO_Q(heap->pos);
    NODO_C(0)=NODO_C(heap->pos);

    heap = bubbleDown(heap,heap->pos,ordenacao);
    
    return string;
}


static Heap bubbleDown(Heap heap,int n, char ordenacao) {
    int i,m;
    i=0;
    if(ordenacao == 'Q') {
        while(ESQUERDO(i) < n) {
            if(DIREITO(i) < n) m = FILHO_E_Q(i) > FILHO_D_Q(i) ? ESQUERDO(i) : DIREITO(i);
            else m = ESQUERDO(i);

            if(NODO_Q(i) < NODO_Q(m)) { 
                heap = swap(heap,i,m);
                i = m;
            }
            else return heap;
        }
        return heap;
    } else {
        while(ESQUERDO(i) < n) {
            if(DIREITO(i) < n) m = FILHO_E_C(i) > FILHO_D_C(i) ? ESQUERDO(i) : DIREITO(i);
            else m = ESQUERDO(i);

            if(NODO_C(i) < NODO_C(m)){ 
                heap = swap(heap,i,m);
                i = m;
            }
            else return heap;
        }
    }
}


static Heap bubbleUp(Heap heap, int i, char ordenacao){
    if(ordenacao == 'Q') {
        while(i > 0 && PAI_Q(i) < NODO_Q(i)){
            heap=swap(heap,i,PAI(i));
            i = PAI(i);
        }
        return heap;
    } else {
        while(i > 0 && PAI_C(i) < NODO_C(i)){
            heap=swap(heap,i,PAI(i));
            i = PAI(i);
        }
        return heap;
    }
}


static Heap swap(Heap heap,int n1,int n2) {
    
    char string[7];
    int n = NODO_Q(n1);
    float x = NODO_C(n1);
    strcpy(string,NODO_P(n1));
    
    NODO_Q(n1) = NODO_Q(n2);
    NODO_C(n1) = NODO_C(n2);
    strcpy(NODO_P(n1),NODO_P(n2));

    NODO_Q(n2) = n;
    NODO_C(n2) = x;
    strcpy(NODO_P(n2),string);

    return heap;
}


int heap_count(Heap heap){
    return heap->pos;
}

void heap_free(Heap heap){
    int i;
    for(i = 0; i < heap->pos; i++) {
        free(heap->produto[i]);
    }
    free(heap->quantidade);
    free(heap->custo);
    free(heap);
}