// Gabriel Rodrigues Marques - 5097
// Alan Araújo dos Reis - 5096
// Marcos Biscotto de Oliveira - 4236
// Luiz César Galvão Lima - 4216

// Implementação de PATRICIA e suas funções

#include "../headers/searchTerm.h"

typedef enum {
    inn, ext
} typeNode;
typedef struct typePatNode* typePatPointer;
typedef struct typePatNode {
    typeNode InnExt;
    union {
        struct {
            int index;
            char charIndex;
            typePatPointer left;
            typePatPointer right;
        } typeInnNode;
        typeSearchTerm data;
    } typeExtNode;
} typePatNode;