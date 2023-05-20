// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/fileManagement.h"


int readSrcFile(typeDocList* docList, char* srcFileName) {
    char srcDirectory[size] = "files/"; 
    strcat(srcDirectory, srcFileName);
    FILE* srcFile = NULL;
    srcFile = fopen(srcDirectory, "r");
    if (srcFile == NULL) {
        printf("Could not open the file ''%s''. Try again...\n", srcFileName);
        return -1;
    }
    startDocList(docList);
    writeSrcFile(docList, srcFile);
    fclose(srcFile);
}

void writeSrcFile(typeDocList* docList, FILE* srcFile) {
    int nDocs;
    char docName[size];
    int idDoc = 1;
    fscanf(srcFile, "%d", &nDocs);
    while (idDoc <= nDocs) {
        fscanf(srcFile, "%s", docName);
        insertDocList(docList, docName, idDoc);
        idDoc++;
    }
}

void readDocFile(typePatPointer* patTree, typeDocList* docList) {
    startPatTree(patTree);
    cleanFiles();
    typeDocPointer doc = docList -> firstCell -> nextCell;
    while (doc != NULL) {
        writeDocFile(patTree, docList, doc);
        doc = doc -> nextCell;
    }
}

int writeDocFile(typePatPointer* patTree, typeDocList* docList, typeDocPointer doc) {
    char textWord[size];
    char docDirectory[size] = "files/"; 
    strcat(docDirectory, doc -> itemDoc.docName);
    int idDoc = doc -> itemDoc.idDoc;
    FILE* docFile = NULL;
    docFile = fopen(docDirectory, "r");
    if (docFile == NULL) {
        printf("Could not open the file ''%s''. Try again...\n", doc -> itemDoc.docName);
        return -1;
    }
    while (fscanf(docFile, "%s", textWord) != EOF) {
        *patTree = insertPatTree(patTree, *docList, textWord, idDoc);
    }
    fclose(docFile);
}

void cleanFiles() {
    system("python3 files/fileManagement.py");
}