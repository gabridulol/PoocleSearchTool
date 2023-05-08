// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include <stdio.h>
#include <stdlib.h>

typedef struct tfIdf {
    int qtde;
    int idDoc;
    float weight;
    float erpkmkr; // alguma coisa importante
} typeTfIdf;

typedef struct typeCell* typeLkPointer;
typedef struct typeCell {
    typeTfIdf item;
    typeLkPointer nextCell;
} typeCell;
typedef struct LinkedList {
    typeLkPointer firstCell;
    typeLkPointer lastCell;
} typeLinkedList;

void startLinkedList(typeLinkedList* linkedList);
void insertLinkedList(typeLinkedList* linkedList, typeTfIdf itemData);
void printLinkedList(typeLinkedList linkedList);