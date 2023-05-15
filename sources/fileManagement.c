// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/fileManagement.h"

void readingFolderFiles(typeDocList* docList, char* fileName) {
    char fileDirectory[] = "files/";
    char fileNewName[SIZEOFCHAR]; 
    strcpy(fileNewName, fileName);
    strcat(fileDirectory, fileNewName);
    cleanFiles();
    readSrcFile(docList, fileDirectory);
}

int readSrcFile(typeDocList* docList, char* fileDirectory) {
    int filesInfile;
    char docName[SIZEOFCHAR];
    int isIdDocs = 1;
    FILE *srcFile = NULL;
    srcFile = fopen(fileDirectory, "r");
    if (srcFile == NULL) {
        return -1;
    }
    startDocList(docList);
    fscanf(srcFile, "%d", &filesInfile);
    for (int i = 0; i < filesInfile; i++) {
        fscanf(srcFile, "%s", docName);
        insertDocList(docList, docName, isIdDocs);
        isIdDocs++;
    }
    fclose(srcFile);
}

void readingDocFiles(typeDocList* docList, char* docName, int isIdDoc) {
    char docDirectory[] = "files/";
    char docNewName[SIZEOFCHAR]; 
    strcpy(docNewName, docName);
    strcat(docDirectory, docNewName);
    readDocText(docList, docDirectory, isIdDoc);
}

int readDocText(typeDocList* docList, char* docDirectory, int isIdDoc) {
    char textWord[SIZEOFCHAR];
    char isQtde = 1;
    FILE *docFile = NULL;
    docFile = fopen(docDirectory, "r");
    if (docFile == NULL) {
        return -1;
    }
    while (fscanf(docFile, "%s", textWord) != EOF) {
        // Insere na PATRÍCIA
        printf("%s <%d, %d>\n\n", textWord, isQtde, isIdDoc);
    }
    fclose(docFile);
}

void cleanFiles() {
    system("python3 files/fileManagement.py");
}