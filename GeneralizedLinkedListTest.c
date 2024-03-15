#include <stdio.h>
#include <stdlib.h>
#include "GeneralizedLinkedList.h"

int main() {
    Node *list = NULL;
    Node *subList = NULL;

    // Testando a função addAtom
    printf("Adicionando átomos à subLista...\n");
    addAtom(&subList, 1);
    addAtom(&subList, 2);
    show(subList);
    printf("\n");

    // Testando a função addList
    printf("Adicionando subLista à lista...\n");
    addList(&list, &subList);
    show(list);
    printf("\n");

    // Testando a função addAtom na lista
    printf("Adicionando mais átomos à lista...\n");
    addAtom(&list, 3);
    addAtom(&list, 4);
    show(list);
    printf("\n");

    // Testando a função head
    printf("Obtendo a cabeça da lista...\n");
    Node* listHead = head(list);
    show(listHead);
    printf("\n");

    // Testando a função tail
    printf("Obtendo a cauda da lista...\n");
    Node* listTail = tail(list);
    show(listTail);
    printf("\n");

    // Testando a função search
    printf("Procurando o átomo 2 na lista...\n");
    bool found = search(list, 2);
    printf(found ? "Encontrado\n" : "Não encontrado\n");

    // Testando a função depth
    printf("Calculando a profundidade da lista...\n");
    int listDepth = depth(list);
    printf("Profundidade: %d\n", listDepth);

    return 0;
}