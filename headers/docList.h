// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação da lista de documentos a serem indexados e suas funções

#include "../headers/include.h"

// Estrutura do documento
typedef struct doc {
    // Informações básicas do documento
    char* docName; // Nome do documento
    int idDoc; // idDoc do documento
    float rDoc; // Relevância do documento na lista de documentos
    int nWordle; // Quantidade de termos distintos no documento
} typeDoc;

// Estrutura da célula do documento
typedef struct typeDocCell* typeDocPointer;
typedef struct typeDocCell {
    typeDoc itemDoc;
    typeDocPointer nextCell;
} typeDocCell;

// Estrutura da lista encadeada de documentos
typedef struct docList {
    int nDocs; // Quantidade de documentos na lista de documentos
    typeDocPointer firstCell;
    typeDocPointer lastCell;
} typeDocList;

// Função para iniciar a lista encadeada
void startDocList(typeDocList* docList);
// Função para inserir na lista encadeada
void insertDocList(typeDocList* docList, char* docName, int idDoc);
// Função para alocar memória e dados de inserção
void fillDoc(typeDocList* docList, char* docName, int idDoc);
// Função para procurar na lista encadeada por idDoc
typeDocPointer findDoc(typeDocList docList, int idDoc);
// Função para procurar na lista encadeda por relevância
typeDocPointer findDocByRev(typeDocList docList, float rDoc);
// Função para imprimir a lista encadeada
void printDocList(typeDocList docList);
