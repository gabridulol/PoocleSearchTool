// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include <stdio.h>
#include <stdlib.h>

#include "./headers/TF-IDFDocument.h"

int main() {
    typeDocList docList;
    startDocList(&docList);
    insertDocList(&docList, "arquivo1.txt", 1);
    insertDocList(&docList, "arquivo2.txt", 2);
    insertDocList(&docList, "arquivo3.txt", 3);
    insertDocList(&docList, "arquivo4.txt", 4);
    printDocList(docList);
    return 0;
}