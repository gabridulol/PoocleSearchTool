// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/patTree.h"

void startPatTree(typePatPointer* patTree) {
    *patTree = NULL;
}

int isExt(typePatPointer patTree) {
    return (patTree -> InnExt == ext);
}

char bit(int diffIndex, typeWordle* wordleData) {
    return (wordleData -> wordChar[diffIndex - 1]);
}

typePatPointer startNodeInn(typePatPointer* left, typePatPointer* right, int index, char charIndex) {
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> InnExt = inn;
    aux -> typeExtNode.typeInnNode.left = *left;
    aux -> typeExtNode.typeInnNode.right = *right;
    aux -> typeExtNode.typeInnNode.index = index;
    aux -> typeExtNode.typeInnNode.charIndex = charIndex;
    return aux;
}

typePatPointer startNodeExt(typeWordle* wordleData) {
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> InnExt = ext;
    aux -> typeExtNode.wordleData = startWordle();
}

typePatPointer insertPatTree(typePatPointer* patTree, typeDocList* docList, char* textWord, int idDoc) {
    typeDocPointer auxDoc = findDoc(*docList, idDoc);
    typeWordle* wordleData = startWordle();
    defineWordle(wordleData, textWord, idDoc);
    typePatPointer aux;
    int i;
    if (*patTree == NULL) {
        return startNodeExt(wordleData);
    }
    else {
        aux = *patTree;
        while (!isExt(aux)) {
            if (bit(aux -> typeExtNode.typeInnNode.index, wordleData) == 1) {
                aux = aux -> typeExtNode.typeInnNode.right;
            }
            else {
                aux = aux -> typeExtNode.typeInnNode.left;
            }
        }
        i = 0;
        while (((i < strlen(wordleData->wordChar)) && (bit(i, wordleData))) == bit(i, aux->typeExtNode.wordleData)) {
            i++;
        }
        if (i > strlen(wordleData->wordChar)) {
            auxDoc->itemDoc.nWordle++;
        }
        else {
            return NULL;
        }
    }
    free(auxDoc);
    free(wordleData);
}

// typePatPointer insertBetween(typePatPointer *patTree, typ    free(auxDoc);eDocList *docList, typeWordle *wordleData, int i) {
// }

// void searchPat(typePatPointer patty, char searchWord){
//     if(patty != NULL){
//         if(patty->InnExt == ext){
//             if(strcmp(searchWord, patty->typeExtNode.data.wordChar)==0) printf("Palavra encontrada!!\n");
//             else printf("Palavra não encontrada!!\n");
//             return;
//         }
//         else{
//             searchPat(patty->typeExtNode.typeInnNode.left, searchWord);
//             searchPat(patty->typeExtNode.typeInnNode.right, searchWord);
//         }

//     }
// }

void printPatTree(typePatPointer patTree){
    if(patTree != NULL){
        if(patTree->InnExt == ext){
            printWordle(*patTree->typeExtNode.wordleData);
            return;
        }
        else{
            printPatTree(patTree->typeExtNode.typeInnNode.left);
            printPatTree(patTree->typeExtNode.typeInnNode.right);
        }
    }
}