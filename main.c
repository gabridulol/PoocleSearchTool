#include "./headers/GTKInterface.h"

typedef struct GTKData {
    typePatPointer patTree;
    typeDocList docList;
} typeGTKData;

// Callback function para os botões
void button_insert_source_clicked(GtkWidget *widget, gpointer data) {
    typeGTKData* GTKData = (typeGTKData*) data;
    g_print("Insert source file button clicked!\n");
    // Adicione aqui o código para a funcionalidade do botão "Insert source file"
    getFile(&GTKData -> docList);
}

void button_build_index_clicked(GtkWidget *widget, gpointer data) {
    typeGTKData* GTKData = (typeGTKData*) data;
    g_print("Build inverted index button clicked!\n");
    // Adicione aqui o código para a funcionalidade do botão "Build inverted index"
    buildInvertedIndex(&GTKData -> patTree, &GTKData -> docList);
}

void button_print_index_clicked(GtkWidget *widget, gpointer data) {
    typeGTKData* GTKData = (typeGTKData*) data;
    g_print("Print inverted index button clicked!\n");
    // Adicione aqui o código para a funcionalidade do botão "Print inverted index"
    printInvertedIndex(&GTKData -> patTree);
}

void button_search_clicked(GtkWidget *widget, gpointer data) {
    // typeGTKData* GTKData = (typeGTKData*) data;
    g_print("Search on Poocle button clicked!\n");
    // Adicione aqui o código para a funcionalidade do botão "Search on Poocle"
}

void button_exit_clicked(GtkWidget *widget, gpointer data) {
    g_print("Exit button clicked. Exiting...\n");
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    typeGTKData GTKData;

    gtk_init(&argc, &argv);

    // Crie a janela principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Poocle Search Tool");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Defina o estilo para o título "Poocle"
    const gchar* title_markup = "<span foreground='#4285F4'  font_weight='bold' font='24'><big>P</big></span>"
                                 "<span foreground='#DB4437' font_weight='bold' font='24'><big>o</big></span>"
                                 "<span foreground='#F4B400' font_weight='bold' font='24'><big>o</big></span>"
                                 "<span foreground='#4285F4' font_weight='bold' font='24'><big>c</big></span>"
                                 "<span foreground='#0F9D58' font_weight='bold' font='24'><big>l</big></span>"
                                 "<span foreground='#DB4437' font_weight='bold' font='24'><big>e</big></span>"
                                 "<span foreground='#FFFFFF' font_weight='bold' font='24'><big> Search Tool</big></span>";
    GtkWidget* title_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(title_label), title_markup);

    // Crie os botões
    GtkWidget *button_insert_source = gtk_button_new_with_label("Insert source file");
    GtkWidget *button_build_index = gtk_button_new_with_label("Build inverted index");
    GtkWidget *button_print_index = gtk_button_new_with_label("Print inverted index");
    GtkWidget *button_search = gtk_button_new_with_label("Search on Poocle");
    GtkWidget *button_exit = gtk_button_new_with_label("Exit");

    // Conecte os sinais "clicked" dos botões às funções de callback
    g_signal_connect(button_insert_source, "clicked", G_CALLBACK(button_insert_source_clicked), &GTKData);
    g_signal_connect(button_build_index, "clicked", G_CALLBACK(button_build_index_clicked), &GTKData);
    g_signal_connect(button_print_index, "clicked", G_CALLBACK(button_print_index_clicked), &GTKData);
    g_signal_connect(button_search, "clicked", G_CALLBACK(button_search_clicked), NULL);
    g_signal_connect(button_exit, "clicked", G_CALLBACK(button_exit_clicked), NULL);

    // Crie um layout para os botões
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(box), title_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_insert_source, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_build_index, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_print_index, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_search, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_exit, TRUE, TRUE, 0);

    // Adicione o layout à janela
    gtk_container_add(GTK_CONTAINER(window), box);

    // Mostre todos os widgets
    gtk_widget_show_all(window);

    // Inicie o loop principal do GTK
    gtk_main();

    return 0;
}
