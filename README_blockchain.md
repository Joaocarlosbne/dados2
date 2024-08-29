Estrutura de Dados 2
Repositório dados2

Projeto Blockchain, Alunos: João Carlos, Rodrigo Henrique

Implementação de uma Blockchain Simples em C
Descrição
Este projeto visa implementar uma blockchain básica em C, onde cada bloco da cadeia contém um índice, um hash do bloco anterior, um timestamp, dados e seu próprio hash. A blockchain permite verificar a integridade de seus blocos, garantindo que os dados não foram alterados após sua criação. Esta implementação é simples e não inclui conceitos avançados como Proof of Work ou transações distribuídas, focando apenas na estrutura de dados da blockchain.

Estrutura do Projeto
Blockchain.h e Blockchain.c: Definição e implementação das estruturas e funções principais da blockchain.
sha-256.h e sha-256.c: Implementação da função de hash SHA-256 usada para garantir a integridade dos blocos.
BlockchainTest.c: Arquivo de teste que inicializa a blockchain, adiciona blocos, e verifica a validade da cadeia.
Makefile: Arquivo Make para compilar e executar o projeto.
Funcionamento da Blockchain
Estrutura de um Bloco
Cada bloco na blockchain é composto por:

index: Identificador único do bloco.
previousHash: Hash do bloco anterior na cadeia.
timestamp: Registro de data e hora em que o bloco foi criado.
data: Dados armazenados no bloco.
hash: Hash do bloco atual, calculado a partir de seus dados.
Funções Implementadas
initBlockchain: Inicializa a blockchain com um bloco gênesis.
generateNextBlock: Gera um novo bloco com base no bloco anterior.
addBlock: Adiciona um novo bloco à blockchain após validar sua integridade.
isValidNewBlock: Verifica a validade de um novo bloco em relação ao anterior.
isBlockchainValid: Verifica se a blockchain como um todo é válida.
Estrutura do Código de Teste
O código de teste (BlockchainTest.c) realiza as seguintes operações:

Inicializa a blockchain.
Adiciona quatro blocos à cadeia.
Exibe o hash de cada bloco.
Verifica a integridade da blockchain.
Configuração e Execução
Requisitos
GCC (GNU Compiler Collection)
Ambiente de desenvolvimento configurado para C (como MinGW para Windows)
Compilação
Para compilar o programa, use o seguinte comando:

gcc Blockchain.c BlockchainTest.c sha-256.c -o blockchain

Execução
Para executar o programa, use o seguinte comando:

./blockchain   # No Linux/Mac
blockchain.exe # No Windows

