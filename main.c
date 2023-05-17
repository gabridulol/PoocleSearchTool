// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "./headers/poocleMenu.h"

int main() {
    typeDocList docList;
    typePatPointer patTree;
    startDocList(&docList);
    startPatTree(&patTree);
    insertDocList(&docList, "arquivo1.txt", 1);
    printPatTree(patTree);
    return 0;
}