// // Gabriel Rodrigues Marques - 5097
// // Alan Araújo dos Reis - 5096
// // Marcos Biscotto de Oliveira - 4236
// // Luiz César Galvão Lima - 4216

#include "../headers/patTree.h"

// void startPatty(typePatPointer *patty){
//     *patty = NULL;
// }

// int ifNodeExt(typePatPointer patty){
//     return(patty->InnExt==ext);
// }

// char Bit(int indexDiferentLetter, typeSearchTerm *data){
//     return(data->wordChar[indexDiferentLetter - 1]);
// }

// typePatPointer startNodeInn(typePatPointer *left, typePatPointer *right, int index, char charindex){
//     typePatPointer aux;
//     aux = (typePatPointer) malloc(sizeof(typePatNode));
//     aux->InnExt = inn;
//     aux->typeExtNode.typeInnNode.left = *left;
//     aux->typeExtNode.typeInnNode.right = *right;
//     aux->typeExtNode.typeInnNode.index = index;
//     aux->typeExtNode.typeInnNode.charIndex = charindex;
//     return aux;
// }
// typePatPointer starNodeExt(typeSearchTerm *data){
//     typePatPointer aux;
//     aux = (typePatPointer) malloc(sizeof(typePatNode));
//     aux->InnExt = ext;
//     aux->typeExtNode.data = *data;
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