#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

// 1. Considere o seguinte tipo para representar stacks de n´umeros inteiros.

/*
a) void SinitStack (SStack s) que inicializa uma stack (passa a representar uma stack
vazia)
*/

void SinitStack (SStack s) {
    s->sp = 0;
}

/*
(b) int SisEmpty (SStack s) que testa se uma stack  ́e vazia
*/

int SisEmpty (SStack s) {
    return s->sp == 0;
}

/*
(c) int Spush (SStack s, int x) que acrescenta x ao topo de s; a fun ̧c ̃ao deve retornar 0 se
a opera ̧c ̃ao fˆor feita com sucesso (i.e., se a stack ainda n ̃ao estiver cheia) e 1 se a opera ̧c ̃ao
n ̃ao fˆor poss ́ıvel (i.e., se a stack estiver cheia).
*/

int Spush (SStack s, int x) {
    if (s->sp >= Max) return 1; // max capacity
    s->values[s->sp++] = x;
    
    return 0;
}

/*
(d) int Spop (SStack s, int *x) que remove de uma stack o elemento que est ́a no topo. A
fun ̧c ̃ao dever ́a colocar no endere ̧co x o elemento removido. A fun ̧c ̃ao dever ́a retornar 0 se a
opera ̧c ̃ao for poss ́ıvel (i.e. a stack n ̃ao est ́a vazia) e 1 em caso de erro (stack vazia).
*/

int Spop (SStack s, int *x) {
    if (SisEmpty(s)) return 1;

    *x = s->values[--s->sp];
}

/*
(e) int Stop (SStack s, int *x) que coloca no endere ̧co x o elemento que est ́a no topo da
stack (sem modificar a stack). A fun ̧c ̃ao dever ́a retornar 0 se a opera ̧c ̃ao for poss ́ıvel (i.e. a
stack n ̃ao est ́a vazia) e 1 em caso de erro (stack vazia).
*/

int Stop (SStack s, int *x) {
    if (SisEmpty(s)) return 1;

    *x = s->values[s->sp - 1];

    return 0;
}

// 2. Considere o seguinte tipo para representar queues de n ́umeros inteiros.

struct staticQueue {
    int front;
    int length;
    int values[Max];
} QUEUE, *SQueue;

/*
(a) void SinitQueue (SQueue q) que inicializa uma queue (passa a representar uma queue
vazia)
*/

void SinitQueue (SQueue q) {
    q->front = 0;
    q->length = 0;
}

/*
(b) int SisEmptyQ (SQueue q) que testa se uma queue  ́e vazia
*/

int SisEmptyQ (SQueue q) {
    return q->length == 0;
}

/*
(c) int Senqueue (SQueue q, int x) que acrescenta x ao fim de q; a fun ̧c ̃ao deve retornar
0 se a opera ̧c ̃ao fˆor feita com sucesso (i.e., se a queue ainda n ̃ao estiver cheia) e 1 se a
opera ̧c ̃ao n ̃ao fˆor poss ́ıvel (i.e., se a queue estiver cheia).
*/

int Senqueue (SQueue q, int x) {
    if (q->length >= Max) {
        return 1; // Erro: fila CHEIA, exatamente como o enunciado pede!
    }
    
    // Se não estiver cheia, prossegue com a inserção...
    int pos = (q->front + q->length) % Max;
    q->values[pos] = x;
    q->length++;
    
    return 0;
}

/*
d) int Sdequeue (SQueue q, int *x) que remove de uma queue o elemento que est ́a no
in ́ıcio. A fun ̧c ̃ao dever ́a colocar no endere ̧co x o elemento removido. A fun ̧c ̃ao dever ́a
retornar 0 se a opera ̧c ̃ao for poss ́ıvel (i.e. a queue n ̃ao est ́a vazia) e 1 em caso de erro
(queue vazia).
*/

int Sdequeue (SQueue q, int *x) {
    if (q->length == 0) return 1;

    *x = q->values[q->front];

    q->front = (q->front + 1 ) % Max;
    q->length--;
    
    return 0;
}

/*
(e) int Sfront (SQueue q, int *x) que coloca no endere ̧co x o elemento que est ́a no in ́ıcio
da queue (sem modificar a queue). A fun ̧c ̃ao dever ́a retornar 0 se a opera ̧c ̃ao for poss ́ıvel
(i.e. a queue n ̃ao est ́a vazia) e 1 em caso de erro (queue vazia).
*/

int Sfront (Squeu q, int *x) {
    if (q->length == 0) return 1;

    *x = q->values[q->front];

    return 0;
}

/*
3. Na representa ̧c ̃ao de stacks e queues sugeridas nas al ́ıneas anteriores o array de valores tem
um tamanho fixo (definido pela constante MAX). Uma consequˆencia dessa defini ̧c ̃ao  ́e o facto
de as fun ̧c ̃oes de inser ̧c ̃ao (push e enqueue) poderem n ̃ao ser executadas por se ter excedido a
capacidade da estruturas.
Uma defini ̧c ̃ao alternativa consiste em n ̃ao ter um array com tamanho fixo e sempre que seja
preciso mais espa ̧co, realocar o array para um de tamanho superior (normalmente duplica-se o
tamanho do array).
Considere ent ̃ao as seguintes defini ̧c ̃oes alternativas e adapte as fun ̧c ̃oes definidas atr ́as para esta
nova representa ̧c ̃ao.
Use as fun ̧c ̃oes malloc e free cujo tipo est ́a definido em stdlib.h.
*/

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

// init, empty, push, pop, top

void DinitStack (DStack s) {
    s->size = 10;
    s->sp = 0;

    s->values = malloc(sizeof(int) * s->size);
}

int Dpush (DStack s, int x) {
    if (s->sp == s->size) {
        s->size *= 2;

        s->values = realloc(s->values, s->size * sizeof(int));

        if (s->values = NULL) return -1;
    }
    s->values[s->sp] = x;
    s->sp++;

    return 0;
}

// pop e top nao mexem em memoria

void DinitQueue (DQueue q) {
    q->size = 10; // Tamanho inicial à tua escolha
    q->front = 0;
    q->length = 0;
    
    // Pede memória para o array de valores
    q->values = malloc(q->size * sizeof(int));
}

int Denqueue (DQueue q, int x) {
    // Verificar se a fila está cheia
    if (q->length == q->size) {
        int old_size = q->size;
        q->size *= 2; // Duplica o tamanho
        
        // Pede mais memória
        q->values = realloc(q->values, q->size * sizeof(int));

        // Copiamos os elementos do início do array para as novas posições livres
        for (int i = 0; i < q->front; i++) {
            q->values[old_size + i] = q->values[i];
        }
    }

    // Inserção normal com matemática circular usando o novo q->size
    int pos = (q->front + q->length) % q->size;
    q->values[pos] = x;
    q->length++;
    
    return 0;
}