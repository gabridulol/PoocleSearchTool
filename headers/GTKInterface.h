// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/poocleMenu.h"

typedef struct GTKData {
    typePatPointer patTree;
    typeDocList docList;
} typeGTKData;

void button_insert_source_clicked(GtkWidget *widget, gpointer data);
void button_build_index_clicked(GtkWidget *widget, gpointer data);
void button_print_index_clicked(GtkWidget *widget, gpointer data);
void button_search_clicked(GtkWidget *widget, gpointer data);
void button_exit_clicked(GtkWidget *widget, gpointer data);
void gtkmain(int argc, char *argv[]);