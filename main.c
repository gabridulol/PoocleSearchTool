// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "./headers/poocleMenu.h"
#include "./headers/include.h"

GtkBuilder *builder;
GtkWidget *window; 


void on_main_window_destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void user_instructions(char text[600]){
    GtkMessageDialog *mensagem_dialogo = gtk_builder_get_object(builder, "user_instructions");
    
    g_object_set(mensagem_dialogo, "text", text, NULL);

    gtk_widget_show_all(mensagem_dialogo);
    gtk_dialog_run(mensagem_dialogo);
    gtk_widget_hide(mensagem_dialogo);
    
}

void on_button_instructions_clicked(GtkWidget *widget, gpointer data){
    user_instructions("1º Informar o Arquivo de Entrada: Informe o nome  do Arquivo de Texto que contém o número de documentos a serem lidos e seus respectivos títulos.\n\n2º Construir o Índice Invertido: Constroi o Índice Invertido a partir dos documentos lidos pelo programa.\n\n3º Imprimir o Índice Invertido: Após utilizar a função anterior, o programa lhe informará o Índice Invertido construído.\n\n4º Realizar Busca de Termos: Informe um ou mais termos para serem buscados. Em caso de mais de um termo, separe-os por espaços em branco.");
}

void on_button_enter_file_clicked(GtkWidget *widget, typeDocList docList){
    getFile(&docList);
}

void on_button_build_inverted_index_clicked(GtkWidget *widget, typePatPointer patTree, typeDocList docList){
    buildInvertedIndex(&patTree, &docList);
}

void on_button_print_inverted_index_clicked(GtkWidget *widget, typePatPointer* patTree){
    printInvertedIndex(&patTree);
}

void on_button_search_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}


int main(int argc, char **argv){
    typePatPointer patTree;
    typeDocList docList;
    gtk_init(&argc, &argv);
    builder = gtk_builder_new_from_file("GTKProject/MenudeOpcoes.glade");
    
    gtk_builder_add_callback_symbols(
        builder,
        "on_main_window_destroy",                           G_CALLBACK(on_main_window_destroy),
        "on_button_instructions_clicked",                   G_CALLBACK(on_button_instructions_clicked),
        "on_button_enter_file_clicked",                     G_CALLBACK(on_button_enter_file_clicked),
        "on_button_build_inverted_index_clicked",           G_CALLBACK(on_button_build_inverted_index_clicked),
        "on_button_print_inverted_index_clicked",           G_CALLBACK(on_button_print_inverted_index_clicked),
        "on_button_search_clicked",                         G_CALLBACK(on_button_search_clicked),
    NULL);

    gtk_builder_connect_signals(builder, NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}