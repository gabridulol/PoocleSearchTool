// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

#include "../headers/poocleMenu.h"

void poocleMenu(typePatPointer* patTree, typeDocList* docList) {
    int loop = 1;
    int chooseOption;
    char searchLine[sizeLine];
    while (loop) {
        printf("=======================\n");
        printf(ANSI_COLOR_BLUE "P" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "o" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "o" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "c" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "l" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "e" ANSI_COLOR_RESET);
        printf(" Search Tool");
        printf("\n=======================\n");
        printf("1. Insert source file\n");
        printf("2. Build inverted index\n");
        printf("3. Print inverted index\n");
        printf("4. Search on Poocle\n");
        printf("5. Exit");
        printf("\n=======================\n");
        printf("Option: "); scanf("%d", &chooseOption);
        system("cls || clear");
        switch (chooseOption) {
        case 1 :
            printf("\n=======================\n");
            printf("1. Insert source file");
            printf("\n=======================\n");
            getFile(docList);
            break;
        case 2 :
            printf("\n=======================\n");
            printf("2. Build inverted index");
            printf("\n=======================\n\n");
            buildInvertedIndex(patTree, docList);
            printf("\n");
            break;
        case 3 :
            printf("\n=======================\n");
            printf("3. Print inverted index");
            printf("\n=======================\n");
            printInvertedIndex(patTree);
            break;
        case 4 :
            printf("\n=======================\n");
            printf("4. Search on Poocle");
            printf("\n=======================\n\n");
            printf("Search: ");
            getchar();
            fgets(searchLine, sizeof(searchLine), stdin);
            if (searchLine[0] == '\n') {
                    break;
            }
            searchTool(patTree, docList, searchLine);
            printf("\nSearch results:\n\n");
            printDocByRev(docList);
            printf("\n");
            break;
        case 5 :
            printf("\n=======================\n");
            printf("4. Exit");
            printf("\n=======================\n\n");
            printf("Thank you for using ");
            printf(ANSI_COLOR_BLUE "P" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_RED "o" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_YELLOW "o" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_BLUE "c" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_GREEN "l" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_RED "e" ANSI_COLOR_RESET);
            printf("!\n\n");
            loop = 0;
            break;
        default:
            printf("Invalid option! Try again...\n");
        }
    }
}
