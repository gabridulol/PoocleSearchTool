// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/patTree.h"

void startPatTree(typePatPointer* patTree) {
    *patTree = NULL;
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

typePatPointer startNodeExt(char* textWord, int idDoc) {
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> typeInnExt = ext;
    aux -> typeExtNode.wordleData = startWordle();
    fillWordle(aux -> typeExtNode.wordleData, textWord, idDoc);
    return aux;
}

typePatPointer insertPatTree(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc) {
    typeDocPointer auxDoc = findDoc(*docList, idDoc);
    typePatPointer auxInsert;
    int i;
    if (*patTree == NULL) {
        return startNodeExt(textWord, idDoc);
    }
}

typePatPointer insertBetween(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc, int index) {
    
}

// int searchPatTree(typePatPointer patTree, char* searchTerm){
//     if (patTree != NULL){
//         if (patTree -> typeInnExt == ext){
//             if (strcmp(searchTerm, patTree -> typeExtNode.wordleData -> wordChar) == 0) {
//                 return 1;
//             }
//             else {
//                 return 0;
//             }
//         }
//         else {
//             searchPat(patTree -> typeExtNode.typeInnNode.left, searchTerm);
//             searchPat(patTree -> typeExtNode.typeInnNode.right, searchTerm);
//         }
//     }
// }

void printPatTree(typePatPointer patTree){
    if (patTree != NULL) {
        if (patTree -> typeInnExt == inn) {
            printPatTree(patTree -> typeExtNode.typeInnNode.left);
        }
        if (patTree -> typeInnExt == ext) {
            printWordle(*patTree -> typeExtNode.wordleData);
        }
        if (patTree -> typeInnExt == inn) {
            printPatTree(patTree -> typeExtNode.typeInnNode.right);
        }
    }
}