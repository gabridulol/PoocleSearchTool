// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/docMath.h"


void mathRelevance(typePatPointer* patTree, typeDocList* docList, char* searchWordle) {
    typeDocPointer auxDoc = docList -> firstCell -> nextCell;
    while (auxDoc != NULL) {
        auxDoc -> itemDoc.rDoc = mathDocRelevance(patTree, auxDoc, searchWordle, docList -> nDocs);
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
    double n = (qtde * (log10(nDocs) / inDoc));
    return (qtde * (log10(nDocs) / inDoc));
}

void printDocByRev(typePatPointer* patTree, typeDocList* docList, double* rDoc) {
    typeDocPointer auxDoc;
    int docCount = 0;
    while (docCount < docList -> nDocs) {
        auxDoc = findDocByRev(*docList, rDoc[docCount]);
        printf("Texto %d (%s)\n", auxDoc -> itemDoc.idDoc, auxDoc -> itemDoc.docName);
        docCount++;
    }
}