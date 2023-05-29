// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação da wordle (palavra + índice invertido) e suas funções

#include "../headers/index.h"

// Estrutura da Wordle
typedef struct wordle {
    char* wordChar; // Palavra
    typeIndexList* indexList; // Lista de índices
} typeWordle;

// Função para iniciar uma wordle
typeWordle startWordle();
// Função para definir uma wordle
void fillWordle(typeWordle* wordle, char* textWord, int idDoc);
// Função para imprimir uma wordle
void printWordle(typeWordle wordle);