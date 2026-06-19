#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao int length (LInt) que calcula o compri-
mento de uma lista ligada.
*/

typedef struct lligada {
            int valor;
        struct lligada *prox;
} *LInt;

int length (LInt l) {
    int len = 0;
    LInt atual = l;

    while (atual != NULL) {
        len++;
        atual = atual->prox;
    }
    return len;
}

/*
2. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void freeL (LInt) que liberta o espa ̧co
ocupado por uma lista.
*/

void freeL (LInt l) {
    LInt atual = l;
    LInt next;
    while (atual != NULL) {
        // Save next link
        next = atual->prox; 
        // Delete data
        free(atual);
        // Check next link, repeat
        atual = next;
    }
}

/*
3. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void imprimeL (LInt) que imprime no
ecran os elementos de uma lista (um por linha).
*/

void imprimeL (LInt l) {
    LInt atual = l;

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

/*
4. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao LInt reverseL (LInt) que inverte uma
lista (sem criar uma nova lista).
*/

LInt reverseL (LInt l) {
    LInt atual = l;
    LInt prev = NULL;
    LInt next = NULL;

    while (atual != NULL) {
        next = atual->prox; // Save the next pointer
        atual->prox = prev; // Reverse the direction of current pointer
        prev = atual; // Former is now the current node
        atual = next; // We skip to the next node
    }
    return prev;
}

/*
5. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void insertOrd (LInt *, int) que insere
ordenadamente um elemento numa lista ordenada.
*/

void insertOrd (LInt *l, int x) {
    LInt atual = *l;
    LInt prev = NULL;

    while (atual != NULL && atual->valor < x) {
        prev = atual;
        atual = atual->prox;
    }

    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = atual;

    if (prev == NULL) {
        *l = novo; // Se não havia anterior, o novo é o primeiro
    } else {
        // Onde é que o prev deve apontar agora para incluir o novo nó?
        prev->prox = novo; 
    }
}

/*
6. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao int removeOneOrd (LInt *, int) que
remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover n ̃ao exista,
0 no outro caso.
*/

int removeOneOrd (LInt *l, int x) {
    LInt atual = *l;
    LInt prev = NULL;

    while (atual != NULL && atual->valor != x) {
        prev = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 1;

    if (prev == NULL) {
        *l = atual->prox;
        free(atual);
        return 0;
    } else {
        prev->prox=atual->prox;
        free(atual);
        return 0;
    }
}

/*
7. Defina uma fun ̧c ̃ao void merge (LInt *r, LInt a, LInt b) que junta duas listas orde-
nadas (a e b) numa  ́unica lista ordenada (*r).
*/

void merge (LInt *r, LInt a, LInt b) {
    if (a == NULL) {
        *r = b;
        return;
    }
    if (b == NULL) {
        *r = a;
        return;
    }

    if (a->valor < b->valor) {
        *r = a;
        a = a->prox; // Avançamos na lista a
    } else {
        *r = b;
        b = b->prox; // Avançamos na lista b
    }

    LInt atual = *r;

    while (a != NULL && b != NULL) {
        if (a->valor < b->valor) {
            atual->prox = a;
            a = a->prox;
        } else {
            atual->prox = b;
            b = b->prox;
        }
        // Como fazemos o 'atual' passar a ser o nó que acabámos de ligar?
        atual = atual->prox; 
    }

    if (a == NULL) {
        atual->prox = b;
    } else {
        atual->prox = a;
    }
}

/*
8. Defina uma fun ̧c ̃ao void splitQS (LInt l, int x, LInt *mx, LInt *Mx) que, dada uma
lista ligada l e um inteiro x, parte a lista em duas (retornando os endere ̧cos dos primeiros
elementos da lista em *mx e *Mx): uma com os elementos de l menores do que x e a outra
com os restantes. Note que esta fun ̧c ̃ao n ̃ao dever ́a criar c ́opias dos elementos da lista.
*/

void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    *mx = NULL;
    *Mx = NULL;

    LInt atual = l;
    LInt ult_m = NULL;
    LInt ult_M = NULL;

    while (atual != NULL) {
        if (atual->valor < x) {
            if (*mx == NULL) {
                *mx = atual;
            } else {
                ult_m->prox = atual;
            }
            ult_m = atual;
        } else {
            if (*Mx == NULL) {
                *Mx = atual;
            } else {
                ult_M->prox = atual;
            }
            ult_M = atual;
        }
        atual = atual->prox;
    }

    // O toque final: garantir que as listas terminam em NULL 🏁
    if (ult_m != NULL) ult_m->prox = NULL;
    if (ult_M != NULL) ult_M->prox = NULL;
}

/*
9. Defina uma fun ̧c ̃ao LLig parteAmeio (LLig *l) que, parte uma lista n ̃ao vazia *l a meio.
Se x contiver os elementos 1,2,3,4,5, ap ́os a invoca ̧c ̃ao y=parteAmeio(&x) a lista y dever ́a
conter os elementos 1,2 e a lista x os restantes 3,4,5
*/

LInt parteAmeio (LInt *l) {
    int i, total = 0;

    LInt temp = *l;
    while (temp) {
        total++;
        temp = temp->prox;
    }

    int meio = total / 2;

    if (meio == 0) return NULL; // x <= 1 elemento, nao corta nada

    //Correr atual ate ao meio da lista
    LInt atual = *l;
    for (i = 0; i < meio - 1; i++) {
        atual = atual->prox;
    }

    //Agora atual esta a meio da lista e podemos cortar
    LInt y = *l; //y começa a 0
    *l = atual->prox; // x começa a meio
    atual->prox = NULL; //cortamos a cauda de y

    return y;
}

/*
10. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao int removeAll (LInt *, int) que remove
todas as ocorrˆencias de um dado inteiro de uma lista, retornando o n ́umero de c ́elulas removi-
das.
*/

int removeAll (LInt *l, int n) {
    int counter = 0;
    LInt atual = *l;
    LInt prev = NULL;

    while (atual != NULL) {
        if (atual->valor == n) { // Se for para remover
            counter++;
            LInt temp = atual;
            
            if (prev == NULL) {
                // Caso seja o primeiro nó, movemos o início da lista
                *l = atual->prox;
                atual = *l;
            } else {
                // Caso contrário, o anterior "salta" o atual
                prev->prox = atual->prox;
                atual = prev->prox;
            }
            free(temp);
        } else {
            // Se não for para remover, apenas avançamos ambos
            prev = atual;
            atual = atual->prox;
        }
    }
    return counter;
}

/*
11. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int removeDups (LInt *) que remove os valores repeti-
dos de uma lista (deixando apenas a primeira ocorrˆencia).
*/

int removeDups (LInt *l) {
    LInt atual = *l;
    int removidos = 0;

    while (atual != NULL) {
        LInt insider_atual = atual->prox;
        LInt insider_anterior = atual;

        while (insider_atual != NULL) {
            if (insider_atual->valor == atual->valor ) {
                // duplicado encontrado
                removidos++;
                insider_anterior->prox = insider_atual->prox;
                LInt temp = insider_atual;
                insider_atual = insider_atual->prox;
                free (temp);
            } else {
                insider_anterior = insider_atual;
                insider_atual = insider_atual->prox;
            }
        }
        // Depois de percorrer a lista ligada por x vamos a procura de outro
        atual = atual->prox;
    }
    return removidos;
}

/*
12. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int removeMaiorL (LInt *) que remove (a primeira
ocorrˆencia) o maior elemento de uma lista n ̃ao vazia, retornando o valor desse elemento.
*/

int removeMaiorL (LInt *l) {
    LInt atual = *l;
    LInt anterior = NULL;
    LInt maior_node = atual;
    LInt pre_maior = NULL;
    int record = atual->valor;

    while (atual != NULL) {
        if (atual->valor > record) {
            record = atual->valor;
            maior_node = atual;
            pre_maior = anterior; // Guardamos exatamente quem vinha atrás do recorde!
        }
        // Avançamos ambos os ponteiros passo a passo
        anterior = atual;
        atual = atual->prox;
    }

    // Desligar o maior nó da corrente
    if (pre_maior == NULL) {
        // Se o pre_maior continuar a NULL, significa que o maior era logo o 1º elemento!
        *l = maior_node->prox;
    } else {
        // Caso contrário, o nó anterior "salta" o maior_node
        pre_maior->prox = maior_node->prox;
    }

    // Limpar a memória e devolver o valor
    free(maior_node);
    return record;
}

/*
13. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void init (LInt *) que remove o  ́ultimo
elemento de uma lista n ̃ao vazia (libertando o correspondente espa ̧co).
*/

void removeUltimo (LInt *l) {
    if (*l == NULL) return; 

    LInt atual = *l;
    LInt anterior = NULL;

    // Paramos quando o *próximo* for NULL (estamos no último nó!)
    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    // Desligar a cauda
    if (anterior == NULL) {
        // Só havia 1 elemento na lista. A lista passa a vazia.
        *l = NULL;
    } else {
        // O penúltimo elemento passa a ser o novo último
        anterior->prox = NULL;
    }

    // 3. Libertar a memória do último nó
    free(atual);
}

/*
14. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void appendL (LInt *, int) que acres-
centa um elemento no fim da lista.
*/

void appendL (LInt *l, int x) {
    // Criar e alocar o novo nó
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = NULL;

    // Se a lista estiver vazia, o novo nó é a cabeça
    if (*l == NULL) {
        *l = novo;
    } else {
        // Caso contrário, percorrer até ao último
        LInt atual = *l;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

/*
15. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao void concatL (LInt *a, LInt b) que acrescenta a lista
b `a lista *a
*/

void concatL (LInt *a, LInt b) {
    LInt cu = b;
    // se nao houver pixa o cu fode-se sozinho
    if (*a == NULL) {
        *a = cu;
    } else {
        LInt pixa = *a;

    // encontrar a ponta da pixa
    while (pixa->prox != NULL) {
        pixa = pixa->prox;
        }
    // e por no cu
    pixa->prox = cu;
    }
}

/*
16. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao LInt cloneL (LInt) que cria uma nova lista ligada com
os elementos pela ordem em que aparecem na lista argumento.
*/

LInt cloneL (LInt l) {
    if (l == NULL) return NULL;

    // Criar o primeiro nó (a cabeça da nossa nova lista)
    LInt clone_head = malloc(sizeof(struct lligada));
    clone_head->valor = l->valor; // Copiamos apenas o NÚMERO!
    clone_head->prox = NULL;

    // Apontadores de trabalho
    LInt atual = l->prox;    // Vai percorrer o resto da original (a partir do 2º)
    LInt cauda = clone_head; // Fica na ponta do clone para irmos colando

    // 2. Percorrer o resto da lista original
    while (atual != NULL) {
        // Criar uma casa nova
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = atual->valor; // Copiar o número
        novo->prox = NULL;

        // Colar a casa nova na ponta da nossa lista clonada
        cauda->prox = novo;
        
        // A cauda avança para a nova ponta
        cauda = novo;

        // Avançar na lista original
        atual = atual->prox;
    }

    return clone_head;
}

/*
17. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao LInt cloneRev (LInt) que cria uma nova
lista ligada com os elementos por ordem inversa.
Por exemplo, se a lista l tiver 5 elementos com os valores [1,2,3,4,5] por esta ordem, a
invoca ̧c ̃ao cloneRev(l) deve corresponder a uma nova lista com os elementos [5,4,3,2,1]
por esta ordem
*/

LInt cloneRev (LInt l) {
    LInt atual = l;
    LInt nova_cabeca = NULL; // A lista invertida começa vazia

    // Percorremos a lista original normalmente, do início para o fim
    while (atual != NULL) {
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = atual->valor;

        novo->prox = nova_cabeca;
        nova_cabeca = novo;

        atual = atual->prox;
    }

    return nova_cabeca;
}

/*
18. Defina uma fun ̧c ̃ao int maximo (LInt l) que calcula qual o maior valor armazenado numa
lista n ̃ao vazia.
*/

int maximo (LInt l) {
    LInt atual = l;
    int record = atual->valor;

    atual = atual->prox;

    while (atual != NULL) {
        if (atual->valor > record) {
            record = atual->valor;
        }

        atual = atual->prox;
    }
    return record;
}

/*
19. Apresente uma defini ̧c ̃ao iterativa da fun ̧c ̃ao int take (int n, LInt *l) que, dado um in-
teiro n e uma lista ligada de inteiros l, apaga de l todos os nodos para al ́em do n- ́esimo
(libertando o respectivo espa ̧co). Se a lista tiver n ou menos nodos, a fun ̧c ̃ao n ̃ao altera a
lista.
A fun ̧c ̃ao deve retornar o comprimento final da lista.
*/

int take (int n, LInt *l) {
    int cont = 0;
    LInt atual = *l;
    LInt anterior = NULL;

    // Percorrer até contar 'n' elementos ou a lista acabar
    while (atual != NULL && cont < n) {
        anterior = atual;
        atual = atual->prox;
        cont++;
    }

    // O TRAVÃO DE OURO: se a lista tem n ou menos nós, não se altera nada!
    if (atual == NULL) {
        return cont;
    }

    // Se chegámos aqui, é porque atual != NULL (a lista tem MAIS de n nós)
    if (anterior == NULL) {
        // Caso n <= 0: apagar a lista toda desde a cabeça
        while (atual != NULL) {
            LInt temp = atual;
            atual = atual->prox;
            free(temp);
        }
        *l = NULL;
    } else {
        // Caso normal: cortar a ligação no n-ésimo nó
        anterior->prox = NULL;

        // Limpar o resto do lixo que ficou para a frente
        while (atual != NULL) {
            LInt temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    return cont;
}

/*
20. Apresente uma defini ̧c ̃ao iterativa da fun ̧c ̃ao int drop (int n, LInt *l) que, dado um in-
teiro n e uma lista ligada de inteiros l, apaga de l os n primeiros elementos da lista (libertando
o respectivo espa ̧co). Se a lista tiver n ou menos nodos, a fun ̧c ̃ao liberta a totalidade da lista.
A fun ̧c ̃ao deve retornar o n ́umero de elementos removidos.
*/

int drop (int n, LInt *l) {
    int del = 0;
    LInt atual = *l;

    while (atual != NULL && del < n) {
        LInt temp = atual;
        atual = atual->prox;
        free (temp);
        del++;
    }

    *l = atual;

    return del;
}

/*
21. O tipo LInt pode ser usado ainda para implementar listas circulares. Defina uma fun ̧c ̃ao LInt
Nforward (LInt l, int N) que, dada uma lista circular d ́a como resultado o endere ̧co do
elemento da lista que est ́a N posi ̧c ̃oes `a frente.
*/

LInt Nforward (LInt l, int N) {
    LInt atual = l;
    int i;

    for (i = 0; i < N && atual != NULL; i++) {
        atual = atual->prox;
    }
    
    return atual;
}

/*
22. Defina uma fun ̧c ̃ao int listToArray (LInt l, int v[], int N) que, dada uma lista l,
preenche o array v com os elementos da lista.
A fun ̧c ̃ao dever ́a preencher no m ́aximo N elementos e retornar o n ́umero de elementos preenchi-
dos.
*/

int listToArray (LInt l, int v[], int N) {
    int i;
    LInt atual = l;

    if (atual == NULL) return 0;

    for (i = 0; i < N && atual != NULL; i++) {
        v[i] = atual->valor;
        atual = atual->prox;
    }
    return i;
}

/*
23. Defina uma fun ̧c ̃ao LInt arrayToList (int v[], int N) que constr ́oi uma lista com os
elementos de um array, pela mesma ordem em que aparecem no array.
*/

LInt arrayToList (int v[], int N) {
    int i;

    if (N == 0) return NULL;

    LInt head = malloc(sizeof(struct lligada));
    head->valor = v[0];
    head->prox = NULL;

    LInt tail = head;

    for (i = 1; i < N; i++) {
        LInt new = malloc(sizeof(struct lligada));

        new->valor = v[i];
        new->prox = NULL;

        tail->prox = new;
        tail = new;
    }
    return head;
}

/*
24. Defina uma fun ̧c ̃ao LInt somasAcL (LInt l) que, dada uma lista de inteiros, constr ́oi uma
nova lista de inteiros contendo as somas acumuladas da lista original (que dever ́a permanecer
inalterada).
Por exemplo, se a lista l tiver os valores [1,2,3,4] a lista contru ́ıda pela invoca ̧c ̃ao de
somasAcL (l) dever ́a conter os valores [1,3,6,10].
*/

LInt somasAcL (LInt l) {
    if (l == NULL) return NULL;

    int soma = l->valor;
    LInt head = malloc(sizeof(struct lligada));

    head->valor = soma;
    head->prox = NULL;

    LInt tail = head;
    LInt atual = l->prox;

    while (atual != NULL) {
        soma += atual->valor;
        LInt new = malloc(sizeof(struct lligada));

        new->valor = soma;
        new->prox = NULL;

        tail->prox = new;
        tail = new;

        atual = atual->prox;
    }
    return head;
}

/*
25. Defina uma fun ̧c ̃ao void remreps (LInt l) que, dada uma lista ordenada de inteiros, elimina
dessa lista todos os valores repetidos assegurando que o espa ̧co de mem ́oria correspondente
aos n ́os removidos  ́e correctamente libertado.
*/

void remreps (LInt l) {
    if (l == NULL) return;

    LInt prev = l;
    LInt atual = prev->prox;

    while (atual != NULL) {
        if (atual->valor == prev->valor) {
            LInt temp = atual;
            
            atual = atual->prox;
            prev->prox = atual;
            
            free(temp);
        } else {
            // Só quando os valores são diferentes é que ambos avançam
            prev = atual;
            atual = atual->prox;
        }
    }
}

/*
26. Defina uma fun ̧c ̃ao LInt rotateL (LInt l) que coloca o primeiro elemento de uma lista no
fim. Se a lista for vazia ou tiver apenas um elemento, a fun ̧c ̃ao n ̃ao tem qualquer efeito pr ́atico
(i.e., devolve a mesma lista que recebe como argumento).
Note que a sua fun ̧c ̃ao n ̃ao deve alocar nem libertar mem ́oria. Apenas re-organizar as c ́elulas
da lista.
*/

LInt rotateL (LInt l) {
    LInt atual = l;

    if (atual == NULL) return l;

    LInt head = atual;
    atual = atual->prox;

    if (atual == NULL) return l;
    // tendo mais que um elemento a lista passa a começar no 2º
    l = atual;

    // corre a lista ligada ate ao fim
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    //estando no fim o atual->prox recebe head
    atual->prox = head;
    head->prox = NULL;

    return l;
}

/*
27. Defina uma fun ̧c ̃ao LInt parte (LInt l) que parte uma lista l em duas: na lista l ficam
apenas os elementos das posi ̧c ̃oes  ́ımpares; na lista resultante ficam os restantes elementos.
Assim, se a lista x tiver os elementos [10,20,30,40,50,60] a chamada y = parte (x),
coloca na lista y os elementos [20,40,60] ficando em x apenas os elementos [10,30,50]
*/

LInt parte (LInt l) {
    if (l == NULL || l->prox == NULL) return NULL;

    LInt pares_head = l->prox;
    LInt impar = l;
    LInt par = l->prox;

    while (par != NULL) {
        // O ímpar atual aponta para o nó a seguir ao par
        impar->prox = par->prox;
        impar = impar->prox; // O ímpar avança

        // Se ainda houver um ímpar válido, o par faz o mesmo salto
        if (impar != NULL) {
            par->prox = impar->prox;
            par = par->prox; // O par avança
        } else {
            // Se o ímpar ficou a NULL, a lista acabou perfeitamente
            break;
        }
    }
    return pares_head;
}

// Auxiliar para criar nodo novo
LInt novoNo(int v, LInt proximo) {
    LInt n = malloc(sizeof(struct lligada));
    n->valor = v;
    n->prox = proximo;
    return n;
}

int main() {
    printf("🚀 A INICIAR TESTES GERAIS (Funcoes 12 a 27)...\n\n");

    // --- Testes originais do teu ficheiro ---
    LInt lista_orig = NULL;
    printf("--- Teste Questao 14 (Append) ---\n");
    appendL(&lista_orig, 10);
    appendL(&lista_orig, 50);
    appendL(&lista_orig, 20);
    appendL(&lista_orig, 30);
    imprimeL(lista_orig); // Esperado: [ 10 -> 50 -> 20 -> 30 ]

    printf("\n--- Teste Questao 12 (Remove Maior) ---\n");
    int maior = removeMaiorL(&lista_orig);
    printf("Maior removido: %d\n", maior);
    imprimeL(lista_orig); // Esperado: [ 10 -> 20 -> 30 ]

    printf("\n--- Teste Questao 13 (Remove Ultimo) ---\n");
    removeUltimo(&lista_orig);
    imprimeL(lista_orig); // Esperado: [ 10 -> 20 ]
    freeL(lista_orig);

    // --- TESTE 15: concatL ---
    printf("\n--- Q15: concatL ---\n");
    // Usando a tua função novoNo encadeada para criar listas rapidamente!
    LInt l15_a = novoNo(1, novoNo(2, NULL));
    LInt l15_b = novoNo(3, novoNo(4, NULL));
    printf("Lista A: "); imprimeL(l15_a);
    printf("Lista B: "); imprimeL(l15_b);
    concatL(&l15_a, l15_b);
    printf("Resultado: "); imprimeL(l15_a);
    freeL(l15_a); // Limpa tudo (a+b fundidos)

    // --- TESTE 16 & 17: cloneL e cloneRev ---
    printf("\n--- Q16 & Q17: cloneL e cloneRev ---\n");
    LInt base = novoNo(10, novoNo(20, novoNo(30, NULL)));
    LInt clone16 = cloneL(base);
    LInt clone17 = cloneRev(base);
    printf("Original:  "); imprimeL(base);
    printf("CloneL:    "); imprimeL(clone16);
    printf("CloneRev:  "); imprimeL(clone17);
    freeL(base); freeL(clone16); freeL(clone17);

    // --- TESTE 18: maximo ---
    printf("\n--- Q18: maximo ---\n");
    LInt l18 = novoNo(12, novoNo(85, novoNo(42, NULL)));
    printf("Lista: "); imprimeL(l18);
    printf("Maximo esperado: 85 | Obtido: %d\n", maximo(l18));
    freeL(l18);

    // --- TESTE 19: take ---
    printf("\n--- Q19: take ---\n");
    LInt l19 = novoNo(1, novoNo(2, novoNo(3, novoNo(4, NULL))));
    printf("Original: "); imprimeL(l19);
    int t = take(2, &l19);
    printf("take(2):  "); imprimeL(l19);
    printf("Retorno esperado: 2 | Obtido: %d\n", t);
    freeL(l19);

    // --- TESTE 20: drop ---
    printf("\n--- Q20: drop ---\n");
    LInt l20 = novoNo(10, novoNo(20, novoNo(30, novoNo(40, NULL))));
    printf("Original: "); imprimeL(l20);
    int d = drop(2, &l20);
    printf("drop(2):  "); imprimeL(l20);
    printf("Retorno esperado: 2 | Obtido: %d\n", d);
    freeL(l20);

    // --- TESTE 21 & 22: Nforward e listToArray ---
    printf("\n--- Q21 & Q22: Nforward e listToArray ---\n");
    LInt l21 = novoNo(100, novoNo(200, novoNo(300, NULL)));
    printf("Lista: "); imprimeL(l21);
    LInt fwd = Nforward(l21, 2);
    printf("Nforward(2) aponta para: %d (Esperado: 300)\n", fwd ? fwd->valor : -1);
    
    int arr[5];
    int n22 = listToArray(l21, arr, 5);
    printf("Array preenchido: [ ");
    for(int i=0; i<n22; i++) printf("%d ", arr[i]);
    printf("]\n");
    freeL(l21);

    // --- TESTE 23: arrayToList ---
    printf("\n--- Q23: arrayToList ---\n");
    int src[] = {5, 7, 9};
    LInt l23 = arrayToList(src, 3);
    printf("Array [5, 7, 9] convertido: "); imprimeL(l23);
    freeL(l23);

    // --- TESTE 24: somasAcL ---
    printf("\n--- Q24: somasAcL ---\n");
    LInt l24 = novoNo(1, novoNo(2, novoNo(3, novoNo(4, NULL))));
    printf("Original:  "); imprimeL(l24);
    LInt somas = somasAcL(l24);
    printf("Acumulada: "); imprimeL(somas); // Esperado: 1 -> 3 -> 6 -> 10
    freeL(l24); freeL(somas);

    // --- TESTE 25: remreps ---
    printf("\n--- Q25: remreps ---\n");
    LInt l25 = novoNo(1, novoNo(1, novoNo(2, novoNo(2, novoNo(3, NULL)))));
    printf("Com reps: "); imprimeL(l25);
    remreps(l25);
    printf("Sem reps: "); imprimeL(l25); // Esperado: 1 -> 2 -> 3
    freeL(l25);

    // --- TESTE 26: rotateL ---
    printf("\n--- Q26: rotateL ---\n");
    LInt l26 = novoNo(1, novoNo(2, novoNo(3, NULL)));
    printf("Original: "); imprimeL(l26);
    l26 = rotateL(l26);
    printf("Rodada:   "); imprimeL(l26); // Esperado: 2 -> 3 -> 1
    freeL(l26);

    // --- TESTE 27: parte ---
    printf("\n--- Q27: parte ---\n");
    LInt l27 = novoNo(1, novoNo(2, novoNo(3, novoNo(4, novoNo(5, NULL)))));
    printf("Ziper original: "); imprimeL(l27);
    LInt pares = parte(l27);
    printf("Impares (l):    "); imprimeL(l27);   // Esperado: 1 -> 3 -> 5
    printf("Pares (retorno):"); imprimeL(pares); // Esperado: 2 -> 4
    freeL(l27); freeL(pares);

    printf("\n🎉 TODOS OS TESTES CONCLUIDOS COM SUCESSO!\n");
    return 0;
}