// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do manejador de arquivos  e suas funções

#include "../headers/PATRICIA.h"


#define SIZEOFCHAR 100 // Definindo tamanho máximo para uma variável tipo char

// Função geral para ler os arquivos da pasta files e indicar o diretório do arquivo "entradas.txt"
void readingFolderFiles(char* fileName);
// Função para ler o arquivo "entradas.txt"
int readSrcFile(char* fileDirectory);
// Função para indicar o diretório dos arquivos "arquivoN.txt"
void readingDocFiles(char* docName, int isQtde, int isIdDoc);
// Função para ler o arquivo específico "arquivoN.txt"
int readDocText(char* docDirectory, int isQtde, int isIdDoc);
// Função para tratar o texto antes de fazer todo o trabalho
void cleanFiles(); // Para mais detalhes ver clean_files.py
