#include <stdio.h>
#include <stdlib.h>

// Função de comparação para o qsort (ordem crescente)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função que calcula a soma das diferenças absolutas
int calcularSomaDiferencas(int listaEsq[], int listaDir[], int tamanho) {
    // 1. Ordenar ambas as listas
    qsort(listaEsq, tamanho, sizeof(int), compare);
    qsort(listaDir, tamanho, sizeof(int), compare);

    int soma_total = 0;

    // 2. Emparelhar e calcular a diferença absoluta
    for (int i = 0; i < tamanho; i++) {
        soma_total += abs(listaEsq[i] - listaDir[i]);
    }

    return soma_total;
}

int main() {
    // Listas do exemplo
    int listaEsquerda[] = {260,3557,1594,3008,1395,968,4113,4530,1006,962,2942,365,2082,
        4852,767,3821,695,4712,3671,4901,3590,4831,4738,3057,1616,4790,640,679,2335,2006,
        2972,1098,4095,319,3454,223,2289,1760,3905,1126,1123,4506,813,1770,238,4094,1220,
        2844,2366,534,226,394,1363,3738,2844,4590,1550,159,3623,4947,4947};
    int listaDireita[] = {2385,2217,272,539,4247,2385,3496,4885,623,2420,3144,1968,735,4915,
        1625,3534,1042,1011,4679,4152,244,2295,3818,396,2692,1815,2991,33,2669,4397,4553,547,
        825,1210,4662,211,3808,3377,2761,625,2335,1868,2995,2776,2767,2439,4874,4331,556,1301,
        3872,560,94,3984,3755,4789,1407,3015,193,2769,2769};
    
    int tamanho = sizeof(listaEsquerda) / sizeof(listaEsquerda[0]);

    int resultado = calcularSomaDiferencas(listaEsquerda, listaDireita, tamanho);

    printf("A soma das diferencas absolutas e: %d\n", resultado);

    return 0;
}