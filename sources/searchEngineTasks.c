// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/searchEngineTasks.h"

void getFile(typeDocList* docList) {
    readSrcFile(docList, "entrada.txt");
    printf("Documents list:\n");
    printDocList(*docList);
}

void buildInvertedIndex(typePatPointer* patTree, typeDocList* docList) {
    readDocFile(patTree, docList);
}

void printInvertedIndex(typePatPointer* patTree) {
    printf("Inverted index:\n");
    printPatTree(*patTree);
    printf("\n");
}

void searchTool(typePatPointer* patTree, typeDocList* docList) {
    printf("Poocle Search Tool:\n");
    char searchLine[size];
    char* searchWordle;
    while (1) {
        fgets(searchLine, sizeof(searchLine), stdin);
        if (searchLine[0] == '\n') {
            break;
        }
        searchWordle = strtok(searchLine, " ");
        while (searchWordle != NULL) {
            searchWordle[strcspn(searchWordle, "\n")] = '\0';
            mathRelevance(patTree, docList, searchWordle);
            searchWordle = strtok(NULL, " ");
        }
    }
    printDocByRev(docList);
    docReset(docList);
}