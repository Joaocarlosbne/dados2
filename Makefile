# Target principal para compilar e executar todos os programas
all: clear ola LinkedList Generalizada blockchain

# Compilar e executar o programa 'ola'
ola:
	@echo "Compilando o Programa Olá"
	@gcc ola.c -o ola
	@echo "tornando o arquivo executável"
	@chmod +x ola
	@echo "executando o programa olá"
	@./ola

# Limpar todos os binários
clear:
	@echo "Limpando os binários"
	@del /f /q ola.exe > NUL 2>&1
	@del /f /q LinkedList.exe > NUL 2>&1
	@del /f /q GeneralizedLinkedList.exe > NUL 2>&1
	@del /f /q blockchain.exe > NUL 2>&1

# Exibir ajuda
help:
	@echo "-ola- compila e executa o programa ola"
	@echo "-clear- limpa todos os binários"
	@echo "-all- clear + ola + LinkedList + Generalizada + blockchain"

# Compilar e executar o programa 'LinkedList'
LinkedList: clear
	@echo "Compilando LinkedListTest"
	@gcc LinkedList.h LinkedList.c LinkedListTest.c -o LinkedList
	@./LinkedList

# Compilar e executar o programa 'Generalizada'
Generalizada: clear
	@echo "Compilando GeneralizedLinkedListTest"
	@gcc GeneralizedLinkedList.h GeneralizedLinkedList.c GeneralizedLinkedListTest.c -o GeneralizedLinkedList
	@./GeneralizedLinkedList

# Compilar e executar o programa 'blockchain'
blockchain: clear
	@echo "Compilando o Blockchain"
	@gcc Blockchain.h Blockchain.c BlockchainTest.c sha-256.c -o blockchain
	@./blockchain
