// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/TF-IDFDocument.h"

void startDocList(typeDocList* docList) {
    docList -> firstCell = (typeDocCell*) malloc(sizeof(typeDocCell));
    docList -> firstCell = (typeDocCell*) malloc(sizeof(typeDocCell));
    docList -> firstCell -> nextCell = NULL;
    docList -> lastCell = docList -> firstCell;
}

void insertDocList(typeDocList* docList, char* docName, int idDoc) {
    docList -> lastCell -> nextCell = (typeDocCell*) malloc(sizeof(typeDocCell));
    docList -> lastCell = docList -> lastCell -> nextCell;
    docList -> lastCell -> itemDoc.docName = (char*) malloc(sizeof(char) * (strlen(docName) + 1));
    strcpy(docList -> lastCell -> itemDoc.docName, docName);
    docList -> lastCell -> itemDoc.idDoc = idDoc;
    docList -> lastCell -> nextCell = NULL;
}

void printDocList(typeDocList docList) {
    typeDocPointer auxPrint = docList.firstCell -> nextCell;
    while (auxPrint != NULL) {
        printf("Texto %d (%s)\n", auxPrint -> itemDoc.idDoc, auxPrint -> itemDoc.docName);
        auxPrint = auxPrint -> nextCell;
    }
}