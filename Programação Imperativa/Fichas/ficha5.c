#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

/*
1. Defina uma fun ̧c ̃ao int nota (Aluno a) que calcula a nota de um aluno (de acordo com as
regras definidas para Programa ̧c ̃ao Imperativa). A fun ̧c ̃ao dever ́a retornar 0 se o aluno n ̃ao tiver
aproveitamento.
*/

int nota (Aluno a) {
    float somaMini = 0;
    int i;

    // 1. Somar os 5 mini-testes (escala 0-20)
    for (i = 0; i < 5; i++) {
        somaMini += a.miniT[i];
    }
    
    // 2. Verificar a nota mínima de 8 valores (40% de 20)
    if (somaMini < 8.0) return 0;

    // 3. Calcular nota final (20% mini, 80% teste)
    float notaFinal = (somaMini * 0.2) + (a.teste * 0.8);

    // 4. Arredondar para o inteiro mais próximo
    return (int)(notaFinal + 0.5);
}

/*
2. Defina uma fun ̧c ̃ao int procuraNum (int num, Aluno t[], int N) que recebe um n ́umero de
aluno e um array de alunos ordenado por ordem crescente de n ́umero de aluno e retorna o  ́ındice
onde esse aluno est ́a armazenado (retorna -1 se o n ́umero n ̃ao existir).
*/

procuraNum (int num, Aluno t[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        // array ordenado se o numero atual já é maior o num nao existe no array
        if (t[i].numero > num) {
            return -1;
        } else {
            // se encontrarmos num no array retornamos o indice i
            if (t[i].numero == num)
            return i;
        }
    }
    return -1;
}

/*
3. Defina uma fun ̧c ̃ao void ordenaPorNum (Aluno t [], int N) que ordena um array t de N
alunos, por ordem crescente do seu n ́umero.
*/

void ordenaPorNum (Aluno t[], int N) {
    int i, j, min;
    Aluno temp;
    // Selection Sort
    for (i = 0; i < N; i++) {
        min = i; // is current one the smallest?

        // search for one smaller
        for (j = i; j < N; j++) {
            if (t[j].numero < t[min].numero) {
                min = j;
            }
        }
        // if we found an ew min
        if (min != i) {
            temp = t[i];
            t[i] = t[min];
            t[min] = temp;
        }
    }
}

/*
4. Uma alternativa `a fun ̧c ̃ao anterior consiste em calcular um array de  ́ındices em que na posi ̧c ̃ao i se
encontra o  ́ındice correespondente ao i- ́esimo elemento. Defina uma fun ̧c ̃ao void criaIndPorNum
(Aluno t [], int N, int ind[]) que preenche o vector ind com os indices correspondentes
a uma ordena ̧c ̃ao do array t por ordem crescente do n ́umero de aluno.
Por exemplo, para N = 4, se o array tivesse os elementos
{{4444, "Andr ́e", {2,1,0,2,2,2}, 10.5}
,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
,{7777, "Maria", {2,2,2,2,2,1}, 18.5}
,{3333, "Paulo", {0,0,2,2,2,1}, 8.7}
}
A fun ̧c ̃ao criaIndPorNum devia preencher o array com {1,3,0,2}.
*/

void criaIndPorNum (Aluno t[], int N, int ind[]) {
    int i, j, temp;

    // 1. Inicializar o array de índices (ind[i] = i)
    for (i = 0; i < N; i++) ind[i] = i;

    // 2. Ordenar o array ind usando os valores de t para comparar
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            // A comparação é feita através do índice indireto
            if (t[ind[i]].numero > t[ind[j]].numero) {
                // Trocamos os índices, NÃO os alunos!
                temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }
}

/*
5. Defina uma fun ̧c ̃ao void imprimeTurma (int ind[], Aluno t[], int N) que recebe uma
turma e um array tal como produzido pela fun ̧c ̃ao da al ́ınea anterior e imprime os n ́umeros,
nomes e notas dos alunos por ordem crescente do n ́umero de aluno.
*/

void imprimeTurma (int ind[], Aluno t[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        int pos = ind[i];

        printf("Número: %d | Nome: %s | Nota: %f\n",
        t[pos].numero,
        t[pos].nome,
        nota(t[pos]));
    }
}

/*
6. Adapte a fun ̧c ̃ao de procura definida na alinea 2 de forma a receber um array de alunos e um
array tal como produzido pela fun ̧c ̃ao criaIndPorNum.
*/

int procuraNumInd (int num, Aluno t[], int ind[], int N) {
    int inicio = 0, fim = N - 1, meio;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;
        
        // Acesso indireto: olhamos para o número do aluno apontado pelo índice
        if (t[ind[meio]].numero == num) {
            return ind[meio]; // Retorna o índice original onde o aluno está em t
        }
        
        if (t[ind[meio]].numero < num) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

/*
7. Defina uma outra fun ̧c ̃ao void criaIndPorNome (Aluno t [], int N, int ind[]) que preenche
o vector ind com os indices correspondentes a uma ordena ̧c ̃ao do array t por ordem crescente
do nome do aluno.
*/

void criaIndPorNome (Aluno t[], int N, int ind[]) {
    int i, j, temp;

    // 1. Inicializar o array de índices
    for (i = 0; i < N; i++) ind[i] = i;

    // 2. Ordenação indireta usando strcmp
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            // Compara os nomes apontados pelos índices
            if (strcmp(t[ind[i]].nome, t[ind[j]].nome) > 0) {
                // Troca os índices se estiverem fora de ordem
                temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }
}