// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do TERMO DE BUSCA do texto (PALAVRA + PESO + TF-IDF) e suas funções

#include <string.h>

#include "../headers/TF-IDFList.h"

// Estrutura das palavras do texto
typedef struct searchTerm {
    char* wordChar;
    float weight;
    typeListTfIdf* listTfIdf;
} typeSearchTerm;

// Função para inicar
typeSearchTerm* startSearchTerm();
// Função para definir
void defineSearchTerm(typeSearchTerm* searchTerm, char* textWord);
// Função para imprimir
void printSearchTerm(typeSearchTerm searchTerm);