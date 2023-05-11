// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/fileManagement.h"

void readingFolderFiles(char* fileName) {
    char fileDirectory[] = "files/";
    char fileNewName[SIZEOFCHAR]; 
    strcpy(fileNewName, fileName);
    strcat(fileDirectory, fileNewName);
    cleanFiles();
    readSrcFile(fileDirectory);
}

int readSrcFile(char* fileDirectory) {
    int filesInfile;
    int isIdDoc = 1;
    int isQtde = 1;
    char docName[SIZEOFCHAR];
    FILE *srcFile = NULL;
    srcFile = fopen(fileDirectory, "r");
    if (srcFile == NULL) {
        return -1;
    }
    fscanf(srcFile, "%d", &filesInfile);
    for (int i = 0; i < filesInfile; i++) {
        fscanf(srcFile, "%s", docName);
        readingDocFiles(docName, isQtde, isIdDoc);
        isIdDoc++;
    }
    fclose(srcFile);
}

void readingDocFiles(char* docName, int isQtde, int isIdDoc) {
    char docDirectory[] = "files/";
    char docNewName[SIZEOFCHAR]; 
    strcpy(docNewName, docName);
    strcat(docDirectory, docNewName);
    readDocText(docDirectory, isQtde, isIdDoc);
}

int readDocText(char* docDirectory, int isQtde, int isIdDoc) {
    char textWord[SIZEOFCHAR];
    FILE *docFile = NULL;
    docFile = fopen(docDirectory, "r");
    if (docFile == NULL) {
        return -1;
    }
    while (fscanf(docFile, "%s", textWord) != EOF) {
        printf("%s <%d, %d>\n\n", textWord, isQtde, isIdDoc);
    }
    fclose(docFile);
}

void cleanFiles() {
    system("python3 files/fileManagement.py");
}