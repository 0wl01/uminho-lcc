#include <stdio.h>
#include <stdlib.h>

/*
1. Um conjunto de inteiros pode ser representado como uma união de 
intervalos. Por exemplo, o conjunto {1,2,3,4,5,6,10,11} pode ser representado 
pela união dos intervalos [1..6] e [10..11], ou pela união dos intervalos [2..4], 
[1..5], [10..11] e [4..6]. Implemente a função void ordena(Intervalo c[], 
int N) que dado um conjunto c com N intervalos guardados num array, 
ordena os respectivos intervalos pelo limite inferior. O tipo Intervalo está 
declarado da seguinte forma.
*/

typedef struct {  
  int inf,sup;  
} Intervalo;

void ordena(Intervalo c[], int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (c[i].inf > c[j].inf) {
                Intervalo temp;
                temp = c[j];
                c[j] = c[i];
                c[i] = temp;
            }
        }
    }
}

/*
2. Implemente a função int cardinalidade(Intervalo c[], int N), que 
dado um conjunto c com N intervalos guardados num array e já ordenados de 
forma crescente pelo limite inferior, devolve quantos inteiros estão contidos 
nesse conjunto. No caso do conjunto ilustrado na questão anterior, a função 
deve devolver 8.
*/

int cardinalidade (Intervalo c[], int N) {
    if (N == 0) return 0;
    int i, lowest = c[0].inf, high = c[0].sup;
    int counter = (high - lowest + 1);

    for (i = 1; i < N; i++) {
        if (c[i].inf <= high) {
            if (c[i].sup > high) {
                counter += (c[i].sup - high);
                high = c[i].sup;
            }
        } else {
            counter += (c[i].sup - c[i].inf + 1);
            high = c[i].sup;
        }
    }
    return counter;
}

/*
3. As duas convenções mais típicas para dar nomes a funções são 
conhecidas por camel case e snake case. No camel case as várias palavras 
de um identificador aparecem juntas, sendo que a primeira de cada palavra 
(exceto na primeira) é escrita em maiúscula. No snake case os identificadores 
são escritos sempre em minúsculas sendo as diferentes palavras separadas 
pelo caracter '_'. Por exemplo, o identificador "apagaTodosMenores" está 
escrito na convenção camel case e o identificador "apaga_todos_menores" 
em snake case. Implemente a função void camel2snake(char *id), que 
dada uma string com um identificador na convenção camel case o converte 
para convenção snake case. Assuma que a string tem espaço para o 
identificador resultante. Note que para converter um caracter de maiúscula 
para minúscula basta somar-lhe 32.
*/

void camel2snake (char *id) {
    int upper = 0, read = 0;

    while(id[read] != '\0') {
        if (id[read] >= 'A' && id[read] <= 'Z') upper++;
        read++;
    }
    int write = (read + upper);

    while (read >= 0) {
        if (isupper(id[read])) {
            id[write--] = id[read--] + 32; // vira minuscula
            id[write--] = '_';
        } else {
            id[write--] = id[read--];
        }
    }
}

/*
4. Defina a função LInt arrayToList (int v[], int N) que constroi 
uma lista com os elementos de um array, pela mesma ordem em que 
aparecem no array. O tipo LInt está declarado da seguinte forma.
*/

typedef struct no { 
  int valor; 
  struct no *prox; 
} *LInt;

LInt arrayToList (int v[], int N) {
    LInt atual = NULL;
    for (int i = N - 1; i >= 0; i--) {
        LInt new = malloc(sizeof(struct no));
        new->valor = v[i];
        new->prox = atual;
        atual = new;
    }
    return atual;
}

/*
5. Implemente a função int apagaUltimo(LInt *l, int x) que dada uma 
lista não ordenada apaga a última ocorrência do número x. Se o número não 
existir na lista deve devolver um código de erro.
*/

int apagaUltimo(LInt *l, int x) {
    LInt atual = *l;
    LInt prev = NULL;
    LInt prev_target = NULL;
    LInt target = NULL;

    // Fase 1: Marcar para a morte
    while (atual != NULL) {
        if (atual->valor == x) {
            prev_target = prev;
            target = atual;
        }
        prev = atual;
        atual = atual->prox;
    }

    // Fase 2: Analisar o resultado
    if (target == NULL) {
        return -1; // Não encontrou o elemento
    } 
    
    // Fase 3: Executar a remoção
    if (prev_target == NULL) {
        // Caso especial: o alvo é a cabeça da lista
        *l = target->prox;
    } else {
        // Caso normal: o alvo está a meio ou no fim
        prev_target->prox = target->prox;
    }

    // Fase 4: Limpeza e sucesso
    free(target);
    return 0;
}

/*
6. Implemente a função int parentesco(ABin a, int x, int y) que 
dada uma árvore binária de procura (sem números repetidos) e dois números 
que pertencem à árvore calcula o grau de parentesco entre eles (a distância 
entre eles na árvore). Por exemplo, na árvore ilustrada abaixo, o grau de 
parentesco entre 1 e 8 é 3. O tipo 
ABin está declarado da seguinte 
forma.
*/

typedef struct nodo { 
  int valor; 
  struct nodo *esq, *dir; 
} *ABin;

// Função auxiliar: calcula a distância da raiz da árvore 'a' até ao nó com o valor 'v'
int profundidade(ABin a, int v) {
    int passos = 0;
    
    while (a != NULL && a->valor != v) {
        if (v < a->valor) {
            a = a->esq;
        } else {
            a = a->dir;
        }
        passos++;
    }
    
    return passos;
}

// Função principal
int parentesco(ABin a, int x, int y) {
    // 1. Encontrar o Menor Ancestral Comum (o "cruzamento")
    while (a != NULL) {
        if (x < a->valor && y < a->valor) {
            // Ambos os valores são menores: o cruzamento está mais à esquerda
            a = a->esq;
        } 
        else if (x > a->valor && y > a->valor) {
            // Ambos os valores são maiores: o cruzamento está mais à direita
            a = a->dir;
        } 
        else {
            // Um é maior e o outro é menor (ou um deles é o próprio nó atual).
            // Encontrámos o cruzamento!
            break;
        }
    }
    
    // 2. Calcular a distância do cruzamento até x e até y, e somar as duas
    return profundidade(a, x) + profundidade(a, y);
}