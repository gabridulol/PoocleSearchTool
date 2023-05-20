// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implemetação do cálculo de relevância e suas funções

#include "../headers/fileManagement.h"

// Função para calcular a relevância de todos os documentos
void mathRelevance(typePatPointer* patTree, typeDocList* docList, char* searchWordle);

// Função do cálculo de relevância do documento i com n palavras
double mathDocRelevance(typePatPointer *patTree, typeDocPointer currentDoc, char *searchWordle, int nDocs);

// Função do cálculo do peso da palavra j para o documento i
double mathWordleWeight(typePatPointer auxTree, typeIndexPointer auxIndex, int idDoc, int nDocs);

// Funçãao para imprimir os documentos por relevância
void printDocByRev(typePatPointer *patTree, typeDocList *docList, double *rDoc);