// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do manejador de arquivos e suas funções

#include "../headers/patTree.h"


int readSrcFile(typeDocList* docList, char* srcFileName);
void writeSrcFile(typeDocList* docList, FILE* srcFile);
void readDocFile(typePatPointer* patTree, typeDocList *docList);
int writeDocFile(typePatPointer* patTree, typeDocList* docList, typeDocPointer doc);
void cleanFiles(); // Para mais detalhes ver fileManagement.py
