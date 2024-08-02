# Estrutura de dados 2
repositorio dados2




------------------------------------------------------
Projeto Espelhamento, Alunos: João Carlos, Rodrigo henrique

Descrição do Projeto
Título: Visualização de Colisões em Tabelas Hash com Palavras da Língua Portuguesa

Objetivo:
O objetivo deste projeto é desenvolver e visualizar a dispersão de colisões em tabelas hash utilizando um conjunto de palavras da língua portuguesa. A visualização é feita na forma de uma matriz de cores, onde diferentes tonalidades indicam pontos de menor e maior colisão. O projeto visa comparar diferentes funções de hash para identificar a mais adequada para uma boa dispersão dos dados.

Componentes do Projeto:

Lista de Palavras:

Um arquivo de texto (ListaDePalavrasPT.txt) contendo uma lista de palavras em português que serão utilizadas como chaves na tabela hash.
Implementação da Tabela Hash:

Estruturas de Dados:
HashStruct: Estrutura principal da tabela hash, utilizando listas duplamente encadeadas para gerenciar colisões.
DoublyLinkedList: Implementação de listas duplamente encadeadas para armazenar palavras que colidem em um mesmo índice da tabela hash.
Função de Hash:
hash(char *key): Função que calcula o índice hash para uma dada palavra, somando os valores ASCII dos caracteres na palavra e aplicando módulo MAX.
Visualização das Colisões:

Geração da Matriz PPM:
generatePPM(int hashTable[MAX], const char* filename): Função que cria uma imagem PPM representando a matriz de colisões, onde diferentes tons de verde indicam a densidade de colisões em cada índice da tabela hash.
Parâmetros de Visualização:
MATRIX_SIZE: Define o tamanho da matriz quadrada usada para visualização.
Execução do Projeto:

Compilação:
Utiliza o compilador gcc para compilar os arquivos fonte (main.c, hash.c, DoublyLinkedList.c).
Execução:
Gera e executa um programa (hash_program.exe) que carrega a lista de palavras, insere as palavras na tabela hash, conta as colisões e gera a visualização em um arquivo PPM (hash_collisions.ppm).
Resumo do Código:

main.c:

Carrega as palavras da lista.
Inicializa a tabela hash e insere as palavras.
Conta as colisões em cada índice.
Gera a matriz PPM para visualizar as colisões.
hash.c:

Implementa as funções de manipulação da tabela hash, incluindo a função de hash.
DoublyLinkedList.c:

Implementa as funções de manipulação das listas duplamente encadeadas.
Uso:
Este projeto é útil para estudantes e desenvolvedores que desejam entender o comportamento de diferentes funções de hash e visualizar a distribuição de colisões, ajudando a escolher ou desenvolver funções de hash mais eficientes.

Addons: Image preview para a visualização do arquivo PPM.

A pasta imagem ppm contém imagens com diferentes tipos de calculo para o hash, linear, sem peso e exponencial.