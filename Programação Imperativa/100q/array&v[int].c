#include <stdio.h>

/*
26. Defina uma funcao void insere (int v[], int N, int x) que insere um elemento (x) num
vector ordenado. Assuma que as N primeiras posicoes do vector estao ordenadas e que por
isso, apos a insercao o vector tera as primeiras N+1 posicoes ordenadas.
*/

void insere (int v[], int N, int x) {
    int j = N - 1;
    int i;
    // Enquanto o elemento inserido for menor empurramos para a direita
    while (x < v[j] && j >= 0) {
        v[j+1] = v[j];
        j--;
    }
    // Insere o X no buraco criado ao empurrar para a direita
    v[j+1] = x;
}

/*
27. Defina uma funcao void merge (int r [], int a[], int b[], int na, int nb) que, dados
vectores ordenados a (com na elementos) e b (com nb elementos), preenche o vector r
(com na+nb elementos) com os elementos de a e b ordenados.
*/

void merge (int r[], int a[], int b[], int na, int nb) {
    int write = 0;
    int readA = 0, readB = 0;
    
    //Enquanto há elementos em ambos
    while (readA < na && readB < nb) {
        if (a[readA] < b[readB]) {
            r[write] = a[readA];
            readA++;
        }
        else {
            r[write] = b[readB];
            readB++;
        }
        write++;
    }

    //a leftovers
    while (readA < na) {
        r[write] = a[readA];
        readA++;
        write++;
    }

    //b leftovers
    while (readB < nb) {
        r[write] = b[readB];
        readB++;
        write++;
    }
}

/*
28. Defina uma funcao int crescente (int a[], int i, int j) que testa se os elementos do
vector a, entre as posicoes i e j (inclusive) estao ordenados por ordem crescente. A funcao
deve retornar 1 ou 0 consoante o vector esteja ou nao ordenado.
*/

int crescente (int a[], int i, int j) {
    if (i == j) return 1;

    int k, ordenados = 1;

    for (k = i; k < j; k++) {
        if (a[k] > a[k+1]) return 0;
    }
    return 1;
}

/*
29. Defina uma funcao int retiraNeg (int v[], int N) que retira os numeros negativos de
um vector com N inteiros. A funcao deve retornar o numero de elementos que nao foram
retirados.
*/

int retiraNeg (int v[], int N) {
    int i, write = 0;

    for (i = 0; i < N; i++) {
        if (v[i] >= 0) {
            v[write] = v[i];
            write++;
        }
    }
    return write;
}

/*
30. Defina uma funcao int menosFreq (int v[], int N) que recebe um vector v com N elementos
 ordenado por ordem crescente e retorna o menos frequente dos elementos do vector.
Se houver mais do que um elemento nessas condicoes deve retornar o que comeca por
aparecer no ındice mais baixo.
*/

int menosFreq (int v[], int N) {
    int menorFreq = N;
    int i, res = v[0];
    int Counter = 1;

    if (N <= 0) return 0;


    for (i = 1; i < N; i++) {
        if (v[i] != v[i-1]) {
            if (Counter < menorFreq) {
            menorFreq = Counter;
            res = v[i-1];
            }
            // Restart counter for v[i]
            Counter = 1;
        }
        else {
            Counter++;
        }

        if (Counter < menorFreq) {
        res = v[N-1];
    }
    }
    return res;
}

/*
31. Defina uma funcao int maisFreq (int v[], int N) que recebe um vector v com N elementos
 ordenado por ordem crescente e retorna o mais frequente dos elementos do vector.
Se houver mais do que um elemento nessas condicoes deve retornar o que comeca por aparecer
no ́ındice mais baixo.
*/

int maisFreq (int v[], int N) {
    int i;
    int res = v[0]; 
    int counter = 1;
    int record = 1;

    if (N <= 0) return 0;

    for (i = 1; i < N; i++) {
        if (v[i] == v[i - 1]) {
            counter++;
        } else {
            // Block ended, check if it's the new record
            if (counter > record) {
                record = counter;
                res = v[i - 1];
            }
            counter = 1; // Reset for the new block
        }
    }

    // Final check for the last block
    if (counter > record) {
        res = v[N - 1];
    }
    
    return res;
}

/*
32. Defina uma funcao int maxCresc (int v[], int N) que calcula o comprimento da maior
sequencia crescente de elementos consecutivos num vector v com N elementos. Por exemplo,
5 se o vector contiver 10 elementos pela seguinte ordem: 1, 2, 3, 2, 1, 4, 10, 12, 5, 4,
a funcao devera retornar 4, correspondendo ao tamanho da sequencia 1, 4, 10, 12.
*/

int maxCresc (int v[], int N) {
    int i, streak = 1;
    int record = 1;

    if (N <= 0) return 0;

    for (i = 1; i < N; i++) {
        if (v[i - 1] < v[i]) {
            streak++;
        } else {
            // Sequence broke: check record and ALWAYS reset streak
            if (streak > record) {
                record = streak;
            }
            streak = 1; 
        }
    }

    // Final check for the last streak in the array
    if (streak > record) {
        record = streak;
    }

    return record;
}

/*
33. Defina uma funcao int elimRep (int v[], int n) que recebe um vector v com n inteiros e
elimina as repeticoes. A funcao devera retornar o numero de elementos do vector resultante.
Por exemplo, se o vector v contiver nas suas primeiras 10 posicoes os numeros {1, 2, 3, 2,
1, 4, 2, 4, 5, 4}, a invocacao elimRep (v,10) devera retornar 5 e colocar nas primeiras
5 posicoes do vector os elementos {1,2,3,4,5}.
*/

int elimRep (int v[], int N) {
    int read, write = 0;
    int i, repeat;

    if (N <= 0) return 0;

    for (read = 0; read < N; read++) {
        repeat = 0;

        for (i = 0; i < write; i++) {
            if (v[read] == v[i]) {
                repeat = 1;
                break; // no bother to read the rest
            }
        }
        if (!repeat) {
            v[write] = v[read];
            write++;
        }
    }
    return write;
}

/*
34. Defina uma funcao int elimRepOrd (int v[], int n) que recebe um vector v com n inteiros
ordenado por ordem crescente e elimina as repeticoes. A funcao devera retornar o
numero de elementos do vector resultante.
*/

int elimRepOrd (int v[], int N) {
    int read, write = 0;

    if (N <= 0) return 0;

    for (read = 0; read < N; read++) {
        if (v[read] != v[write - 1]) {
            v[write] = v[read];
            write++;
        }
    }
    return write;
}

/*
35. Defina uma funcao int comunsOrd (int a[], int na, int b[], int nb) que calcula quantos
elementos os vectores a (com na elementos) e b (com nb elementos) tem em comum. 
Assuma que os vectores a e b estao ordenados por ordem crescente.
*/

int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0;
    int count = 0;

    // We run the loop as long as there are elements to compare in BOTH arrays
    while (i < na && j < nb) {
        if (a[i] == b[j]) {
            count++;
            i++;
            j++;
        } 
        else if (a[i] < b[j]) {
            // Value in 'a' is too small, move to the next one
            i++;
        } 
        else {
            // Value in 'b' is too small, move to the next one
            j++;
        }
    }

    return count;
}

/*
36. Defina uma fun ̧c ̃ao int comuns (int a[], int na, int b[], int nb) que calcula quantos
elementos os vectores a (com na elementos) e b (com nb elementos) tˆem em comum. Assuma
que os vectores a e b n ̃ao est ̃ao ordenados e defina a fun ̧c ̃ao sem alterar os vectores.
*/

int comuns (int a[], int na, int b[], int nb) {
    if (na <= 0 || nb <= 0) return 0;

    int i, j, k;
    int count = 0;
    int alreadyCounted;

    for (i = 0; i < na; i++) {
        // Check if we already processed this value in array 'a' 
        // to avoid double counting duplicates.
        alreadyCounted = 0;
        for (k = 0; k < i; k++) {
            if (a[i] == a[k]) {
                alreadyCounted = 1;
                break; //already counted move to next 'a'
            }
        }
        // if first time being counted = search in b
        if (!alreadyCounted) {
            for (j = 0; j < nb; j++) {
                if (a[i] == b[j]) {
                    count++;
                    break; //found a match move to next 'a'
                }
            }
        }
    }
    return count;
}

/*
37. Defina uma fun ̧c ̃ao int minInd (int v[], int n) que, dado um vector v com n inteiros,
retorna o  ́ındice do menor elemento do vector.
*/

int minInd (int v[], int n) {
    if (n <= 0) return 0;

    int i;
    int index = 0;

    for (i = 1; i < n; i++) {
        if (v[i] < v[index]) {
            index = i;
        }
    }
    return index;
}

/*
38. Defina uma fun ̧c ̃ao void somasAc (int v[], int Ac [], int N) que preenche o vector Ac
com as somas acumuladas do vector v. Por exemplo, na posi ̧c ̃ao Ac[3] deve ser calculado
como v[0]+v[1]+v[2]+v[3].
*/

void somasAc (int v[], int Ac [], int N) {
    int i, soma = 0;

    for (i = 0; i < N; i++) {
        soma += v[i];
        Ac[i] = soma;
    }
}

// Função auxiliar local apenas para imprimir arrays nos testes
void printArr(int n, int a[]) {
    printf("[ ");
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("]\n");
}

int main() {
    printf("🚀 A INICIAR TESTES: array&v[int].c (Q26 a Q38)\n\n");

    int v26[10] = {1, 3, 5, 7};
    insere(v26, 4, 4);
    printf("Q26 (insere): "); printArr(5, v26); // Esperado: [ 1 3 4 5 7 ]

    int a27[] = {1, 3, 5}, b27[] = {2, 4, 6}, r27[6];
    merge(r27, a27, b27, 3, 3);
    printf("Q27 (merge): "); printArr(6, r27);

    int v28[] = {1, 2, 3, 5, 4};
    printf("Q28 (crescente index 0-3): %d\n", crescente(v28, 0, 3)); // Esperado: 1

    int v29[] = {1, -2, 3, -4, 5};
    int n29 = retiraNeg(v29, 5);
    printf("Q29 (retiraNeg): Sobraram %d -> ", n29); printArr(n29, v29);

    int v30[] = {1, 1, 2, 2, 2, 3, 4, 4};
    printf("Q30 (menosFreq): %d\n", menosFreq(v30, 8)); // Esperado: 3
    printf("Q31 (maisFreq): %d\n", maisFreq(v30, 8)); // Esperado: 2

    int v32[] = {1, 2, 3, 2, 1, 4, 10, 12, 5, 4};
    printf("Q32 (maxCresc): %d\n", maxCresc(v32, 10)); // Esperado: 4

    int v33[] = {1, 2, 3, 2, 1, 4, 2, 4, 5, 4};
    int n33 = elimRep(v33, 10);
    printf("Q33 (elimRep): Len %d -> ", n33); printArr(n33, v33);

    int v34[] = {1, 1, 2, 2, 3, 3, 3};
    int n34 = elimRepOrd(v34, 7);
    printf("Q34 (elimRepOrd): Len %d -> ", n34); printArr(n34, v34);

    int cA[] = {1, 2, 3, 4}, cB[] = {3, 4, 5, 6};
    printf("Q35 (comunsOrd): %d\n", comunsOrd(cA, 4, cB, 4)); // Esperado: 2
    printf("Q36 (comuns): %d\n", comuns(cA, 4, cB, 4)); // Esperado: 2

    int v37[] = {10, 5, 2, 8};
    printf("Q37 (minInd): %d (Valor: %d)\n", minInd(v37, 4), v37[minInd(v37, 4)]);

    int v38[] = {1, 2, 3, 4}, ac38[4];
    somasAc(v38, ac38, 4);
    printf("Q38 (somasAc): "); printArr(4, ac38); // Esperado: [ 1 3 6 10 ]
    printf("\n🎉 TESTES CONCLUIDOS!\n");
    return 0;
}