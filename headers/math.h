// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implemetação do cálculo de relevância e suas funções

#include "../headers/fileManagement.h"

// Função para cálculo de relevância da lista de documentos
void mathRelevance(typePatPointer* patTree, typeDocList* docList, char* searchWordle);
// Função para cálculo de relevância de um documentos
double mathDocRelevance(typePatPointer *patTree, typeDocPointer currentDoc, char *searchWordle, int nDocs);
// Função para cálculo do peso de uma palavra
double mathWordleWeight(typePatPointer auxTree, typeIndexPointer auxIndex, int idDoc, int nDocs);
// Função para imprimir a lista de documentos por relevância
void printDocByRev(typeDocList *docList);
// Função auxiliar para função qsort
int cmp(const void *a, const void *b);