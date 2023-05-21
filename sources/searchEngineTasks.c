// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/searchEngineTasks.h"

void getFile(typeDocList* docList) {
    readSrcFile(docList, "entrada.txt");
    printf("\nDocuments list:\n\n");
    printDocList(*docList);
}

void buildInvertedIndex(typePatPointer* patTree, typeDocList* docList) {
    readDocFile(patTree, docList);
}

void printInvertedIndex(typePatPointer* patTree) {
    printf("\nInverted index:\n\n");
    printPatTree(*patTree);
    printf("\n");
}

void searchTool(typePatPointer* patTree, typeDocList* docList, char* searchLine) {
    char* searchWordle = strtok(searchLine, " ");
    while (searchWordle != NULL) {
        searchWordle[strcspn(searchWordle, "\n")] = '\0';
        mathRelevance(patTree, docList, searchWordle);
        searchWordle = strtok(NULL, " ");
    }
}