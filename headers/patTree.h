// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação da árvore PATRICIA e suas funções

#include "../headers/wordle.h"
#include "../headers/docList.h"

// Estrutura nó de tipo interno ou externo
typedef enum {
    inn, ext // Interno (0) e Externo (1)
} typeNode;

// Estrutura do nó da árvore PATRICIA
typedef struct typePatNode* typePatPointer;
typedef struct typePatNode {
    typeNode innext; // Interno (0) ou Externo (1)
    union {
        struct {
            int index; // Índice que difere
            char charIndex; // Caractere que difere
            typePatPointer left;
            typePatPointer right;
        } typeInnNode; // Nó interno da árvore PATRICIA
        typeWordle wordleData; // Wordle
    } typeExtNode; // Nó externo da árvore PATRICÍA
} typePatNode;

// Função para iniciar a árvore PATRICIA
void startPatTree(typePatPointer* patTree);
// Funções para verificar o nó da árvore PATRICIA
int isExt(typePatPointer patTree);
// Função para retornar o caractere que difere
char bit(int index, char* textWord);
//Função para iniciar nó interno da ávore PATRICIA
typePatPointer startNodeInn(typePatPointer* left, typePatPointer* right, int index, char charIndex);
// Função para inciar nó externo da árvore PATRICIA
typePatPointer startNodeExt(typeDocList docList, char* textWord, int idDoc);
// Função para inserir na árvore PATRICIA
typePatPointer insertPatTree(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc);
typePatPointer insertBetween(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc, int i, char diffChar);
// Função de busca de um nó na árvore PATRICIA
typePatPointer findNode(typePatPointer patTree, char* searchWordle);
// Função para verificar se existe a palavra na árvore PATRICIA
int searchPatTree(typePatPointer patTree, char* searchWordle);
// Função de impressão da árvore PATRICIA em ordem alfabética
void printPatTree(typePatPointer patTree);