// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "./headers/poocleMenu.h"

int main() {
    typePatPointer patTree;
    typeDocList docList;
    startDocList(&docList);
    insertDocList(&docList, "arquivo1.txt", 1);
    startPatTree(&patTree);
    insertPatTree(&patTree, &docList, "palavra", 1);
    printPatTree(patTree);
    return 0;
}