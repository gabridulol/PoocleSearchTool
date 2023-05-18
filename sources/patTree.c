// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/patTree.h"

void startPatTree(typePatPointer* patTree) {
    *patTree = NULL;
}

char bit(int index, char* textWord) {
    return textWord[index - 1];
}

int isExt(typePatPointer patTree) {
    return (patTree -> innext == ext);
}

typePatPointer startNodeInn(typePatPointer* left, typePatPointer* right, int index, char charIndex) {
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> innext = inn;
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
    aux -> innext = ext;
    aux -> typeExtNode.wordleData = startWordle();
    fillWordle(&(aux -> typeExtNode.wordleData), textWord, idDoc);
    return aux;
}

typePatPointer insertPatTree(typePatPointer* patTree, typeDocList docList, char* textWord, int idDoc) {
    typePatPointer auxTree;
    char iChar;
    char diffChar;
    int size = strlen(textWord);
    if (*patTree == NULL) {
        return startNodeExt(docList, textWord, idDoc);
    }
    else {
        auxTree = *patTree;
        while (!isExt(auxTree)) {
            if (auxTree -> typeExtNode.typeInnNode.index > size) {
                iChar = textWord[size];
            }
            else {
                iChar = bit(auxTree -> typeExtNode.typeInnNode.index, textWord);
            }
            if (iChar < auxTree -> typeExtNode.typeInnNode.charIndex) {
                auxTree = auxTree -> typeExtNode.typeInnNode.left;
            }
            else {
                auxTree = auxTree -> typeExtNode.typeInnNode.right;
            }
        }
        if (strcmp(textWord, auxTree -> typeExtNode.wordleData.wordChar) == 0) {
            insertIndexList(auxTree -> typeExtNode.wordleData.indexList, idDoc);
            return (*patTree);
        }
        else {
            int i = 1;
            while (bit(i, textWord) == bit(i, auxTree -> typeExtNode.wordleData.wordChar)) {
                i++;
            }
            if (bit(i, textWord) > bit(i, auxTree -> typeExtNode.wordleData.wordChar)) {
                diffChar = textWord[i - 1];
            }
            else {
                diffChar = auxTree -> typeExtNode.wordleData.wordChar[i - 1];
            }
            return insertBetween(patTree, docList, textWord, idDoc, i, diffChar);
        }
    }
}

typePatPointer insertBetween(typePatPointer* patTree, typeDocList docList, char* textWord, int idDoc, int i, char diffChar) {
    typePatPointer auxTree;
    if (isExt(*patTree)) {
        auxTree = startNodeExt(docList, textWord, idDoc);
        if (bit(i, textWord) >= bit(i, (*patTree) -> typeExtNode.wordleData.wordChar)) {
            return startNodeInn(patTree, &auxTree, i, diffChar);
        }
        else {
            return startNodeInn(&auxTree, patTree, i, diffChar);
        }
    }
    else if (i < (*patTree) -> typeExtNode.typeInnNode.index) {
        auxTree = startNodeExt(docList, textWord, idDoc);
        if (bit(i, textWord) >= diffChar) {
            return startNodeInn(patTree, &auxTree, i, diffChar);
        }
        else {
            return startNodeInn(&auxTree, patTree, i, diffChar);
        }
    }
    else {
        if (bit((*patTree) -> typeExtNode.typeInnNode.index, textWord) >= (*patTree) -> typeExtNode.typeInnNode.charIndex) {
            (*patTree) -> typeExtNode.typeInnNode.right = insertBetween(&(*patTree) -> typeExtNode.typeInnNode.right, docList, textWord, idDoc, i ,diffChar);
        }
        else {
            (*patTree) -> typeExtNode.typeInnNode.left = insertBetween(&(*patTree) -> typeExtNode.typeInnNode.left, docList, textWord, idDoc, i, diffChar);
        }
    }
    return (*patTree);
}

void printPatTree(typePatPointer patTree) {
    if (patTree != NULL) {
        if (patTree -> innext == inn) {
            printPatTree(patTree -> typeExtNode.typeInnNode.left);
        }
        if (patTree -> innext == ext) {
            printWordle(patTree -> typeExtNode.wordleData);
        }
        if (patTree -> innext == inn) {
            printPatTree(patTree -> typeExtNode.typeInnNode.right);
        }
    }
}