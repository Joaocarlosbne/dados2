#include <stdio.h>
#include <stdlib.h>
#include "GeneralizedLinkedList.h"

int addAtom(Node **list, int atom){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    newNode->type = 0;
    newNode->atomList.atom = atom;
    newNode->next = *list;
    *list = newNode;
    return 1;
}

int addList(Node **list, Node **subList){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    newNode->type = 1;
    newNode->atomList.list = *subList;
    newNode->next = *list;
    *list = newNode;
    return 1;
}

void show(Node *list){
    if (list == NULL) {
        printf("()");
        return;
    }
    if (list->type == 0) {
        printf("%d", list->atomList.atom);
    } else {
        printf("(");
        show(list->atomList.list);
        printf(")");
    }
    if (list->next != NULL) {
        printf(" ");
        show(list->next);
    }
}

Node* head(Node *list) {
    if (list == NULL) {
        printf("Erro: a lista está vazia.\n");
        return NULL;
    }
    Node* copy = (Node*)malloc(sizeof(Node));
    if (copy == NULL) {
        printf("Erro: memória insuficiente.\n");
        return NULL;
    }if (copy == NULL) {
        printf("Erro: memória insuficiente.\n");
        return NULL;
    }
    *copy = *list;
    copy->next = NULL;
    return copy;
    return list->atomList.list;
}

Node* tail(Node *list) {
    if (list == NULL) {
        printf("Erro: a lista está vazia.\n");
        return NULL;
    }
    return list->next;
}

bool search(Node *list, int atom) {
    if (list == NULL) {
        return false;
    }
    if (list->type == 0) {
        if (list->atomList.atom == atom) {
            return true;
        } else {
            return search(list->next, atom);
        }
    } else {
        return search(list->atomList.list, atom) || search(list->next, atom);
    }
}

int depth(Node *list) {
    if (list == NULL) {
        return 0;
    }
    if (list->type == 0) {
        return 1 + depth(list->next);
    } else {
        int depthList = depth(list->atomList.list);
        int depthNext = depth(list->next);
        return depthList > depthNext ? 1 + depthList : 1 + depthNext;
    }
}