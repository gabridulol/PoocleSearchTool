// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Tarefas que a máquina de buscas precisa realizar
// 1 - Receber arquivo "entradas.txt"
// 2 - Criar índice invertido
// 3 - Imprimir índice invertido
// 4 - Buscar por textos com base em termos de busca
// 5 - MENU
//      a) receber o arquivo de entrada com os
//      textos a serem indexados;
//      b) construir o índice invertido, a partir dos textos de entrada,
//      usando o TAD árvore PATRICIA;
//      c) imprimir o índice invertido, contendo as palavras em
//      ordem alfabética, uma por linha, com suas respectivas listas de ocorrências;
//      d) realizar buscas por um ou mais termo(s) de busca, no índice construído,
//      apresentando os arquivos ordenados por relevância.

// Implementação do Buscador Poocle  e suas funções

#include "../headers/fileManagement.h"
#include "../math.h"

// Função que recebe o arquivo de entrada
void getFile(typeDocList* docList);
// Função que constrói o índice invertido
void buildInvertedIndex();
// Função que imprime o índice invertido
void printInvertedIndex();
// Função que realiza busca com base em termos de busca
void searchTool();
