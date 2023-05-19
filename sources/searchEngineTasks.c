// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/searchEngineTasks.h"

void getFile(typeDocList* docList) {
    readSrcFile(docList, "entrada.txt");
}

void buildInvertedIndex(typePatPointer* patTree, typeDocList* docList) {
    readDocFile(patTree, docList);
}

void printInvertedIndex(typePatPointer* patTree) {
    printPatTree(*patTree);
}

void searchTool(typePatPointer* patTree, typeDocList* docList) {
    char searchWorlde[size];
    int nSearchWordles = 0;
    float rDoc[docList -> nDocs];
    while (1) {
        fgets(searchWorlde, sizeof(searchWorlde), stdin);
        if (strcmp(searchWorlde, "\n") == 0) {
            break;
        }
        searchWorlde[strcspn(searchWorlde, "\n")] = '\0';
        printf("Worlde: %s\n", searchWorlde); // mathRelevance
        nSearchWordles++;
    }
    printDocB
}

// Função para calcular a relevância de todos os documentos
void relevanceofDocs(typeDocList *lista, typePatPointer *root, typeWordle *searchWords, int numberOfwords){
    int counter = 0;
    typeDocPointer aux;
    aux = lista->firstCell;
    while(counter > lista->nDocs){
        if(aux == NULL){
            return 0;
        }
    aux->itemDoc.rDoc = relevanceOfDoc(aux->itemDoc, lista->nDocs, &root, &searchWords, numberOfwords);
    aux = aux->nextCell;
    counter++;
    }
}

// Função do cálculo de relevância do documento i com n palavras
double relevanceOfDoc(typeDoc doc, int nDocs, typePatPointer *root, typeWordle *searchWords, int numberOfwords){
    double sumWeight = 0;
    int counter = 0;
    while(counter < numberOfwords){
        sumWeight += weightOfWord(int lista.Docs, typePatPointer *root, typeWordle *j, int idDoc);
    }
    return (1/doc.nWordle) * sumWeight;
}

// Função do cálculo do peso da palavra j para o documento i
double weightOfWord(int lista.Docs, typePatPointer *root, typeWordle *j, int idDoc); // N receberá nDocs da estrutura typeDocList list