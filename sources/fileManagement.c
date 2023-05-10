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
    char docName[SIZEOFCHAR];
    FILE *srcFile = NULL;
    srcFile = fopen(fileDirectory, "r");
    if (srcFile == NULL) {
        return -1;
    }
    fscanf(srcFile, "%d", &filesInfile);
    for (int i = 0; i < filesInfile; i++) {
        fscanf(srcFile, "%s", docName);
        readingDocFiles(docName);
    }
    fclose(srcFile);
}

void readingDocFiles(char* docName) {
    char docDirectory[] = "files/";
    char docNewName[SIZEOFCHAR]; 
    strcpy(docNewName, docName);
    strcat(docDirectory, docNewName);
    readDocText(docDirectory);
}

int readDocText(char* docDirectory) {
    int isIdDoc;
    char textWord[SIZEOFCHAR];
    FILE *docFile = NULL;
    docFile = fopen(docDirectory, "r");
    if (docFile == NULL) {
        return -1;
    }
    while (fgets(textWord, sizeof(textWord), docFile) != NULL) {
        printf("%s\n", textWord);
    }
    fclose(docFile);
    printf("%d", isIdDoc);
    isIdDoc++;
}

void cleanFiles() {
    system("python3 files/clean_files.py");
}