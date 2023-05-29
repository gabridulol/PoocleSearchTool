// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do índice invertido TF-IDF (Term frequency – Inverse Document Frequency) e suas funções

#include "../headers/docList.h"

// Estrutura do índice
typedef struct index {
    int qtde; // Quantidade
    int idDoc; // Documento
} typeIndex;

// Estrutura da célula da lista encadeade de índices
typedef struct typeIndexCell* typeIndexPointer;
typedef struct typeIndexCell {
    typeIndex itemIndex;
    typeIndexPointer nextCell;
} typeIndexCell;

// Estrutura da lista encadeada de índices
typedef struct indexList {
    typeIndexPointer firstCell;
    typeIndexPointer lastCell;
} typeIndexList;

// Função para inicar a lista de índices
void startIndexList(typeIndexList* indexList);
// Função para inserir na lista de índices
void insertIndexList(typeIndexList* indexList, int idDoc);
// Função para procurar na lista de índices por idDoc
typeIndexPointer findIdDoc(typeIndexList indexList, int idDoc);
// Função para retornar o tamanho da lista de índices
int sizeIndexList(typeIndexList indexList);
// Função para imprimir a lista de índices
void printIndexList(typeIndexList indexList);