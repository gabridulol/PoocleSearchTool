// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/TF-IDF.h"

void startListTfIdf(typeListTfIdf* listTfIdf) {
    listTfIdf -> firstCell = (typeCell*) malloc(sizeof(typeCell));
    listTfIdf -> firstCell -> nextCell = NULL;
    listTfIdf -> lastCell = listTfIdf -> firstCell;
}

void insertListTfIdf(typeListTfIdf* listTfIdf, int qtde, int idDoc) {
    listTfIdf -> lastCell -> nextCell = (typeCell*) malloc(sizeof(typeCell));
    listTfIdf -> lastCell = listTfIdf -> lastCell -> nextCell;
    listTfIdf -> lastCell -> itemTfIdf.qtde = qtde;
    listTfIdf -> lastCell -> itemTfIdf.idDoc = idDoc;
    listTfIdf -> lastCell -> nextCell = NULL;
}

void printListTfIdf(typeListTfIdf listTfIdf) {
    typePointer auxPrint;
    auxPrint = listTfIdf.firstCell -> nextCell;
    while (auxPrint != NULL) {
        printf("<%d, %d>", auxPrint -> itemTfIdf.qtde, auxPrint -> itemTfIdf.idDoc);
        auxPrint = auxPrint -> nextCell;
    }
}