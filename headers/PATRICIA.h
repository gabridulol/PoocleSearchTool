// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação de PATRICIA e suas funções

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #include "../headers/TF-IDF.h"

// typedef unsigned char TipoDib;
// typedef unsigned char TipoIndexAmp;
// typedef struct {
//    char *word;
//    typeLinkedList LinkedList;
// }typeWord;

// typedef enum
// {
//    internal, external 
// } typeNode;

// typedef struct typePatty *typePPointer;
// typedef struct tipePatty
// {
//     typeNode Interno_Externo;
//     union
//     {
//         struct
//         {
//             TipoIndexAmp Index;
//             typePPointer left, right;
//             char letterActually;
//         } nodeInternal;
//         typeWord patword;
//     } NODE;
// } typePatty;

// void startPatty(typePatty *patty);