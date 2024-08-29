#include <stdio.h>
#include "Blockchain.h"

int main() {
    // Inicializa a blockchain
    Blockchain blockchain;
    initBlockchain(&blockchain);

    // Exibe informações sobre o bloco gênesis
    printf("Hash do Bloco Genesis: %s\n", blockchain.genesisBlock->hash);
    printf("Timestamp do Bloco Genesis: %lu\n", blockchain.genesisBlock->timestamp);

    // Cria e adiciona um segundo bloco à blockchain
    Block *newBlock2 = generateNextBlock(&blockchain, 80.0);
    addBlock(&blockchain, newBlock2);
    printf("Hash do Bloco 2: %s\n", newBlock2->hash);

    // Cria e adiciona um terceiro bloco à blockchain
    Block *newBlock3 = generateNextBlock(&blockchain, 250.0);
    addBlock(&blockchain, newBlock3);
    printf("Hash do Bloco 3: %s\n", newBlock3->hash);

    // Cria e adiciona um quarto bloco à blockchain
    Block *newBlock4 = generateNextBlock(&blockchain, 500.0);
    addBlock(&blockchain, newBlock4);
    printf("Hash do Bloco 4: %s\n", newBlock4->hash);

    // Verifica a validade dos blocos na blockchain
    printf("O Bloco 2 eh valido? %i\n", isValidNewBlock(newBlock2, blockchain.genesisBlock));
    
    // Verifica a validade da blockchain como um todo
    printf("A Blockchain eh valida? %i\n", isBlockchainValid(&blockchain));

    // Exibe o índice do último bloco na blockchain
    printf("indice do ultimo Bloco: %u\n", blockchain.latestBlock->index);

    return 0;
}
