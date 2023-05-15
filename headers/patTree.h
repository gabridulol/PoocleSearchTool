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
    typeNode InnExt;
    union {
        struct {
            int index;
            char charIndex;
            typePatPointer left;
            typePatPointer right;
        } typeInnNode;
        typeWordle wordle;
    } typeExtNode;
} typePatNode;

// ***********PASSAR docList como parâmetro*******************
// Função para iniciar a árvore PATRICIA
void startPatTree(typePatPointer* patTree);
//Funções para verificar se nó da PATRICIA é externo
int isExt(typePatPointer patTree);
// Função para ????
char bit(int diffIndex, typeWordle* wordleData);


//Funções para criar nós interno e externo da ávore PATRICIA
typePatPointer startNodeInn(typePatPointer* left, typePatPointer* right, int index, char charIndex);
typePatPointer starNodeExt(typeWordle* wordleData);


// //Função de busca
// void searchPat(typePatPointer patty, char searchWord);
// //Funções de inserção
// typePatPointer insertBetween(typePatPointer *patty, typeSearchTerm *data, int index);
// typePatPointer insert(typePatPointer *patty, typeSearchTerm *data);
// //Função de impressão da PATRICIA
// void printPat(typePatPointer patty);