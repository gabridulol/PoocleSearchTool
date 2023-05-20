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

void searchTool(typePatPointer* patTree, typeDocList* docList) {
    char searchWordle[size];
    while (1) {
        fgets(searchWordle, sizeof(searchWordle), stdin);
        if (strcmp(searchWordle, "\n") == 0) {
            break;
        }
        searchWordle[strcspn(searchWordle, "\n")] = '\0';
        mathRelevance(patTree, docList, searchWordle);
    }
    printDocByRev(patTree, docList);
}