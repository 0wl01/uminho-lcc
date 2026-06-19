#include <stdio.h>
#include <stdlib.h>

/*
1. Um conjunto de inteiros pode ser representado como uma união de 
intervalos. Por exemplo, o conjunto {1,2,3,4,5,6,10,11} pode ser representado 
pela união dos intervalos [1..6] e [10..11]. Implemente a função int existe 
(int x, Intervalo c[], int N) que dado um conjunto c com N intervalos 
guardados num array, testa se o número x pertence a esse conjunto. Assuma 
que o conjunto está representado de forma normalizada, não existindo 
intervalos que se intersectam e estando os intervalos ordenados de forma 
crescente. O tipo Intervalo está declarado da seguinte forma.
*/

typedef struct {  
  int inf,sup;  
} Intervalo;

int existe (int x, Intervalo c[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        if (c[i].inf <= x && c[i].sup >= x) {
            return 1;
        } else {
            if (c[i].inf > x) return 0;
        }
    }
    return 0;
}

/*
2. Implemente a função int acrescenta (Intervalo a, Intervalo c[], 
int N), que dado um conjunto c com N intervalos guardados num array de 
forma normalizada (ordenados de forma crescente e sem haver intervalos 
que se intersectam), acrescenta o intervalo a a esse conjunto, mantendo a 
representação normalizada. A função deve devolver o número de intervalos 
usados para representar o conjunto resultante.
*/

int acrescenta (Intervalo a, Intervalo c[], int N) {
    int i = N - 1;

    // Empurra os elementos maiores para a direita
    while (i >= 0 && c[i].inf > a.inf) {
        c[i + 1] = c[i];
        i--;
    }
    c[i + 1] = a;
    
    return N + 1;
}

/*
3. Defina uma função void invertePals (char *frase) que inverte cada 
uma das palavras de uma frase (assuma que uma palavra é uma sequência 
de caracteres alfabéticos). Por exemplo, se char f[] = "Ser ou nao ser, 
eis a questao.", após a invocação invertePals(f) o array f deve conter 
a string "reS uo oan res, sie a oatseuq."
*/

void inverte (char s[], int inicio, int fim) {
    char temp;
    while (inicio < fim) {
        temp = s[inicio];
        s[inicio] = s[fim];
        s[fim] = temp;

        inicio++;
        fim--;
    }
}

void invertePals(char *frase) {
    int i = 0, inicio, fim;

    while (frase[i] != '\0') {
        
        // 1. SALTAR O "LIXO" (Avançar enquanto NÃO é letra)
        while (frase[i] != '\0' && !((frase[i] >= 'A' && frase[i] <= 'Z') || (frase[i] >= 'a' && frase[i] <= 'z'))) {
            i++;
        }

        // Se chegámos ao fim da string enquanto saltávamos o lixo, podemos parar.
        if (frase[i] == '\0') break;

        // 2. ENCONTRÁMOS UMA LETRA! É o início da palavra.
        inicio = i;

        // 3. MEDIR A PALAVRA (Avançar enquanto É letra)
        while (frase[i] != '\0' && ((frase[i] >= 'A' && frase[i] <= 'Z') || (frase[i] >= 'a' && frase[i] <= 'z'))) {
            i++;
        }

        // 4. O ciclo parou, logo batemos em lixo ou no fim da string. 
        // A palavra acabou exatamente no índice anterior!
        fim = i - 1;

        // 5. Chamar o nosso "Mecânico" para inverter este bocado
        inverte(frase, inicio, fim);
    }
}

/*
4. Defina a função int listToArray (LInt l, int v[], int N) que 
dada uma lista l preenche o  array v com os elementos da lista (sem alterar a 
lista). A função deverá preencher no máximo N elementos e retornar o 
número de elementos preenchidos. O tipo LInt está declarado da seguinte 
forma
*/

typedef struct no { 
  int valor; 
  struct no *prox; 
} *LInt;

int listToArray (LInt l, int v[], int N) {
    LInt atual = l;
    int i;

    for (i = 0; i < N; i++) {
        // se chegarmos ao fim da lista cortamos
        if (atual == NULL) return i;

        v[i] = atual->valor;
        atual = atual->prox;
    }
    return i;
}

/*
5. Defina a função int removeMenores(LInt *l) que dada uma lista l 
remove dessa lista todos os nós que tenham um valor estritamente menor 
que o nó anterior na lista original. A função deve devolver o comprimento da 
lista resultante.
*/

int removeMenores(LInt *l) {
    LInt prev = *l;
    if (prev == NULL) return 0;
    LInt atual = prev->prox;
    int length = 1;

    while (atual != NULL) {
        if (atual->valor < prev->valor) {
            LInt temp = atual;

            atual = atual->prox;
            prev->prox = atual;
            free(temp);
        } else {
            length++;
            prev = atual;
            atual = atual->prox;
        }
    }
    return length;
}

/*
6. Defina uma função ABin folhaMaisProfunda (ABin a) que, dada uma 
árvore binária não vazia, calcula o endereço de uma das folhas que está no 
nível mais profundo. Na seguinte árvore poderia devolver o endereço de um 
dos seguintes nós: 8,17 ou 21. O tipo ABin está declarado da seguinte forma.
*/

typedef struct nodo { 
  int valor; 
  struct nodo *esq, *dir; 
} *ABin;

int altura(ABin a) {
    if (a == NULL) return 0; // O caso base que faltava!
    
    int e = altura(a->esq);
    int d = altura(a->dir);
    
    if (e > d) return 1 + e;
    else return 1 + d;
}

ABin folhaMaisProfunda (ABin a) {
    // Caso base: se não tem filhos, é uma folha! Chegámos ao destino.
    // (O enunciado diz para assumir árvore não vazia, logo 'a' nunca é NULL aqui)
    if (a->esq == NULL && a->dir == NULL) {
        return a;
    }
    
    // Perguntar ao auxiliar qual é o lado mais fundo
    int altEsq = altura(a->esq);
    int altDir = altura(a->dir);
    
    // Se o lado esquerdo for mais fundo, descemos por aí
    if (altEsq > altDir) {
        return folhaMaisProfunda(a->esq);
    } 
    // Caso contrário (se for maior ou igual), descemos pela direita
    else {
        return folhaMaisProfunda(a->dir);
    }
}