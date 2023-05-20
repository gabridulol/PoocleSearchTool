// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação TF-IDF (Term frequency – Inverse Document Frequency) e suas funções

#include "../headers/docList.h"

// Estrutura do item TF-IDF
typedef struct index {
    int qtde; // Quantidade
    int idDoc; // Documento
} typeIndex;
// Estrutura da célula do item TF-IDF
typedef struct typeIndexCell* typeIndexPointer;
typedef struct typeIndexCell {
    typeIndex itemIndex;
    typeIndexPointer nextCell;
} typeIndexCell;
// Estrutura da lista encadeada do item TF-IDF
typedef struct indexList {
    typeIndexPointer firstCell;
    typeIndexPointer lastCell;
} typeIndexList;

// Função para inicar a lista encadeada de itens TF-IDF
void startIndexList(typeIndexList* indexList);
// Função para inserir na lista encadeada de itens TF-IDF
void insertIndexList(typeIndexList* indexList, int idDoc);
// Função para procurar o indíce de um arquivo específico
typeIndexPointer findIdDoc(typeIndexList indexList, int idDoc);
//
int sizeIndexList(typeIndexList indexList);
// Função para imprimir a lista encadeada de itens TF-IDF
void printIndexList(typeIndexList indexList);