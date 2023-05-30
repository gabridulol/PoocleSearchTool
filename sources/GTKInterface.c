// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/GTKInterface.h"

void GTKPrintDocList(typeDocList docList) {
    GtkWidget *window;
    GtkWidget *scrolled_window;
    GtkWidget *text_view;
    GtkTextBuffer *buffer;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Documents List");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    typeDocPointer auxPrint = docList.firstCell->nextCell;
    while (auxPrint != NULL) {
        char bufferText[256];
        g_snprintf(bufferText, sizeof(bufferText), "docName: %s\n", auxPrint->itemDoc.docName);
        gtk_text_buffer_insert_at_cursor(buffer, bufferText, -1);
        g_snprintf(bufferText, sizeof(bufferText), "idDoc: %d\n", auxPrint->itemDoc.idDoc);
        gtk_text_buffer_insert_at_cursor(buffer, bufferText, -1);
        g_snprintf(bufferText, sizeof(bufferText), "rDoc: %lf\n", auxPrint->itemDoc.rDoc);
        gtk_text_buffer_insert_at_cursor(buffer, bufferText, -1);
        g_snprintf(bufferText, sizeof(bufferText), "nWordle: %d\n\n", auxPrint->itemDoc.nWordle);
        gtk_text_buffer_insert_at_cursor(buffer, bufferText, -1);
        auxPrint = auxPrint->nextCell;
    }
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);
    gtk_widget_show_all(window);
    gtk_main();
}

void GTKPrintPatTree(typePatPointer patTree) {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Inverted Index");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(scrolled_window), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD_CHAR);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    if (patTree != NULL) {
        GTKPrintPatTreeRecursive(patTree, buffer);
    }
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);
    gtk_widget_show_all(window);
    gtk_main();
}

void GTKPrintPatTreeRecursive(typePatPointer patTree, GtkTextBuffer *buffer) {
    if (patTree != NULL) {
        if (patTree->innext == inn) {
            GTKPrintPatTreeRecursive(patTree->typeExtNode.typeInnNode.left, buffer);
        }
        if (patTree->innext == ext) {
            gchar bufferText[256];
            g_snprintf(bufferText, sizeof(bufferText), "%s ", patTree->typeExtNode.wordleData.wordChar);
            gtk_text_buffer_insert_at_cursor(buffer, bufferText, -1);
            typeIndexPointer auxIndex = patTree->typeExtNode.wordleData.indexList->firstCell->nextCell;
            while (auxIndex != NULL) {
                g_snprintf(bufferText, sizeof(bufferText), " <%d, %d> ", auxIndex->itemIndex.qtde, auxIndex->itemIndex.idDoc);
                gtk_text_buffer_insert_at_cursor(buffer, bufferText, -1);
                auxIndex = auxIndex->nextCell;
            }
            gtk_text_buffer_insert_at_cursor(buffer, "\n\n", -1);
        }
        if (patTree->innext == inn) {
            GTKPrintPatTreeRecursive(patTree->typeExtNode.typeInnNode.right, buffer);
        }
    }
}

void GTKSearchTool(typeGTKData *GTKData) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *entry;
    gint result;
    dialog = gtk_dialog_new_with_buttons("Search on Poocle",
                                         GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL)),
                                         GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                         "Search", GTK_RESPONSE_ACCEPT,
                                         "Cancel", GTK_RESPONSE_CANCEL,
                                         NULL);
    gtk_window_set_default_size(GTK_WINDOW(dialog), 400, 80);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Enter search line...");
    gtk_container_add(GTK_CONTAINER(content_area), entry);
    gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_ACCEPT);
    gtk_widget_show_all(dialog);
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    if (result == GTK_RESPONSE_ACCEPT) {
        const gchar *search_query = gtk_entry_get_text(GTK_ENTRY(entry));
        char searchLine[sizeLine]; strcpy(searchLine, search_query);
        searchTool(&GTKData->patTree, &GTKData->docList, searchLine);
        gtk_widget_destroy(dialog);
        GTKPrintDocByRev(GTKData);
        return;
    }
    else {
        gtk_widget_destroy(dialog);
    }
}

void GTKPrintDocByRev(typeGTKData *GTKData) {
    typeDocPointer auxDoc = GTKData->docList.firstCell->nextCell;
    double array[GTKData->docList.nDocs];
    int count = 0;
    typeDocPointer auxPrint;
    while (auxDoc != NULL) {
        array[count] = auxDoc->itemDoc.rDoc;
        count++;
        auxDoc = auxDoc->nextCell;
    }
    qsort(array, GTKData->docList.nDocs, sizeof(double), cmp);
    GtkWidget *window;
    GtkWidget *scrolled_window;
    GtkWidget *text_view;
    GtkTextBuffer *buffer;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Search Results");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 100);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    count = 0;
    while (count < GTKData->docList.nDocs) {
        if (array[count] != 0) {
            char bufferText[256];
            auxPrint = findDocByRev(GTKData->docList, array[count]);
            g_snprintf(bufferText, sizeof(bufferText), "Text %d (%s)\n", auxPrint->itemDoc.idDoc, auxPrint->itemDoc.docName);
            gtk_text_buffer_insert_at_cursor(buffer, bufferText, -1);
        }
        count++;
    }
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);
    gtk_widget_show_all(window);
    gtk_main();
    docReset(&GTKData->docList);
}

void button_insert_source_clicked(GtkWidget *widget, gpointer data) {
    typeGTKData *GTKData = (typeGTKData*) data;
    g_print("Insert source file button clicked!\n");
    getFile(&GTKData -> docList);
    docReset(&GTKData->docList);
    GTKPrintDocList(GTKData -> docList);
}

void button_build_index_clicked(GtkWidget *widget, gpointer data) {
    typeGTKData *GTKData = (typeGTKData*) data;
    g_print("Build inverted index button clicked!\n");
    buildInvertedIndex(&GTKData -> patTree, &GTKData -> docList);
}

void button_print_index_clicked(GtkWidget *widget, gpointer data) {
    typeGTKData *GTKData = (typeGTKData*) data;
    g_print("Print inverted index button clicked!\n");
    GTKPrintPatTree(GTKData -> patTree);
}

void button_search_clicked(GtkWidget *widget, gpointer data) {
    typeGTKData *GTKData = (typeGTKData*) data;
    g_print("Search on Poocle button clicked!\n");
    GTKSearchTool(GTKData);
}

void button_exit_clicked(GtkWidget *widget, gpointer data) {
    g_print("Exit button clicked. Exiting...\n");
    gtk_main_quit();
}

void gtkmain(int argc, char *argv[]) {
    typeGTKData GTKData;
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Poocle Search Tool");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    const gchar* title_markup = "<span foreground='#4285F4'  font_weight='bold' font='24'><big>P</big></span>"
                                 "<span foreground='#DB4437' font_weight='bold' font='24'><big>o</big></span>"
                                 "<span foreground='#F4B400' font_weight='bold' font='24'><big>o</big></span>"
                                 "<span foreground='#4285F4' font_weight='bold' font='24'><big>c</big></span>"
                                 "<span foreground='#0F9D58' font_weight='bold' font='24'><big>l</big></span>"
                                 "<span foreground='#DB4437' font_weight='bold' font='24'><big>e</big></span>"
                                 "<span foreground='#FFFFFF' font_weight='bold' font='24'><big> Search Tool</big></span>";
    GtkWidget* title_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(title_label), title_markup);
    GtkWidget *button_insert_source = gtk_button_new_with_label("Insert source file");
    GtkWidget *button_build_index = gtk_button_new_with_label("Build inverted index");
    GtkWidget *button_print_index = gtk_button_new_with_label("Print inverted index");
    GtkWidget *button_search = gtk_button_new_with_label("Search on Poocle");
    GtkWidget *button_exit = gtk_button_new_with_label("Exit");
    g_signal_connect(button_insert_source, "clicked", G_CALLBACK(button_insert_source_clicked), &GTKData);
    g_signal_connect(button_build_index, "clicked", G_CALLBACK(button_build_index_clicked), &GTKData);
    g_signal_connect(button_print_index, "clicked", G_CALLBACK(button_print_index_clicked), &GTKData);
    g_signal_connect(button_search, "clicked", G_CALLBACK(button_search_clicked), &GTKData);
    g_signal_connect(button_exit, "clicked", G_CALLBACK(button_exit_clicked), NULL);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), title_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_insert_source, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_build_index, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_print_index, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_search, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_exit, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main();
}