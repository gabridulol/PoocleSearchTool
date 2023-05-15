// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/index.h"

void startIndexList(typeIndexList* indexList) {
    indexList -> firstCell = (typeIndexCell*) malloc(sizeof(typeIndexCell));
    indexList -> firstCell -> nextCell = NULL;
    indexList -> lastCell = indexList -> firstCell;
}

void insertIndexList(typeIndexList* indexList, int idDoc) {
    typeIndexPointer index = findIdDoc(*indexList, idDoc);
    if (index != NULL) {
        index -> itemIndex.qtde++;
        return;
    }
    indexList -> lastCell -> nextCell = (typeIndexCell*) malloc(sizeof(typeIndexCell));
    indexList -> lastCell = indexList -> lastCell -> nextCell;
    indexList -> lastCell -> itemIndex.qtde = 1;
    indexList -> lastCell -> itemIndex.idDoc = idDoc;
    indexList -> lastCell -> nextCell = NULL;
}

typeIndexPointer findIdDoc(typeIndexList indexList, int idDoc) {
    typeIndexPointer auxFind = indexList.firstCell -> nextCell;
    while (auxFind != NULL) {
        if (auxFind -> itemIndex.idDoc == idDoc) {
            return auxFind;
        }
        auxFind = auxFind -> nextCell;
    }
    return NULL;
}

void printIndexList(typeIndexList indexList) {
    typeIndexPointer auxPrint = indexList.firstCell -> nextCell;
    while (auxPrint != NULL) {
        printf("<%d, %d>\n", auxPrint -> itemIndex.qtde, auxPrint -> itemIndex.idDoc);
        auxPrint = auxPrint -> nextCell;
    }
}