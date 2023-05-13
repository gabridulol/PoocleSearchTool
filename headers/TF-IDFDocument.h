// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação da lista encadeada de DOCUMENTOS a serem indexados e suas funções

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do DOCUMENTO
typedef struct doc {
    // Informações básicas do documento
    char* docName; // Nome do documento
    int idDoc; // idDoc do documento
    // Informação para cálculo de relevância do documento
    float rDoc; // Relevância do documento na lista de documentos
    float wSearchTerm; // Peso do termo pesquisado no documento
    int nTerms; // Quantidade de termos distintos no documento
    int nSearchTerms; // Quantidade de termos do termo pesquisado no documento
} typeDoc;

// Estrutura da célula do item DOCUMENTO
typedef struct typeDocCell* typeDocPointer;
typedef struct typeDocCell {
    typeDoc itemDoc;
    typeDocPointer nextCell;
} typeDocCell;

// Estrutura da lista encadeada do
typedef struct docList {
    int nDocs; // Quantidade de documentos na lista de documentos
    typeDocPointer firstCell;
    typeDocPointer lastCell;
} typeDocList;

void startDocList(typeDocList* docList);
void insertDocList(typeDocList* docList, char* docName, int idDoc);
void mallocNewDoc(typeDocList* docList, char* docName, int idDoc);
void rDocPrint(typeDocList docList);
void copyDocList(typeDocList* docList, typeDoc* newDocList, int size);
void selectPrint(typeDoc* newDocList, int size);
int totalDocList(typeDocList docList);
void printDocList(typeDocList docList);
