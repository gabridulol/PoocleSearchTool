// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação da lista de documentos e suas funções

#include "../headers/include.h"

// Estrutura do documento
typedef struct doc {
    // Informações básicas do documento
    char* docName; // Nome do documento
    int idDoc; // idDoc do documento
    double rDoc; // Relevância do documento
    int nWordle; // Termos distintos do documento
} typeDoc;

// Estrutura da célula da lista encadeada de documentos
typedef struct typeDocCell* typeDocPointer;
typedef struct typeDocCell {
    typeDoc itemDoc; // Documento
    typeDocPointer nextCell;
} typeDocCell;

// Estrutura da lista encadeada de documentos
typedef struct docList {
    int nDocs; // Quantidade de documentos na lista de documentos
    typeDocPointer firstCell;
    typeDocPointer lastCell;
} typeDocList;

// Função para iniciar a lista de documentps
void startDocList(typeDocList* docList);
// Função para inserir na lista de documentos
void insertDocList(typeDocList* docList, char* docName, int idDoc);
// Função para alocar memória e dados de inserção do documento
void fillDoc(typeDocList* docList, char* docName, int idDoc);
// Função para zerar a relevância dos documentos para nova pesquisa
void docReset(typeDocList* docList);
// Função para procurar na lista de documentos por idDoc
typeDocPointer findDoc(typeDocList docList, int idDoc);
// Função para procurar na lista de documentos por relevância
typeDocPointer findDocByRev(typeDocList docList, double rDoc);
// Função para imprimir a lista de documentos
void printDocList(typeDocList docList);