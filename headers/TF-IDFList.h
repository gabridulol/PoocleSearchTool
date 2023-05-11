// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação TF-IDF (Term frequency – Inverse Document Frequency) e suas funções

#include <stdio.h>
#include <stdlib.h>

// Estrutura do item TF-IDF
typedef struct tfIdf {
    int qtde; // Quantidade
    int idDoc; // Documento
} typeTfIdf;
// Estrutura da célula do item TF-IDF
typedef struct typeCell* typePointer;
typedef struct typeCell {
    typeTfIdf itemTfIdf;
    typePointer nextCell;
} typeCell;
// Estrutura da lista encadeada do item TF-IDF
typedef struct listTfIdf {
    typePointer firstCell;
    typePointer lastCell;
} typeListTfIdf;

// Função para inicar a lista encadeada de itens TF-IDF
void startListTfIdf(typeListTfIdf* listTfIdf);
// Função para inserir a lista encadeada de itens TF-IDF
void insertListTfIdf(typeListTfIdf* listTfIdf, typeTfIdf itemTfidf);
// Função para imprimir a lista encadeada de itens TF-IDF
void printListTfIdf(typeListTfIdf listTfIdf);