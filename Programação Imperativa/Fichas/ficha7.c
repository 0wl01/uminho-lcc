#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} * Palavras;

/*
Assume-se que a lista n ̃ao tem palavras repetidas.
Apresente defini ̧c ̃oes para as seguintes fun ̧c ̃oes:

1. void libertaLista (Palavras) que liberta todo o espa ̧co (da heap) ocupado pela lista de
palavras.
*/

void libertaLista (Palavras l) {
    Palavras temp; 

    while (l != NULL) {
        temp = l->prox; // save next

        free(l->palavra); // free attached string
        free(l); // free the cell itself

        l = temp;
    }
}

/*
2. Lista quantasP (Palavras l) que calcula quantas palavras (diferentes) existem armazenadas.
*/

int quantasP (Palavras l) {
    if (l == NULL) return 0;
    int counter = 0;
    while(l != NULL) {
        l = l->prox;
        counter++;
    }
    return counter;
}