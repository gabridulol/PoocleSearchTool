#include <stdio.h>
#include <stdlib.h>

typedef struct tfIdf {
    int qtde;
    int idDoc;
    float weight;
    float 
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