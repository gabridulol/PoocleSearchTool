// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/docMath.h"


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
    double n = (qtde * (log10(nDocs) / inDoc));
    return (qtde * (log10(nDocs) / inDoc));
}

void printDocByRev(typePatPointer* patTree, typeDocList* docList) {
    typeDocPointer auxDoc;
    auxDoc = docList->firstCell->nextCell;
    int docCount = 0;
    double array[docList -> nDocs];
    while (auxDoc != NULL) {
        array[docCount] = auxDoc->itemDoc.rDoc;
        docCount++;
        auxDoc = auxDoc -> nextCell; 
    }
    sort(array, docList);
    for(int i = 0; i<docList->nDocs; i++) {
        typeDocPointer docaux = findDocByRev(*docList, array[i]);
        printf("Texto: %d(%s)\n",docaux->itemDoc.idDoc, docaux->itemDoc.docName);
    }  
    }

void sort(double *array, typeDocList *doclist){
int i, j, min, aux;
  
  for (i = 0; i < ( - 1); i++) {
   
    min = i;
    for (j = i+1; j < doclist->nDocs; j++) {

      if (array[j] < array[min]) {
   min = j;
      }
    }
    if (i != min) {
      aux = array[i];
      array[i] = array[min];
      array[min] = aux;
    }
  }
}