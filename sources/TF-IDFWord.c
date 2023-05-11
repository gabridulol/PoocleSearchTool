// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/TF-IDFWord.h"

typeSearchTerm* startSearchTerm() {
    typeSearchTerm* searchTerm = (typeSearchTerm*) malloc(sizeof(typeSearchTerm));
    searchTerm -> listTfIdf = (typeListTfIdf*) malloc(sizeof(typeListTfIdf));
    startListTfIdf(searchTerm -> listTfIdf);
    return searchTerm;
}


void defineSearchTerm(typeSearchTerm* searchTerm, char* textWord) {
    searchTerm -> wordChar = (char*) malloc(sizeof(char) * (strlen(textWord) + 1));
    strcpy(searchTerm -> wordChar, textWord);
}

void printSearchTerm(typeSearchTerm searchTerm) {
    printf("%s", searchTerm.wordChar);
    printListTfIdf(*searchTerm.listTfIdf);
}