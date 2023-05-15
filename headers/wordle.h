// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do TERMO DE BUSCA do texto (PALAVRA + PESO + TF-IDF) e suas funções

#include "../headers/index.h"

// Estrutura do TERMO DE BUSCA
typedef struct wordle {
    char* wordChar;
    typeIndexList* indexList;
} typeWordle;

// Função para iniciar um TERMO DE BUSCA
typeWordle* startSearchTerm();
// Função para definir um TERMO DE BUSCA
void defineWordle(typeWordle* wordle, char* textWord, int idDoc);
// Função para imprimir um TERMO DE BUSCA
void printWordle(typeWordle wordle);