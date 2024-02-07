#include <stdbool.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list) {
  list->first=NULL;
  list->size=0;
}

bool isEmpty(LinkedList *list){
    return (list->size == 0);
}

int enqueue(LinkedList *list, void *data{
    Node *newnode = (Node*)malloc(sizeof(Node));
    if (*newnode = )
}