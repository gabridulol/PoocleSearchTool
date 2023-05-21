// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do manejador de arquivos e suas funções

#include "../headers/patTree.h"

// Função para ler o arquivo de entrada "arquivos.txt"
int readSrcFile(typeDocList* docList, char* srcFileName);
// Função para escrever o arquivo de entrada em uma lista (docList)
void writeSrcFile(typeDocList* docList, FILE* srcFile);
// Função para ler os arquivos de POCs "arquivoN.txt"
void readDocFile(typePatPointer* patTree, typeDocList* docList);
// Função para escrever os arquivos de POCs na árvore (patTree)
int writeDocFile(typePatPointer* patTree, typeDocList* docList, typeDocPointer auxDoc);
// Função para preparar os arquivos de POCs para serem escritos
void cleanFiles(); // Para mais detalhes ver fileManagement.py