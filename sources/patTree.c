// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/patTree.h"

int isTreeEmpty(typePatPointer patTree) {
    return patTree == NULL;
}

void startPatTree(typePatPointer* patTree) {
    *patTree = NULL;
}

char bit(int index, char* textWord) {
    return textWord[index];
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
    typeDocPointer auxDoc = findDoc(docList, idDoc); auxDoc -> itemDoc.nWordle++;
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> innext = ext;
    aux -> typeExtNode.wordleData = startWordle();
    fillWordle(&(aux -> typeExtNode.wordleData), textWord, idDoc);
    return aux;
}

typePatPointer insertPatTree(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc) {
    typeIndexPointer auxIndex;
    typeDocPointer auxDoc;
    typePatPointer auxTree;
    int i;
    char iChar;
    char diffChar;
    if (*patTree == NULL) {
        return startNodeExt(*docList, textWord, idDoc);
    }
    else {
        auxTree = *patTree;
        while (!isExt(auxTree)) {
            if (auxTree -> typeExtNode.typeInnNode.index > strlen(textWord)) {
                iChar = textWord[strlen(textWord)];
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
        i = 0;
        while ((i <= strlen(textWord)) && (bit(i, textWord) == bit(i, auxTree -> typeExtNode.wordleData.wordChar))) {
            i++;
        }
        if(i > strlen(textWord)) {
            auxIndex = findIdDoc(*auxTree -> typeExtNode.wordleData.indexList, idDoc);
            if (auxIndex == NULL) {
                auxDoc = findDoc(*docList, idDoc);
                auxDoc -> itemDoc.nWordle++;
            }
            insertIndexList(auxTree -> typeExtNode.wordleData.indexList, idDoc);
            return (*patTree);
        }
        else {
            i = 0;    
            while (bit(i, textWord) == bit(i, auxTree -> typeExtNode.wordleData.wordChar)) {
                i++;
            }
            if (bit(i, textWord) > bit(i, auxTree -> typeExtNode.wordleData.wordChar)) {
                diffChar = textWord[i];
            }
            else {
                diffChar = auxTree -> typeExtNode.wordleData.wordChar[i];
            }
            return insertBetween(patTree, docList, textWord, idDoc, i, diffChar);
        }
    }
}

typePatPointer insertBetween(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc, int i, char diffChar) {
    typePatPointer auxTree;
    if (isExt(*patTree) || (i < (*patTree) -> typeExtNode.typeInnNode.index)) {
        auxTree = startNodeExt(*docList, textWord, idDoc);
        if (bit(i, textWord) >= diffChar) {
            return startNodeInn(patTree, &auxTree, i, bit(i, textWord));
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

int searchPatTree(typePatPointer patTree, char* searchWordle) {
    if (isExt(patTree)) {
        if (strcmp(searchWordle, patTree -> typeExtNode.wordleData.wordChar) == 0) {
            return 1;
        } 
        else {
            return 0;
        }
    }
    if (strlen(searchWordle) < patTree -> typeExtNode.typeInnNode.index) {
        return searchPatTree(patTree -> typeExtNode.typeInnNode.left, searchWordle);
    } 
    else if (bit(patTree -> typeExtNode.typeInnNode.index, searchWordle) < patTree -> typeExtNode.typeInnNode.charIndex) {
        return searchPatTree(patTree -> typeExtNode.typeInnNode.left, searchWordle);
    } 
    else {
        return searchPatTree(patTree -> typeExtNode.typeInnNode.right, searchWordle);
    }
}

typePatPointer findNode(typePatPointer patTree, char* searchWordle) {
    if (isExt(patTree)) {
        if (strcmp(searchWordle, patTree -> typeExtNode.wordleData.wordChar) == 0) {
            return patTree;
        } 
        else {
            return NULL;
        }
    }
    if (strlen(searchWordle) < patTree -> typeExtNode.typeInnNode.index) {
        return findNode(patTree -> typeExtNode.typeInnNode.left, searchWordle);
    } 
    else if (bit(patTree -> typeExtNode.typeInnNode.index, searchWordle) < patTree -> typeExtNode.typeInnNode.charIndex) {
        return findNode(patTree -> typeExtNode.typeInnNode.left, searchWordle);
    } 
    else {
        return findNode(patTree -> typeExtNode.typeInnNode.right, searchWordle);
    }
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