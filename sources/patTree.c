// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/patTree.h"

void startPatTree(typePatPointer* patTree) {
    *patTree = NULL;
}

char bit(int diffIndex, char* textWord) {
    return textWord[diffIndex - 1];
}

int isExt(typePatPointer patTree) {
    return (patTree -> typeInnExt == ext);
}

typePatPointer startNodeInn(typePatPointer* left, typePatPointer* right, int index, char charIndex) {
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> typeInnExt = inn;
    aux -> typeExtNode.typeInnNode.left = *left;
    aux -> typeExtNode.typeInnNode.right = *right;
    aux -> typeExtNode.typeInnNode.index = index;
    aux -> typeExtNode.typeInnNode.charIndex = charIndex;
    return aux;
}

typePatPointer startNodeExt(typeDocList docList, char* textWord, int idDoc) {
    typeDocPointer doc = findDoc(docList, idDoc); doc -> itemDoc.nWordle++;
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> typeInnExt = ext;
    aux -> typeExtNode.wordleData = startWordle();
    fillWordle(&(aux -> typeExtNode.wordleData), textWord, idDoc);
    return aux;
}

typePatPointer insertPatTree(typePatPointer* patTree, typeDocList docList, char* textWord, int idDoc) {
    typePatPointer aux;
    char diffChar;
    int i;
    if (*patTree == NULL) {
        return startNodeExt(docList, textWord, idDoc);
    }
    else {
        aux = *patTree;
        while (!isExt(aux)) {
            if (bit(aux -> typeExtNode.typeInnNode.index, textWord) == 1) {
                aux = aux -> typeExtNode.typeInnNode.right;
            }
            else {
                aux = aux -> typeExtNode.typeInnNode.left;
            }
        }
        i = 0;
        while (((i < strlen(textWord)) && (bit(i, textWord))) == bit(i, aux -> typeExtNode.wordleData.wordChar)) {
            i++;
        }
        if (i > strlen(textWord)) {
            insertIndexList(aux -> typeExtNode.wordleData.indexList, idDoc);
            return *patTree;
        }
        else {
            while (bit(i, textWord) == bit(i, (*patTree) -> typeExtNode.wordleData.wordChar)) {
                i++;
            }
            if (bit(i, textWord) > bit(i, (*patTree) -> typeExtNode.wordleData.wordChar)) {
                diffChar = (*patTree) -> typeExtNode.wordleData.wordChar[i - 1];
            }
            else{
                diffChar = (*patTree) -> typeExtNode.wordleData.wordChar[i - 1];
            }
            return insertBetween(patTree, docList, textWord, idDoc, i, diffChar);
        }
    }
}

typePatPointer insertBetween(typePatPointer* patTree, typeDocList docList, char* textWord, int idDoc, int i, char diffChar) {
    typePatPointer aux;
    if (isExt(*patTree) || i < (*patTree) -> typeExtNode.typeInnNode.index) {
        aux = startNodeExt(docList, textWord, idDoc);
        if (bit(i, textWord) >= bit(i, (*patTree) -> typeExtNode.wordleData.wordChar)) {
            return startNodeInn(patTree, &aux, i, diffChar);
        }
        else {
            return startNodeInn(&aux, patTree, i, diffChar); 
        }
    }
    else {
        if (bit((*patTree) -> typeExtNode.typeInnNode.index, textWord) >= (*patTree) -> typeExtNode.typeInnNode.charIndex) {
          (*patTree) -> typeExtNode.typeInnNode.right = insertBetween(&(*patTree) -> typeExtNode.typeInnNode.right, docList, textWord, idDoc, i, diffChar);
        }
        else{
            (*patTree) -> typeExtNode.typeInnNode.left = insertBetween(&(*patTree) -> typeExtNode.typeInnNode.left, docList, textWord, idDoc, i, diffChar);
        }
        return *patTree;
    }
 }

void printPatTree(typePatPointer patTree) {
    if (patTree != NULL) {
        if (patTree -> typeInnExt == ext) {
            printWordle(patTree -> typeExtNode.wordleData);
        }
        else {
            printPatTree(patTree -> typeExtNode.typeInnNode.left);
            printPatTree(patTree -> typeExtNode.typeInnNode.right);
        }
    }
}