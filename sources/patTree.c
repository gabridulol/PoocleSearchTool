// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/patTree.h"

void startPatTree(typePatPointer *patTree) {
    *patTree = NULL;
}

int ifNodeExt(typePatPointer patTree) {
    return (patTree -> InnExt == ext);
}

char bit(int diffIndex, typeWordle* wordleData) {
    return wordleData -> wordChar[diffIndex - 1];
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

typePatPointer startNodeExt(typeWordle *wordleData){
    typePatPointer aux;
    aux = (typePatNode*) malloc(sizeof(typePatNode));
    aux -> InnExt = ext;
    aux -> typeExtNode.wordle = *wordleData;
}

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


// void printPat(typePatPointer patty){
//     if(patty != NULL){
//         if(patty->InnExt == ext){
//             printf("%s\n", patty->typeExtNode.data.wordChar);
//             return;
//         }
//         else{
//             printPat(patty->typeExtNode.typeInnNode.left);
//             printPat(patty->typeExtNode.typeInnNode.right);
//         }
//     }
// }