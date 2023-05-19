// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implemetação do cálculo de relevância e suas funções

#include "../headers/patTree.h"

// Função para calcular a relevância de todos os documentos
float mathRelevance(typeDocList* docList, typePatPointer* patTree, char* searchWordle, int nSearchWordles);

// Função do cálculo de relevância do documento i com n palavras
float mathDocRelevance(typeDocList* docList, typePatPointer* patTree, char* searchWordle, int nSearchWordles);

// Função do cálculo do peso da palavra j para o documento i
float mathWordleWeight(int lista.Docs, typePatPointer *root, typeWordle *j, int idDoc);

// Funçãao para imprimir os documentos por relevância
void printDocByRev(typePatPointer* patTree, typeDocList* docList, float* rDoc);