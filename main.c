#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

#define MAX_WORDS 1000
#define WORD_LENGTH 100

void loadWords(const char* filename, char words[MAX_WORDS][WORD_LENGTH], int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    int i = 0;
    while (fgets(words[i], WORD_LENGTH, file) && i < MAX_WORDS) {
        words[i][strcspn(words[i], "\n")] = '\0'; // Remove newline character
        i++;
    }
    *wordCount = i;
    fclose(file);
}

void printWord(void *data) {
    printf("%s ", (char*)data);
}

int main() {
    HashStruct hashStruct;
    char words[MAX_WORDS][WORD_LENGTH];
    int wordCount;
    
    loadWords("ListaDePalavrasPT.txt", words, &wordCount);
    initHash(&hashStruct);

    for (int i = 0; i < wordCount; i++) {
        put(&hashStruct, words[i], words[i], (compare)strcmp);
    }

    showHashStruct(&hashStruct, printWord);

    return 0;
}
