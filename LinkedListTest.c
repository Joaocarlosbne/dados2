#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    LinkedList lista;
    init(&lista);
    printf("%d",isEmpty(&lista));
    return EXIT_SUCCESS;
}