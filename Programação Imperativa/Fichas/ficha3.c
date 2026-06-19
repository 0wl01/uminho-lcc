#include <stdio.h>
#include <stdlib.h>

/*
1. Diga, justificando, qual o output de cada um dos seguintes excertos de c´odigo C.
*/

/*
(a)
int main () {

int x [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int *y, *z, i;
y = x; primeira posição no array?
z = x+3; quarta posição no array?

for (i=0; i<5; i++) {
    printf ("%d %d %d\n",
    x[i], *y, *z);
    y = y+1; z = z+2;
}

Output: 
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12
*/

/*
(b)
int main () {
    int i, j, *a, *b;

    i=3; j=5;
    a = b = 42; // MÁ PRÁTICA a e b guardam endereço 42
    a = &i; b = &j; // a aponta para i = 3 e b aponta para j = 5
    i++; //i é incrementado logo i = 4 e por consequência a = 4
    j = i + *b; // j = 4 + 5 = 9  
    b = a; // b tem o mesmo endereço que a agora, a = b = i
    j = j + *b; // j = 9 + 4 = 13

    printf ("%d\n", j);
    
    return 0;
}

Output: 13
 */

 /*
 2. Defina uma funcao void swapM (int *x, int *y) que
troca o valor de duas variaveis. Por exemplo, o codigo ao
lado devera imprimir no ecran 5 3.

int x = 3, y = 5;
swapM (&x, &y);
printf ("%d %d\n", x, y);
 */

 void swapM(int *x, int *y) {
    int temp = *x;

    *x = *y;
    *y = temp;
 }

 /*
 3. Defina uma funcao void swap (int v[], int i, int j) que troca o valor das posicoes i e
j do vector v.
 */

 void swap (int v[], int i, int j) {
    int temp = v[i];

    v[i] = v[j];
    v[j] = temp;
 }

 /*
 4. Defina uma funcao int soma (int v[], int N) que calcula a soma dos elementos de um vector v
com N inteiros.
 */

 int soma (int v[], int N) {
    int i, resultado = 0;

    for (i = 0; i < N; i++) {
        resultado = resultado + v[i];
    }
    return resultado;
 }

 /*
 5. Defina uma funcao void inverteArray (int v[], int N) que inverte um array. Escreva duas
versoes, cada uma usando uma das funcoes das alıneas anteriores.
 */

void inverteArray (int v[], int N) {
    int i;
    N--; // last valid index is in N - 1, not N

    for (i = 0; i < N; i++) {
        swap(v, i, N);
        N--;
    }
}

void Arrayinverte (int v[], int N) {
    int i, j = N -1;

    for (i = 0; i < j; i++, j--) {
        swapM(&v[i], &v[j]); // swapM receives pointers so we give it the adress of v positions
    }
}

/*
6. Defina uma funcao int maximum (int v[], int N, int *m) que coloca em *m o maior dos
elementos do vector v.
A funcao devera retornar 0 sse tal for possıvel (i.e., quando N>0)
*/

int maximum (int v[], int N, int *m) {
    int i;

    if (N <= 0) {
        return -1;
    }

    *m = v[0];

    for (i = 1; i < N; i++) {
        if (v[i] > *m) {
            *m = v[i];
        }
    }
    return 0;
}

/*
7. Defina uma funcao void quadrados (int q[], int N) que preenche o vector q com os quadrados
dos primeiros N numeros naturais ({0,1,4,9,...}.
Note que, uma vez que (a + 1)2= a2+ (2 ∗a + 1) esta funcao nao precisa de calcular o quadrado
de nenhum dos numeros explicitamente.
*/

void quadrados (int q[], int N) {
    int i;

    q[0] = 0;

    for (i = 1; i < N; i++) {
        // q[i-1] é o a^2. O (i-1) é o a.
        q[i] = q[i - 1] + (2 * (i - 1) + 1);
    }
}

/*
8.
O triangulo de Pascal e uma forma de calcular os
coeficientes da expansao do binomio de Newton.
Ao lado relembramos as 5 primeiras linhas.
Note que a linha n do triangulo tem n elementos
e que a linha n + 1 pode ser obtida a partir da
linha n usando o seguinte processo:
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
1 5 10 10 5 1
•acrescenta-se um 1 no final, i.e., coloca-se 1 na posicao n.
•para todos os elementos (desde n-1 at ́e 1, por esta ordem) substitui-se o elemento nessa
posicao pela sua soma com o que esta na posicao anterior.
*/

/* 
a) Defina uma funcao void pascal (int v[], int N) que preenche o vector v com a N- ́esima
linha do triˆangulo de Pascal.
*/

void pascal (int v[], int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        v[i] = 1; //ultimo elemento de cada linha é 1
        for (j = i - 1; j > 0; j--) {
            v[j] = v[j] + v[j - 1]; // adiciona de trás para a frente
        }
        v[0] = 1; // primeiro elemento também é 1
    } 
}

/*
(b) Adapte a funcao que definiu atras para, em vez de preencher um array com a linha N do
triangulo, escreva no ecran as N primeiras linhas do triangulo.
*/

void pascalPrint (int N) {
    int v[N]; //array local
    int i, j, k;

    for (i = 0; i < N; i++) {
        v[i] = 1; //ultimo elemento de cada linha é 1
        for (j = i - 1; j > 0; j--) {
            v[j] = v[j] + v[j - 1]; // adiciona de trás para a frente
        }
        v[0] = 1; // primeiro elemento também é 1

        for (k = 0; k <= i; k++) {
            printf("%d", v[k]);
        }
        printf("\n");
    } 
}

 int main() {
    int N = 5;

    pascalPrint(N);

    return 0;
 }