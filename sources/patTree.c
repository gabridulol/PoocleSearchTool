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
    typePatPointer aux;
    char diferentLetter;
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
            return patTree;
        }
        else {
             while (bit(i, wordleData->wordChar) == bit(i, (*patTree)->typeExtNode.wordleData->wordChar)) i++;
            if (bit(i, wordleData->wordChar) > bit(i, (*patTree)->typeExtNode.wordleData->wordChar)){
                diferentLetter = wordleData->wordChar[i - 1];
            }
            else{
                diferentLetter = (*patTree)->typeExtNode.wordleData->wordChar[i - 1];
            }
            
            return insertBetween(patTree, docList, *wordleData, i, idDoc, diferentLetter);
        }
    }
    free(auxDoc);
}

typePatPointer insertBetween(typePatPointer* patTree, typeDocList* docList, typeWordle wordleData, int i, int idDoc, char diferentLetter){
    typePatPointer aux;
    typeDocPointer auxDoc = findDoc(*docList, idDoc);
    if(isExt(patTree) || i < (*patTree)->typeExtNode.typeInnNode.index){
        aux = starNodeExt(patTree);
        if(bit(i, wordleData.wordChar) >= bit(i,(*patTree)->typeExtNode.wordleData->wordChar)) return startNodeInn(patTree, &aux, i, diferentLetter);
        else return startNodeInn(&aux, patTree, i, diferentLetter); 
    }
    else{
        if(bit((*patTree)->typeExtNode.typeInnNode.index, wordleData.wordChar) >= (*patTree)->typeExtNode.typeInnNode.charIndex){
          (*patTree)->typeExtNode.typeInnNode.right = insertBetween(&(*patTree)->typeExtNode.typeInnNode.right, docList, wordleData, i, idDoc, diferentLetter);
        }
        else{
            (*patTree)->typeExtNode.typeInnNode.left = insertBetween(&(*patTree)->typeExtNode.typeInnNode.left, docList, wordleData, i, idDoc, diferentLetter);
        }
        return patTree;
    }
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

void printPatTree(typePatPointer patTree){
    if(patTree != NULL){
        if(patTree -> InnExt == ext){
            printWordle(*patTree -> typeExtNode.wordleData);
            return;
        }
        else{
            printPatTree(patTree -> typeExtNode.typeInnNode.left);
            printPatTree(patTree -> typeExtNode.typeInnNode.right);
        }
    }
}