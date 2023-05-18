// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação dos cálculos realzidos no programa e suas funções

#include "../headers/patTree.h"
#include "../headers/doclist.h"
#include <math.h>

// Função para calcular a relevância de todos os documentos
void relevanceofDocs(typeDocList *lista, typePatPointer *root, typeWordle *searchWords, int numberOfwords);

// Função do cálculo de relevância do documento i com n palavras
double relevanceOfDoc(typeDoc doc, int lista.nDocs, typePatPointer *root, typeWordle *searchWords, int numberOfwords);

// Função do cálculo do peso da palavra j para o documento i
double weightOfWord(int lista.Docs, typePatPointer *root, typeWordle *j, int idDoc); // N receberá nDocs da estrutura typeDocList list
