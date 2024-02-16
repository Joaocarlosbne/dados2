#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    LinkedList lista;
    init(&lista);
    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    enqueue(&lista, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=3;
    enqueue(&lista, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=4;
    enqueue(&lista, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=5;
    push(&lista, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=7;
    enqueue(&lista, aux);
    dequeue(&lista);
    printf("A lista está vazia? %d\n", isEmpty(&lista));
    printf("Primeiro elemento da lista: %d\n", *((int*)lista.first->data));
    apagar(&lista);
    printf("A lista está vazia? %d\n", isEmpty(&lista));

    return EXIT_SUCCESS;
}