// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "./headers/poocleMenu.h"

int main() {
    typePatPointer patTree;
    poocleMenu(docList, patTree);
    typeDocList docList;
    startDocList(&docList);
    insertDocList(&docList, "arquivo1.txt", 1);
    printDocList(docList);
    startPatTree(&patTree);
    patTree = insertPatTree(&patTree, docList, "palavra", 1);
    patTree = insertPatTree(&patTree, docList, "passaro", 1);
    patTree = insertPatTree(&patTree, docList, "amor", 1);
    patTree = insertPatTree(&patTree, docList, "cristina", 1);
    patTree = insertPatTree(&patTree, docList, "buceta", 1);
    patTree = insertPatTree(&patTree, docList, "cristino", 1);
    patTree = insertPatTree(&patTree, docList, "cristinu", 1);
    patTree = insertPatTree(&patTree, docList, "cristinu", 1);
    patTree = insertPatTree(&patTree, docList, "cristinu", 5);
    patTree = insertPatTree(&patTree, docList, "amor", 1);   
    patTree = insertPatTree(&patTree, docList, "passaro", 1);
    patTree = insertPatTree(&patTree, docList, "passaram", 1);
    patTree = insertPatTree(&patTree, docList, "passarao", 1);
    patTree = insertPatTree(&patTree, docList, "passar", 1);
    patTree = insertPatTree(&patTree, docList, "doug", 1);            
    printPatTree(patTree);
    return 0;
}