// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação TF-IDF (Term frequency – Inverse Document Frequency)

#include <stdio.h>
#include <stdlib.h>

typedef struct tfIdf {
    int qtde; // Quantaide
    int idDoc; // Documentos
    float weight; // Peso
    float imp; // Relevância (Cálculado com base no Peso)
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