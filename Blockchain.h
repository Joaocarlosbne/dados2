#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

// Estrutura de um bloco na blockchain
typedef struct Block {
    unsigned int index;
    char* previousHash;
    struct Block* previousBlock;
    unsigned long timestamp;
    float data;
    char* hash;
} Block;

// Estrutura da blockchain
typedef struct Blockchain {
    Block *genesisBlock;
    Block *latestBlock;
} Blockchain;

// Funções da Blockchain
void initBlockchain(Blockchain *blockchain);
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data);
char* calculateBlockHash(Block *block);
Block* generateNextBlock(Blockchain *blockchain, float data);
Block* getLatestBlock(Blockchain *blockchain);
bool isValidNewBlock(Block* newBlock, Block* previousBlock);
bool isBlockchainValid(Blockchain *blockchain);
int addBlock(Blockchain *blockchain, Block *newBlock);

#endif
    