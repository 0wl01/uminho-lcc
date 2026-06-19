#include <stdio.h>
#include <stdlib.h>

/*
1. Defina uma funcao int contaVogais (char *s) que conta quantas vogais uma string tem.
*/

int contaVogais (char *s) {
    int i, vogais = 0;

    for (i = 0; s[i] != '\0'; i++) {
        // Verifica se o caractere atual é uma vogal
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U') {
            
            vogais++;
        }
    }
    return vogais;
}

/*
2. Defina uma fun ̧c ̃ao int retiraVogaisRep (char *s) que remove de uma string todas as repe-
ti ̧c ̃oes consecutivas de vogais. A fun ̧c ̃ao dever ́a retornar o n ́umero de vogas removidas. Por e-
xemplo, se a string a == "Estaa e umaa string coom duuuplicadoos", depois de invocarmos
retiraVogaisRep a, a string a dever ́a ter o valor "Esta e uma string com duplicados".
•Para evitar fazer muitos deslocamentos de caracteres, apresente uma defini ̧c ̃ao que usa um
array auxiliar onde a string resultante ser ́a constru ́ıda. No final ter ́a que copiar essa string
de volta para o array argumento.
•Altere a fun ̧c ̃ao que definiu acima de forma a n ̃ao precisar de usar o array auxiliar.
*/

int retiraVogaisRep (char *s) {
    char aux[strlen(s) + 1]; // Array auxiliar seguro
    int i, j = 0, removidos = 0;

    for (i = 0; s[i] != '\0'; i++) {
        // Se for uma vogal e igual à anterior, ignoramos (não copiamos para o aux)
        if (isVogal(s[i]) && i > 0 && isVogal(s[i-1]) && s[i] == s[i-1]) {
            removidos++;
        } else {
            // Caso contrário, copiamos para o auxiliar
            aux[j++] = s[i];
        }
    }
    aux[j] = '\0'; // Terminador da nova string

    // Copiar de volta para o array original, conforme pedido 
    strcpy(s, aux);

    return removidos;
}

int retiraVogaisREP (char *s) {
    int read, write = 1, removidos = 0;

    if (s[0] == '\0') return 0;

    for (read = 1; s[read] != '\0'; read++) {
        if (isVogal(s[read]) && s[read] == s[read - 1]) {
            removidos++;
        } else {
            s[write] = s[read];
            write++;
        }
    }
    s[write] = '\0';

    return removidos;
}

/*
3. Defina uma fun ̧c ̃ao int duplicaVogais (char *s) que duplica todas as vogais de uma string.
A fun ̧c ̃ao deve retornar o n ́umero de caracteres acrescentados. Assuma que o array recebido
como argumento tem capacidade para armazenar o resultado pretendido.
•Mais uma vez, e de forma a evitar muitos deslocamentos de caracteres, defina esta fun ̧c ̃ao
usando um array auxiliar para construir a string resultante.
•Apresente ainda uma defini ̧c ̃ao alternativa onde n ̃ao seja de facto necess ́ario usar o dito
array auxiliar.
*/

int duplicaVogais (char *s) {
    char aux[strlen(s) * 2 + 1];
    int read, write = 0, duplicadas = 0;

    for (read = 0; s[read] != '\0'; read++) {
        if (isVogal(s[read])) {
            aux[write++] = s[read];
            aux[write++] = s[read];
            duplicadas++;
        } else {
            aux[write++] = s[read];
        }
    }
    aux[write] = '\0';
    strcpy(s, aux);

    return duplicadas;
}

int duplicaVogaisInPlace (char *s) {
    int i, n_vogais = 0, len = strlen(s);
    
    // 1. Contar quantas vogais existem
    for (i = 0; s[i] != '\0'; i++) {
        if (isVogal(s[i])) n_vogais++;
    }
    
    // Se não há vogais, não há nada a fazer
    if (n_vogais == 0) return 0;
    
    // 2. Definir os ponteiros
    int read = len;         // Começa no terminador '\0'
    int write = len + n_vogais; // Nova posição final
    
    s[write] = '\0';        // Colocar o novo terminador
    
    // 3. Percorrer de trás para a frente
    while (read >= 0) {
        if (isVogal(s[read])) {
            s[write--] = s[read]; // Copia a vogal
            s[write--] = s[read]; // Duplica a vogal
        } else {
            s[write--] = s[read]; // Copia a consoante normalmente
        }
        read--;
    }
    
    return n_vogais;
}

/*
1. Defina uma fun ̧c ̃ao int ordenado (int v[], int N) que testa se um array de inteiros est ́a
ordenado por ordem crescente.
*/

int ordenado (int v[], int N) {
    int i;

    if (N <= 1) return 1;

    for (i = 1; i < N; i++) {
        if (v[i] < v[i - 1]) return 0;
    }
    return 1;
}

/*
2. Defina uma fun ̧c ̃ao void merge (int a[], int na, int b[], int nb, int r[]) que recebe
dois arrays ordenados a e b (com tamanhos na e nb respectivamente) e os funde num s ́o array
ordenado r. Assuma que o array r tem capacidade para armazenar os na+nb elementos.
*/

void merge (int a[], int na, int b[], int nb, int r[]) {
    int readA = 0, readB = 0, write = 0;

    while (readA < na && readB < nb) {
        if (a[readA] < b[readB]) {
            r[write++] = a[readA++];
        } else {
            r[write++] = b[readB++];
        }
    }

    while (readA < na) r[write++] = a[readA++];

    while (readB < nb) r[write++] = b[readB++];
}

/*
3. Defina uma fun ̧c ̃ao int partition (int v[], int N, int x) que, dado um array v de tamanho
N e um inteiro x, reorganiza o array de forma a que come ̧cam por aparecer todos os elementos
menores ou iguais a x seguidos dos restantes elementos. A fun ̧c ̃ao retorna o n ́umero de elementos
que ficaram na primeira parte do array (i.e., que s ̃ao menores ou iguais a x)

•Comece por definir uma vers ̃ao desta fun ̧c ̃oa que usa um array auxiliar para construir o
resultado pretendido. No final deve copiar o conte ́udo desse array de volta para o array
recebido como argumento.
•Apresente uma defini ̧c ̃ao alternativa para esta fun ̧c ̃ao que n ̃ao usa um array auxiliar. Para
isso considere a seguinte estrat ́egia:

Sejam a e b dois  ́ındices do array em que se verifica a seguinte propriedade:
–todos os elementos nos  ́ındices [0..a[ s ̃ao menores ou iguais a x
–todos os elementos nos  ́ındices [a..b[ s ̃ao maiores do que x
*/

int partition (int v[], int N, int x) {
    int aux[N];
    int i, p = 0; // p é o contador de elementos <= x

    // 1. Primeira passagem: guarda os menores ou iguais
    for (i = 0; i < N; i++) {
        if (v[i] <= x) {
            aux[p++] = v[i];
        }
    }
    
    // O valor atual de 'p' é o número de elementos <= x

    // 2. Segunda passagem: guarda os maiores
    for (i = 0; i < N; i++) {
        if (v[i] > x) {
            aux[p++] = v[i];
        }
    }

    // 3. Copiar de volta
    for (i = 0; i < N; i++) {
        v[i] = aux[i];
    }

    return p; // Retorna quantos ficaram na primeira parte
}

int partitionInPlace (int v[], int N, int x) {
    int a = 0; // Onde vamos colocar o próximo elemento <= x
    int i, temp;

    for (i = 0; i < N; i++) {
        if (v[i] <= x) {
            // Troca o elemento v[i] com o v[a]
            temp = v[i];
            v[i] = v[a];
            v[a] = temp;
            
            // Avança a zona dos menores
            a++;
        }
    }
    return a; // 'a' é exatamente o número de elementos menores ou iguais a x
}