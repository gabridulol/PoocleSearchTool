// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/searchEngineTasks.h"

void getFile(typeDocList* docList) {
    readSrcFile(docList, "entrada.txt");
}

void buildInvertedIndex(typePatPointer* patTree, typeDocList* docList) {
    readDocFile(patTree, docList);
}

void printInvertedIndex(typePatPointer* patTree) {
    printPatTree(*patTree);
}

void searchTool(typePatPointer* patTree, typeDocList* docList, char* searchLine) {
    char* searchWordle = strtok(searchLine, " ");
    while (searchWordle != NULL) {
        searchWordle[strcspn(searchWordle, "\n")] = '\0';
        mathRelevance(patTree, docList, searchWordle);
        searchWordle = strtok(NULL, " ");
    }
}