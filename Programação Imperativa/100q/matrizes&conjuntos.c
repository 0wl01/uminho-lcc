#include <stdio.h>
#include <math.h> // Estritamente necessário para o fabs() usado na Q39

/*
39. Defina uma fun ̧c ̃ao int triSup (int N, float m [N][N]) que testa se uma matriz quadra-
da  ́e triangular superior, i.e., que todos os elementos abaixo da diagonal s ̃ao zeros
*/

int triSup (int N, float m [N][N]) {
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++) {
            if (fabs(m[i][j]) > 0.00001)
            return 0;
        }
    return 1;
}

/*
40. Defina uma fun ̧c ̃ao void transposta (int N, float m [N][N]) que transforma uma ma-
triz na sua transposta.
*/

void transposta (int N, float m [N][N]) {
    int i, j;
    float temp;

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

/*
41. Defina uma fun ̧c ̃ao void addTo (int N, int M, int a [N][M], int b[N][M]) que adi-
ciona a segunda matriz `a primeira.
*/

void addTo (int N, int M, int a [N][M], int b[N][M]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

/*
42. Uma forma de representar conjuntos de  ́ındices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse  ́ındice perten ̧ca ou n ̃ao ao conjunto. Assim o conjunto {1,4,7}seria
representado por um array em que as primeiras 8 posi ̧c ̃oes conteriam {0,1,0,0,1,0,0,1}.
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int unionSet (int N, int v1[N], int v2[N], int
r[N]) que coloca no array r o resultado da uni ̃ao dos conjuntos v1 e v2.
*/

int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int i, counter = 0;
    
    // Limpeza do array
    for (i = 0; i < N; i++) {
        r[i] = 0;
    }

    for (i = 0; i < N; i++) {
        if (r[v1[i]] != 1) {
            r[v1[i]] = 1;
            counter++;
        }
    }

    for (i = 0; i < N; i++) {
        if (r[v2[i]] != 1) {
            r[v2[i]] = 1;
            counter++;
        }
    }
    return counter;
}

/*
43. Uma forma de representar conjuntos de  ́ındices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse  ́ındice perten ̧ca ou n ̃ao ao conjunto. Assim o conjunto {1,4,7}seria
representado por um array em que as primeiras 8 posi ̧c ̃oes conteriam {0,1,0,0,1,0,0,1}.
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int intersectSet (int N, int v1[N], int v2[N],
int r[N]) que coloca no array r o resultado da intersec ̧c ̃ao dos conjuntos v1 e v2.
*/

int intersectSet (int N, int v1[N], int v2[N], int r[N]) {
    int i, counter = 0;
    int temp[N];
    
    for (i = 0; i < N; i++) {
        temp[i] = 0;
        r[i] = 0;
    }

    for (i = 0; i < N; i++) {
        if (temp[v1[i]] != 1) {
            temp[v1[i]] = 1;
        }
    }

    for (i = 0; i < N; i++) {
        if (temp[v2[i]] == 1 && r[v2[i]] != 1) {
            r[v2[i]] = 1;
            counter++;
        }
    }
    return counter;
}

/*
44. Uma forma de representar multi-conjuntos de  ́ındices consiste em usar um array de inteiros
contendo em cada posi ̧c ̃ao o n ́umero de ocorrˆencias desse  ́ındice. Assim o multi-conjunto
{1,1,4,7,7,7}seria representado por um array em que as primeiras 8 posi ̧c ̃oes conteriam
{0,2,0,0,1,0,0,3}.
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int intersectMSet (int N, int v1[N], int v2[N],
int r[N]) que coloca no array r o resultado da intersec ̧c ̃ao dos multi-conjuntos v1 e v2.
*/

int intersectMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i, counter = 0;
    int temp[N];

    for (i = 0; i < N; i++) {
        r[i] = 0;
        temp[i] = 0;
    }

    for (i = 0; i < N; i++) {
        temp[v1[i]] += 1;
    }

    for (i = 0; i < N; i++) {
        r[v2[i]] += 1;
    }

    for (i = 0; i < N; i++) {
        if (r[i] != 0 && temp[i] != 0) {
        r[i] = 1;
        counter++;
        } else {
            r[i] = 0;
        }
    }
    return counter;
}

/*
45. Uma forma de representar multi-conjuntos de  ́ındices consiste em usar um array de inteiros
contendo em cada posi ̧c ̃ao o n ́umero de ocorrˆencias desse  ́ındice. Assim o multi-conjunto
{1,1,4,7,7,7}seria representado por um array em que as primeiras 8 posi ̧c ̃oes conteriam
{0,2,0,0,1,0,0,3}.
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int unionMSet (int N, int v1[N], int v2[N], int
r[N]) que coloca no array r o resultado da uni ̃ao dos multi-conjuntos v1 e v2.
*/

int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i, counter = 0;

    for (i = 0; i < N; i++) {
        r[i] = 0;
    }

    for (i = 0; i < N; i++) {
        r[v1[i]] += 1;
        counter ++;
    }

    for (i = 0; i < N; i++) {
        r[v2[i]] += 1;
        counter++;
    }
    return counter;
}

/*
46. Uma forma de representar multi-conjuntos de  ́ındices consiste em usar um array de inteiros
contendo em cada posi ̧c ̃ao o n ́umero de ocorrˆencias desse  ́ındice. Assim o multi-conjunto
{1,1,4,7,7,7}seria representado por um array em que as primeiras 8 posi ̧c ̃oes conteriam
{0,2,0,0,1,0,0,3}.
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int cardinalMSet (int N, int v[N]) que calcula a
n ́umero de elementos do multi-conjunto v.
*/

int cardinalMSet (int N, int v[N]) {
    int i, counter = 0;

    for (i = 0; i < N; i++) {
        counter += v[i];
    }
    return counter;
}

void printSet(int n, int a[]) {
    printf("{ ");
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("}\n");
}

int main() {
    printf("🚀 A INICIAR TESTES: matrizes&conjuntos.c (Q39 a Q46)\n\n");

    float m39[3][3] = {
        {1.0, 2.0, 3.0},
        {0.0, 5.0, 6.0},
        {0.0, 0.0, 9.0}
    };
    printf("Q39 (triSup): %d\n", triSup(3, m39)); // Esperado: 1

    transposta(3, m39);
    printf("Q40 (transposta m[1][0]): %.1f (Esperado: 2.0)\n", m39[1][0]);

    int mA[2][2] = {{1,1},{1,1}}, mB[2][2] = {{2,2},{2,2}};
    addTo(2, 2, mA, mB);
    printf("Q41 (addTo mA[0][0]): %d (Esperado: 3)\n\n", mA[0][0]);

    int N = 8;
    int v1[] = {0,1,0,0,1,0,0,1}; // Conjunto {1, 4, 7}
    int v2[] = {0,1,1,0,0,0,0,1}; // Conjunto {1, 2, 7}
    int r[8];

    int c42 = unionSet(N, v1, v2, r);
    printf("Q42 (unionSet): Card %d -> ", c42); printSet(N, r);

    // Q43 usa vetores de índices literais no teu código original:
    int ind1[] = {1, 4, 7}, ind2[] = {1, 2, 7};
    int c43 = intersectSet(3, ind1, ind2, r); // Usamos N=3 índices
    printf("Q43 (intersectSet): Card %d\n\n", c43);

    int ms1[] = {0,2,0,0,1,0,0,3}; // MSet {1,1,4,7,7,7}
    int ms2[] = {0,1,0,0,2,0,0,1}; // MSet {1,4,4,7}
    int rM[8];

    // Passando N=8 posições do MSet
    printf("Q44 (intersectMSet): %d\n", intersectMSet(8, ms1, ms2, rM));
    printf("Q45 (unionMSet): %d\n", unionMSet(8, ms1, ms2, rM));
    printf("Q46 (cardinalMSet): %d\n\n", cardinalMSet(8, ms1)); // Esperado: 6

    printf("🎉 TESTES CONCLUIDOS!\n");
    return 0;
}