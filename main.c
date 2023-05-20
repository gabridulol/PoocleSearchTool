// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "./headers/poocleMenu.h"

int main() {
    typePatPointer patTree;
    typeDocList docList;
    getFile(&docList);
    buildInvertedIndex(&patTree, &docList);
    printInvertedIndex(&patTree);
    searchTool(&patTree, &docList);
    printDocList(docList);
    return 0;
}