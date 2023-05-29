// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do Poocle Search Tool e suas funções

#include "../headers/math.h"

// Função que recebe o arquivo de entrada
void getFile(typeDocList* docList);
// Função que constrói o índice invertido
void buildInvertedIndex(typePatPointer* patTree, typeDocList* docList);
// Função que imprime o índice invertido
void printInvertedIndex(typePatPointer* patTree);
// Função que realiza busca com base em termos de busca
void searchTool(typePatPointer* patTree, typeDocList* docList, char* searchLine);