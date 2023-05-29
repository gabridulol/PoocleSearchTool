// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação do Poocle Search Tool para GTK

// Os códigos implementados aqui foram feitos com o auxílio do Chat GPT (https://chat.openai.com/) 
// e utilizando a documentação disponpivel do GTK (https://www.gtk.org/)

#include "../headers/searchEngineTasks.h"

// Estrutura GTKData para realizar "links" no menu
typedef struct GTKData {
    typePatPointer patTree; // Árvore PATRICIA
    typeDocList docList; // Lista de Documentos
} typeGTKData;

// Função GTK para imprimir a lista de documentos
void GTKPrintDocList(typeDocList docList);
// Função GTK para imprimir a árvore PATRICIA em ordem alfabética
void GTKPrintPatTree(typePatPointer patTree);
void GTKPrintPatTreeRecursive(typePatPointer patTree, GtkTextBuffer *buffer);
// Funções GTK para Search on Poocle
void GTKSearchTool(typeGTKData *GTKData);
void GTKPrintDocByRev(typeGTKData *GTKData);
// Função do botão "Insert source file" e suas operações
void button_insert_source_clicked(GtkWidget *widget, gpointer data);
// Função do botão "Build inverted index" e suas operações
void button_build_index_clicked(GtkWidget *widget, gpointer data);
// Função do botão "Print inverted index" e suas operações
void button_print_index_clicked(GtkWidget *widget, gpointer data);
// Função do botão "Search on Poocle" e suas operações
void button_search_clicked(GtkWidget *widget, gpointer data);
// Função do botão "Exit" e suas operações
void button_exit_clicked(GtkWidget *widget, gpointer data);
// Função Poocle Menu para GTK
void gtkmain(int argc, char *argv[]);