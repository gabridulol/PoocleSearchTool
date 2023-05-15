// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/wordle.h"

typeWordle* startSearchTerm() {
    typeWordle* wordle = (typeWordle*) malloc(sizeof(typeWordle));
    wordle -> indexList = (typeIndexList*) malloc(sizeof(typeIndexList));
    startIndexList(wordle -> indexList);
    return wordle;
}

void defineSearchTerm(typeWordle* wordle, char* textWord, int idDoc) {
    wordle -> wordChar = (char*) malloc(sizeof(char) * (strlen(textWord) + 1));
    strcpy(wordle -> wordChar, textWord);
    insertIndexList(wordle -> indexList, idDoc);
}

void printSearchTerm(typeWordle wordle) {
    printf("%s", wordle.wordChar);
    printIndexList(*wordle.indexList);
}