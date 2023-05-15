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
        typeWordle data;
    } typeExtNode;
} typePatNode;

// //Inicialização da PATRICIA ***********PASSAR docList como parâmetro*******************
// void startPatty(typePatPointer *patty);
// //Funções auxiliares
// int ifNodeExt(typePatPointer patty); //Verifica se o node eh externo
// char Bit(int indexDiferentLetter, typeSearchTerm *data);//Retorna a i-esima letra que difere
// //...
// //Funções para criações de node
// typePatPointer startNodeInn(typePatPointer *left, typePatPointer *right, int index, char charindex);
// typePatPointer starNodeExt(typeSearchTerm *data);
// //Função de busca
// void searchPat(typePatPointer patty, char searchWord);
// //Funções de inserção
// typePatPointer insertBetween(typePatPointer *patty, typeSearchTerm *data, int index);
// typePatPointer insert(typePatPointer *patty, typeSearchTerm *data);
// //Função de impressão da PATRICIA
// void printPat(typePatPointer patty);