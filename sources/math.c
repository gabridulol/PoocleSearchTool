// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/math.h"


void mathRelevance(typePatPointer* patTree, typeDocList* docList, char* searchWordle) {
    typeDocPointer auxDoc = docList -> firstCell -> nextCell;
    while (auxDoc != NULL) {
        auxDoc -> itemDoc.rDoc += mathDocRelevance(patTree, auxDoc, searchWordle, docList -> nDocs);
        auxDoc = auxDoc -> nextCell;
    }
}

double mathDocRelevance(typePatPointer* patTree, typeDocPointer currentDoc, char* searchWordle, int nDocs) {
    typePatPointer auxTree = findNode(*patTree, searchWordle);
    if (auxTree == NULL) {
        return 0;
    }
    typeIndexPointer auxIndex = findIdDoc(*auxTree -> typeExtNode.wordleData.indexList, currentDoc -> itemDoc.idDoc);
    if (auxIndex == NULL) {
        return 0;
    }
    else {
        double wordleWeight = mathWordleWeight(auxTree, auxIndex, currentDoc -> itemDoc.idDoc, nDocs);
        return ((1.0 / currentDoc -> itemDoc.nWordle) * wordleWeight);
    }
}

double mathWordleWeight(typePatPointer auxTree, typeIndexPointer auxIndex, int idDoc, int nDocs) {
    int inDoc = sizeIndexList(*auxTree -> typeExtNode.wordleData.indexList);
    int qtde = auxIndex -> itemIndex.qtde;
    return (qtde * (log10(nDocs) / inDoc));
}

void printDocByRev(typeDocList* docList) {
    typeDocPointer auxDoc = docList -> firstCell -> nextCell;
    double array[docList -> nDocs];
    int count = 0;
    typeDocPointer auxPrint;
    while (auxDoc != NULL) {
        array[count] = auxDoc -> itemDoc.rDoc;
        count++;
        auxDoc = auxDoc -> nextCell;
    }
    qsort(array, docList -> nDocs, sizeof(double), cmp);
    count = 0;
    while (count < docList -> nDocs) {
        if (array[count] != 0) {
            auxPrint = findDocByRev(*docList, array[count]);
            printf("Text %d (%s)\n", auxPrint -> itemDoc.idDoc, auxPrint -> itemDoc.docName);
        }
        count++;
    }
    docReset(docList);
}

int cmp(const void *a, const void *b) {
    double value1 = *(double *)a;
    double value2 = *(double *)b;
    if (value1 > value2) return -1;
    else if (value1 < value2) return 1;
    else return 0;
}