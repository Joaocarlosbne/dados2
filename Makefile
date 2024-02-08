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
	@rm ola
	@rm LinkedList

help:
	@echo "-ola- compila e executa o programa ola"
	@echo "-clear- limpa todos os binarios"
	@echo "-all- clear + ola"
#git lol para ver o grafico/commits
#git rm -nome do arquivo- pra excluir um arquivo local e servidor
LinkedList:
	@echo "compilando listateste"
	@gcc LinkedList.h LinkedList.c LinkedListTest.c -o LinkedList
	@./LinkedList