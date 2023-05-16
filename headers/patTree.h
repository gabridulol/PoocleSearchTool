// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação de PATRICIA e suas funções

#include "../headers/wordle.h"

typedef enum {
    inn, ext
} typeNode;
typedef struct typePatNode* typePatPointer;
typedef struct typePatNode {
    typeNode typeInnExt;
    union {
        struct {
            int index;
            char charIndex;
            typePatPointer left;
            typePatPointer right;
        } typeInnNode;
        typeWordle *wordleData;
    } typeExtNode;
} typePatNode;

// Função para iniciar a árvore PATRICIA
void startPatTree(typePatPointer* patTree);
//Funções para verificar se o nó da PATRICIA é externo
int isExt(typePatPointer patTree);
// Função para retornar o caractere que difere
char bit(int diffIndex, typeWordle* wordleData);
//Função para criar nó interno da ávore PATRICIA
typePatPointer startNodeInn(typePatPointer* left, typePatPointer* right, int index, char charIndex);
// Função para criar nó externo da árvore PATRICIA
typePatPointer startNodeExt(char* textWord, int idDoc);

// Função de de busca de um termo na árvore PATRICÍA
// int searchPatTree(typePatPointer patTree, char* searchTerm);
// Função de busca de um nó na árvore PATRÍCIA
// typePatPointer searchNode(typePatPointer patTree, typeWordle wordleData);

// Função para inserir na árvore PATRICIA
typePatPointer insertPatTree(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc);
typePatPointer insertBetween(typePatPointer* patTree, typeDocList* docList, typeWordle wordleData, int i, int idDoc, char diferentLetter);

// Função de impressão da árvore PATRICIA em ordem alfabética
void printPatTree(typePatPointer patTree);