all: clear ola

ola:
	@echo "Compilando o Programa Olá"
	@gcc ola.c -o ola
	@echo "tornando o arquivo executavel"
	@chmod +x ola
	@echo "executando o programa olá"
	@./ola

clear:
	@echo "Limpando os binarios"
	@rm -f ola > /dev/null 2>&1
	@rm -f LinkedList > /dev/null 2>&1
	@rm -f GeneralizedLinkedList > /dev/null 2>&1
help:
	@echo "-ola- compila e executa o programa ola"
	@echo "-clear- limpa todos os binarios"
	@echo "-all- clear + ola"
#git lol para ver o grafico/commits
#git rm -nome do arquivo- pra excluir um arquivo local e servidor
LinkedList: clear
	@echo "compilando listateste"
	@gcc LinkedList.h LinkedList.c LinkedListTest.c -o LinkedList
	@./LinkedList
Generalizada: clear
	@echo "compilando listateste"
	@gcc GeneralizedLinkedList.h GeneralizedLinkedList.c GeneralizedLinkedListTest.c -o GeneralizedLinkedList
	@./GeneralizedLinkedList