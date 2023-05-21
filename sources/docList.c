// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/docList.h"

void startDocList(typeDocList* docList) {
    docList -> firstCell = (typeDocCell*) malloc(sizeof(typeDocCell));
    docList -> firstCell -> nextCell = NULL;
    docList -> lastCell = docList -> firstCell;
    docList -> nDocs = 0;
}

void insertDocList(typeDocList* docList, char* docName, int idDoc) {
    docList -> lastCell -> nextCell = (typeDocCell*) malloc(sizeof(typeDocCell));
    docList -> lastCell = docList -> lastCell -> nextCell;
    fillDoc(docList, docName, idDoc);
    docList -> lastCell -> nextCell = NULL;
    docList -> nDocs++;
}

void fillDoc(typeDocList* docList, char* docName, int idDoc) {
    docList -> lastCell -> itemDoc.docName = (char*) malloc(sizeof(char) * (strlen(docName) + 1));
    strcpy(docList -> lastCell -> itemDoc.docName, docName);
    docList -> lastCell -> itemDoc.idDoc = idDoc;
    docList -> lastCell -> itemDoc.nWordle = 0;
}

void docReset(typeDocList* docList) {
    typeDocPointer auxReset = docList -> firstCell -> nextCell;
    while (auxReset != NULL) {
        auxReset -> itemDoc.rDoc = 0;
        auxReset = auxReset -> nextCell;
    }
}

typeDocPointer findDoc(typeDocList docList, int idDoc) {
    typeDocPointer auxFind = docList.firstCell -> nextCell;
    while (auxFind != NULL) {
        if (auxFind -> itemDoc.idDoc == idDoc) {
            return auxFind;
        }
        auxFind = auxFind -> nextCell;
    }
    return NULL;
}

typeDocPointer findDocByRev(typeDocList docList, double rDoc) {
    typeDocPointer auxFind = docList.firstCell -> nextCell;
    while (auxFind != NULL) {
        if (auxFind -> itemDoc.rDoc == rDoc) {
            return auxFind;
        }
        auxFind = auxFind -> nextCell;
    }
    return NULL;
}

void printDocList(typeDocList docList) {
    typeDocPointer auxPrint = docList.firstCell -> nextCell;
    while (auxPrint != NULL) {
        printf("docName: %s\n", auxPrint -> itemDoc.docName);
        printf("idDoc: %d\n", auxPrint -> itemDoc.idDoc);
        printf("rDoc: %lf\n", auxPrint -> itemDoc.rDoc);
        printf("nWordle: %d\n\n", auxPrint -> itemDoc.nWordle);
        auxPrint = auxPrint -> nextCell;
    }
}