#include <stdio.h>
#include <stdlib.h>

//Exercicio 1 - Estado e Atribuições
/*
Estado e atribui¸c˜oes
Diga, justificando, qual o output de cada um dos seguintes excertos de c´odigo C. 
Pode comprovar a sua resposta copiando o c´odigo de cada uma das al´ıneas para aqui

1.
int x, y;
x = 3; y = x+1;
x = x*y; y = x + y;
printf("%d %d\n", x, y);

Resposta: x = 3 e y = 3 + 1 , depois x * y logo x = 12 e por fim y = 12 + 4 = 16
printf imprime o ultimo valor de x e y, 12 e 16

2.
int x, y;
x = 0;
printf ("%d %d\n", x, y);

Resposta: Vai imprimir os valores para x (neste caso 0) e y vai ser imprevisivel... (lixo de memoria)

3. (assuma que os c´odigos ASCII dos caracteres ’A’, ’0’, ’ ’ e ’a’ s˜ao respectivamente
65, 48, 32 e 97)
char a, b, c;
a = ’A’; b = ’ ’; c = ’0’;
printf ("%c %d\n", a, a);
a = a+1; c = c+2;
printf ("%c %d %c %d\n", a, a, c, c);
c = a + b;
printf ("%c %d\n", c, c);

Resposta: printf('A' 65)
a = 65 + 1 = 66 == 'B' ; c = 48 + 2 = 50
printf('B' 66 '2' 50)
c = 66 + 32 = 98 = 'b'
printf('b' 98)

4.
int x, y;
x = 200; y = 100;
x = x+y; y = x-y; x = x-y;
printf ("%d %d\n", x, y);

Resposta: x = 200 + 100 = 300
y = 300 - 100 = 200
x = 300 - 200 = 100
printf(100 200)
*/

//Exercicio 2 - Estruturas de Controlo

/*
1. Diga, justificando, qual o output de cada um dos seguintes excertos de c´odigo C. Mais
uma vez, pode usar o C Tutor para validar a sua resposta.

(a)
int x, y;
x = 3; y = 5;
if (x > y)
y = 6;
printf ("%d %d\n", x, y);

Resposta: "3 5"
*/

/*
(b)
int x, y;
x = y = 0;
while (x != 11) {
x = x+1; y += x;
}
printf ("%d %d\n", x, y);

1º: x = 1 ; y = 1 + 0
2º: x = 2 ; y = 3
3º: x = 3 ; y = 6
4º: x = 4 ; y = 10
5º: x = 5 ; y = 15
6º : x = 6 ; y = 21
7º: x = 7 ; y = 28
8º: x = 8 ; y = 36
9º: x = 9 ; y = 45
10: x = 10 , y = 55
11º: x = 11 ; y = 66
12º: x==11 , while acabou

Resposta: "11 55"
*/

/*
(c)
int i;
for (i=0; (i<20) ; i++)
if (i%2 == 0) putchar (’_’);
else putchar (’#’);

Output: "_#_#_#_#_#_#_#_#_#_#"
*/

/*
(d)
void f (int n) {
    while (n>0) {
        if (n%2 == 0) putchar (’0’);
        else putchar (’1’);
        n = n/2;
    }
    putchar (’\n’);
}

int main () {
    int i;
        for (i=0;(i<16);i++)
        f (i);
    return 0;
}

Output: " " e depois transforma os numeros de 1 a 15 em binario mas em ordem inversa
*/

// Exercicio 3 - Programas Iterativos
/*
1. Escreva um programa que desenhe no ecran (usando o caracter #) um quadrado de
dimens˜ao 5. O resultado da invoca¸c˜ao da fun¸c˜ao com um argumento 5 dever´a ser
#####
#####
#####
#####
#####
*/

void quadrado (int n) {
    int i, j;
    //Ciclo das Linhas (atingindo o n troca de linha com "\n")
    for (i = 0; i < n ; i++) {
        //Ciclo para as Colunas (escreve '#' n vezes)
        for (j = 0 ; j < n ; j++) {
            putchar ('#');
        }
        putchar ('\n'); //depois de escrever '#' n vezes mudamos de linha, quando i == n acaba o ciclo
    }
}

/*
2. Escreva um programa que desenhe no ecran (usando os caracteres # e _) um tabuleiro
de xadrez. O resultado da invoca¸c˜ao dessa fun¸c˜ao com um argumento 5 dever´a ser
#_#_#
_#_#_
#_#_#
_#_#_
#_#_#
*/

void xadrez (int n) {
    int i, j;
    //Ciclo das Linhas (atingindo o n troca de linha com "\n")
    for (i = 0; i < n ; i++) {
        //Ciclo para as Colunas (escreve '#' ou '_' n vezes consoante for par ou impar)
        for (j = 0 ; j < n ; j++) {
            if ((i + j) % 2 == 0) putchar ('#');
            else putchar ('_');
        }
        putchar ('\n'); //depois de escrever o padrao n vezes mudamos de linha, quando i == n acaba o ciclo
    }
}

/*
3. Escreva duas fun¸c˜oes que desenham triangulos (usando o caracter #). O resultado da
invoca¸c˜ao dessas fun¸c˜oes com um argumento 5 dever´a ser

#
##
###
####
#####
####
###
##
#
    #
   ###
  #####
 #######
#########
*/

void triangulo_sup (int n) {
    int i, j;
    for (i = 1; i <= n; i++) { //enquanto o i < n
        for (j = 0; j < i; j++) { //vamos imprimindo numa linha i vezes '#'
        putchar ('#');
        }
        putchar ('\n'); //após imprimir passamos a outra linha
    }
    for (i = n - 1; i > 0; i--) { //depois do i==n começamos a decrescer
        for (j = 0; j < i; j++) {
        putchar ('#'); //imprimindo '#' a cada linha até que i seja 0
        }
        putchar ('\n');
    } 
}

void triangulo_inf (int n) {
    int i, j;
    //Ciclo das Linhas
    for (i = 1; i <= n; i++) {
        //Ciclo dos Espaços ( n - i)
        for (j = 0; j < (n - i); j++) {
            putchar (' ');
        }
        //Ciclo dos Cardinais
        for (j = 0; j < (2 * i - 1); j++) {
            putchar ('#');
        }
        putchar ('\n'); //muda de linha
    }
}

/*
4. Escreva um programa que desenhe no ecran (usando o caracter #) um circulo. O pro-
grama dever´a come¸car por ler o raio do c´ırculo pretendido. O resultado para um valor
de raio 4 dever´a ser
    #
  #####
 #######
 #######
#########
 #######
 #######
  #####
    #
*/

void circulo (int raio) {
    int x, y;
    int caracteres = 0;
    //Ciclo no Eixo Y
    for (y = raio; y >= -raio; y--) {
        //Ciclo no Eixo x
        for ( x = -raio; x <= raio; x++) {
            if (x*x + y*y <= raio*raio) {
                putchar ('#'); //se a posição estiver dentro do raio, imprimimos cardinal
                caracteres++;
            }
            else {
                putchar (' ');
            }
        }
        putchar ('\n');
    }
    printf("Foram usados %d caracteres\n", caracteres);
}

int main() {
    int r;
    printf("Insira o raio desejado\n");
    scanf("%d", &r);
    circulo(r);
    return 0;
}