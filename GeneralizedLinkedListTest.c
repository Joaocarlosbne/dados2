#include <stdio.h>
#include <stdlib.h>
#include "GeneralizedLinkedList.h"

int main() {
    Node *list = NULL;
    Node *subList = NULL;
    addAtom(&subList, 1);
    addAtom(&subList, 2);
    addList(&list, &subList);
    addAtom(&list, 3);
    addAtom(&list, 4);
    addAtom(&list, 5);
    addAtom(&list, 6);
    addAtom(&list, 7);
    addAtom(&list, 8);
    addAtom(&list, 9);
    addAtom(&list, 10);
    show(list);
    printf("\n");
    return 0;
}