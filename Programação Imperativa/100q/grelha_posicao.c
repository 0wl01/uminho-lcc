#include <stdio.h>
#include <stdlib.h> // Estritamente necessário para o abs() usado na função distancia

// 47. Considere as seguintes defini ̧c ̃oes para representar as posi ̧c ̃oes e movimentos de um robot.
typedef enum movimento {Norte, Oeste, Sul, Este}
                Movimento;

typedef struct posicao {
                int x, y;
                }Posicao;

/*
Defina a fun ̧c ̃ao Posicao posFinal (Posicao inicial, Movimento mov[], int N) que,
dada uma posi ̧c ̃ao inicial e um array com N movimentos, calcula a posi ̧c ̃ao final do robot
8
depois de efectuar essa sequˆencia de movimentos.
*/

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    int i;
    Posicao atual = inicial;

    for (i = 0; i < N; i++) {
        switch (mov [i]) {
            case Norte:
                atual.y++;
                break;
            case Sul:
                atual.y--;
                break;
            case Este:
                atual.x++;
                break;
            case Oeste:
                atual.x--;
                break;
        }
    }
    return atual;
}

/*
48. Defina a fun ̧c ̃ao int caminho (Posicao inicial, Posicao final, Movimento mov[], int N)
que, dadas as posi ̧c ̃oes inicial e final do robot, preenche o array com os movimentos sufi-
cientes para que o robot passe de uma posi ̧c ̃ao para a outra.
A fun ̧c ̃ao dever ́a preencher no m ́aximo N elementos do array e retornar o n ́umero de elementos
preenchidos. Se n ̃ao for poss ́ıvel atingir a posi ̧c ̃ao final com N movimentos, a fun ̧c ̃ao dever ́a
retornar um n ́umero negativo.
*/

// Função Auxiliar para Calcular Distância

int distancia (Posicao inicial, Posicao final) {
    int deltax = (abs(final.x - inicial.x));
    int deltay = (abs(final.y - inicial.y));

    return deltax + deltay;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
    int i = 0;
    Posicao atual = inicial;

    if (N < distancia(inicial, final)) return -1;

    while (atual.x != final.x && i < N) {
        if (atual.x < final.x) {
                mov[i++] = Este;
                atual.x++;
        } else {
            mov[i++] = Oeste;
            atual.x--;
        }
    }

    while (atual.y != final.y && i < N) {
        if (atual.y < final.y) {
            mov[i++] = Norte;
            atual.y++;
        } else {
            mov[i++] = Sul;
            atual.y--;
        }
    }
    return i;
}

/*
49. Defina a fun ̧c ̃ao int maisCentral (Posicao pos[], int N) que, dado um array com N
posi ̧c ̃oes, determina o  ́ındice da posi ̧c ̃ao que est ́a mais perto da origem (note que as coor-
denadas de cada ponto s ̃ao n ́umeros inteiros).
*/

int maisCentral (Posicao pos[], int N) {
    int i, index = 0;

    Posicao origem = {0, 0};

    int record = distancia(pos[0], origem);

    for (i = 1; i < N; i++) {
        if (distancia(pos[i], origem) < record) {
            index = i;
            record = distancia(pos[i], origem);
        }
    }
    return index;
}

/*
50. Defina a fun ̧c ̃ao int vizinhos (Posicao p, Posicao pos[], int N) que, dada uma posi ̧c ̃ao
e um array com N posi ̧c ̃oes, calcula quantas dessas posi ̧c ̃oes s ̃ao adjacentes `a posi ̧c ̃ao dada.
*/

int vizinhos(Posicao p, Posicao pos[], int N) {
    int i, cont = 0;
    for (i = 0; i < N; i++) {
        // Se a distância for 1, são adjacentes
        if (distancia(p, pos[i]) == 1) {
            cont++;
        }
    }
    return cont;
}

int main() {
    printf("🚀 A INICIAR TESTES: grelha_posicao.c (Q47 a Q50)\n\n");

    Posicao pIni = {0, 0};
    Movimento movs[] = {Norte, Este, Norte, Oeste};
    Posicao pFim = posFinal(pIni, movs, 4);
    printf("Q47 (posFinal): (%d, %d)\n", pFim.x, pFim.y); // Esperado: (0, 2)

    Posicao pAlvo = {2, 2};
    Movimento rota[10];
    int passos = caminho(pIni, pAlvo, rota, 10);
    printf("Q48 (caminho): %d passos gerados para chegar a (2,2)\n", passos);

    Posicao viz[] = {{1,0}, {0,1}, {5,5}, {-1,0}};
    printf("Q49 (maisCentral): Indice %d\n", maisCentral(viz, 4));
    printf("Q50 (vizinhos de 0,0): %d adjacentes encontrados\n\n", vizinhos(pIni, viz, 4)); // Esperado: 3

    printf("🎉 TESTES CONCLUIDOS!\n");
    return 0;
}