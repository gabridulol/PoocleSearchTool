// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/math.h"

void relevanceofDocs(typeDocList *lista, typePatPointer *root, typeWordle *searchWords, int numberOfwords) {

}

float relevanceOfDoc(typeDoc doc, int nDocs, typePatPointer *root, typeWordle *searchWords, int numberOfwords){

}

float weightOfWord(int lista.Docs, typePatPointer *root, typeWordle *j, int idDoc) {
    
}

void printDocByRev(typePatPointer* patTree, typeDocList* docList, float* rDoc) {
    typeDocPointer auxDoc;
    int docCount = 0;
    while (docCount < docList -> nDocs) {
        auxDoc = findDocByRev(*docList, rDoc[docCount]);
        printf("Texto %d (%s)\n", auxDoc -> itemDoc.idDoc, auxDoc -> itemDoc.docName);
        docCount++;
    }
}
