#include "Blockchain.h"
#include "sha-256.h"

// Função auxiliar para converter o hash em string
static void hash_to_string(char string[65], const uint8_t hash[32]) {
    size_t i;
    for (i = 0; i < 32; i++) {
        // Montar uma string com 64 caracteres hexadecimais
        string += sprintf(string, "%02x", hash[i]); // 02x hexadecimal em 2 caracteres
    }
}

// Função para calcular o hash de um bloco
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data) {
    char input[1024];
    sprintf(input, "%i%s%lu%.8f", index, previousHash, timestamp, data);
    uint8_t hash[32];
    char *hash_string = (char*)malloc(sizeof(char) * 65);
    calc_sha_256(hash, input, strlen(input));
    hash_to_string(hash_string, hash);
    return hash_string;
}

// Função para calcular o hash de um bloco a partir de sua estrutura
char* calculateBlockHash(Block *block) {
    return calculateHash(block->index, block->previousHash, block->timestamp, block->data);
}

// Inicializa a blockchain com o bloco gênesis
void initBlockchain(Blockchain *blockchain) {
    Block *genesisBlock = (Block*)malloc(sizeof(Block));
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->previousBlock = NULL;
    genesisBlock->timestamp = time(NULL);
    genesisBlock->data = 1000000; // Valor arbitrário para o bloco gênesis
    genesisBlock->hash = calculateHash(genesisBlock->index, genesisBlock->previousHash, genesisBlock->timestamp, genesisBlock->data);
    blockchain->genesisBlock = genesisBlock;
    blockchain->latestBlock = genesisBlock;
}

// Gera o próximo bloco na blockchain
Block* generateNextBlock(Blockchain *blockchain, float data) {
    Block *previousBlock = getLatestBlock(blockchain);
    Block *newBlock = (Block*)malloc(sizeof(Block));
    newBlock->data = data;
    newBlock->previousHash = previousBlock->hash;
    newBlock->index = previousBlock->index + 1;
    newBlock->timestamp = time(NULL);
    newBlock->hash = calculateBlockHash(newBlock);
    return newBlock;
}

// Retorna o bloco mais recente na blockchain
Block* getLatestBlock(Blockchain *blockchain) {
    return blockchain->latestBlock;
}

// Verifica se um novo bloco é válido comparado ao bloco anterior
bool isValidNewBlock(Block* newBlock, Block* previousBlock) {
    if (previousBlock->index + 1 != newBlock->index) {
        return false;
    } else if (strcmp(previousBlock->hash, newBlock->previousHash) != 0) {
        return false;
    } else if (strcmp(calculateBlockHash(newBlock), newBlock->hash) != 0) {
        return false;
    }
    return true;
}

// Verifica se a blockchain é válida
bool isBlockchainValid(Blockchain *blockchain) {
    Block *aux = getLatestBlock(blockchain);
    while (aux != blockchain->genesisBlock) {
        if (!isValidNewBlock(aux, aux->previousBlock))
            return false;
        aux = aux->previousBlock;
    }
    return true;
}

// Adiciona um novo bloco na blockchain
int addBlock(Blockchain *blockchain, Block *newBlock) {
    if (isValidNewBlock(newBlock, getLatestBlock(blockchain))) {
        newBlock->previousBlock = getLatestBlock(blockchain);
        blockchain->latestBlock = newBlock;
        return 1;
    }
    return -1;
}
