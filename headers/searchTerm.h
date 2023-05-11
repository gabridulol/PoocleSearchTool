// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do TERMO DE BUSCA do texto (PALAVRA + PESO + TF-IDF) e suas funções

#include "../headers/TF-IDF.h"

// Estrutura do TERMO DE BUSCA
typedef struct searchTerm {
    char* wordChar;
    float weight;
    typeListTfIdf* listTfIdf;
} typeSearchTerm;

// Função para iniciar um TERMO DE BUSCA
typeSearchTerm* startSearchTerm();
// Função para definir um TERMO DE BUSCA
void defineSearchTerm(typeSearchTerm* searchTerm, char* textWord, int qtde, int idDoc);
// Função para imprimir um TERMO DE BUSCA
void printSearchTerm(typeSearchTerm searchTerm);