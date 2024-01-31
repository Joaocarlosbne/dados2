all: clear ola

ola:
	@echo "Compilando o Programa Olá"
	@gcc ola.c -o ola
	@echo "tornando o arquivo executavel"
	@chmod +x ola
	@echo "executando o programa olá"
	@./ola

clear:
	@echo "Limpando o ola binario"
	@rm ola

help:
	@echo "-ola- compila e executa o programa ola"
	@echo "-clear- limpa todos os binarios"
	@echo "-all- clear + ola"
