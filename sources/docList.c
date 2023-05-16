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

typeDocPointer findDocByRev(typeDocList docList, float rDoc) {
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
        printf("Texto %d (%s)\n", auxPrint -> itemDoc.idDoc, auxPrint -> itemDoc.docName);
        auxPrint = auxPrint -> nextCell;
    }
}


// void rDocPrint(typeDocList docList) {
//     int nDocs = docList.nDocs;
//     typeDoc* newDocList = (typeDoc*) malloc(nDocs * sizeof(typeDoc));
//     copyDocList(&docList, newDocList, nDocs);
//     selectionSort(newDocList, nDocs);
//     for (int i = 0; i < nDocs; i++) {
//         printf("Text %d (%s)\n", newDocList[i].idDoc, newDocList[i].docName);
//     }
//     free(newDocList);
// }

// void copyDocList(typeDocList* docList, typeDoc* newDocList, int size) {
//     int i = 0;
//     typeDocPointer aux = docList -> firstCell -> nextCell;
//     while (aux != NULL) {
//         newDocList[i] = aux -> itemDoc;
//         i++;
//         aux = aux -> nextCell;
//     }
// }

// void selectionSort(typeDoc* newDocList, int size) {
//     typeDoc aux;
//     int index;
//     for (int i = 0; i < size - 1; i++) {
//         index = i;
//         for (int j = index + 1; j < size; j++) {
//             if (newDocList[j].rDoc > newDocList[index].rDoc) {
//                 index = j;
//             }
//         }
//         aux = newDocList[index];
//         newDocList[index] = newDocList[i];
//         newDocList[i] = aux;
//     }
// }