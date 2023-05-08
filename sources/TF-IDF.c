// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/TF-IDF.h"

void startLinkedList(typeLinkedList* linkedList) {
    linkedList -> firstCell = (typeCell*) malloc(sizeof(typeCell));
    linkedList -> firstCell -> nextCell = NULL;
    linkedList -> lastCell = linkedList -> firstCell;
}

void insertLinkedList(typeLinkedList* linkedList, typeTfIdf itemData) {
    linkedList -> lastCell -> nextCell = (typeCell*) malloc(sizeof(typeCell));
    linkedList -> lastCell = linkedList -> lastCell -> nextCell;
    linkedList -> lastCell -> item = itemData;
    linkedList -> lastCell -> nextCell = NULL;
}

void printLinkedList(typeLinkedList linkedList) {
    typeLkPointer auxPrint;
    auxPrint = linkedList.firstCell -> nextCell;
    while (auxPrint != NULL) {
        printf("<%d, %d>", auxPrint -> item.qtde, auxPrint -> item.idDoc);
        auxPrint = auxPrint -> nextCell;
    }
}