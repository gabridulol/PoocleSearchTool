// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/docList.h"

int isDocListEmpty(typeDocList docList) {
    return (docList.firstCell == docList.lastCell);
}

void startDocList(typeDocList* docList) {
    docList -> firstCell = (typeDocCell*) malloc(sizeof(typeDocCell));
    docList -> firstCell -> nextCell = NULL;
    docList -> lastCell = docList -> firstCell;
    docList -> nDocs = 0;
}

void insertDocList(typeDocList* docList, char* docName, int idDoc) {
    docList -> lastCell -> nextCell = (typeDocCell*) malloc(sizeof(typeDocCell));
    docList -> lastCell = docList -> lastCell -> nextCell;
    fillDoc(docList, docName, idDoc);
    docList -> lastCell -> nextCell = NULL;
    docList -> nDocs++;
}

void fillDoc(typeDocList* docList, char* docName, int idDoc) {
    docList -> lastCell -> itemDoc.docName = (char*) malloc(sizeof(char) * (strlen(docName) + 1));
    strcpy(docList -> lastCell -> itemDoc.docName, docName);
    docList -> lastCell -> itemDoc.idDoc = idDoc;
    docList -> lastCell -> itemDoc.nWordle = 0;
}

void docReset(typeDocList* docList) {
    typeDocPointer auxReset = docList -> firstCell -> nextCell;
    while (auxReset != NULL) {
        auxReset -> itemDoc.rDoc = 0;
        auxReset = auxReset -> nextCell;
    }
}

typeDocPointer findDoc(typeDocList docList, int idDoc) {
    typeDocPointer auxFind = docList.firstCell -> nextCell;
    while (auxFind != NULL) {
        if (auxFind -> itemDoc.idDoc == idDoc) {
            return auxFind;
        }
        auxFind = auxFind -> nextCell;
    }
    return NULL;
}

typeDocPointer findDocByRev(typeDocList docList, double rDoc) {
    typeDocPointer auxFind = docList.firstCell -> nextCell;
    while (auxFind != NULL) {
        if (auxFind -> itemDoc.rDoc == rDoc) {
            return auxFind;
        }
        auxFind = auxFind -> nextCell;
    }
    return NULL;
}

void printDocList(typeDocList docList) {
    typeDocPointer auxPrint = docList.firstCell -> nextCell;
    while (auxPrint != NULL) {
        printf("docName: %s\n", auxPrint -> itemDoc.docName);
        printf("idDoc: %d\n", auxPrint -> itemDoc.idDoc);
        printf("rDoc: %lf\n", auxPrint -> itemDoc.rDoc);
        printf("nWordle: %d\n\n", auxPrint -> itemDoc.nWordle);
        auxPrint = auxPrint -> nextCell;
    }
}

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