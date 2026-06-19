#include <stdio.h>
#include <stdlib.h>

/*
Ficha 2
Programação Imperativa
Algoritmos Num´ericos sobre inteiros
*/

/*
1. Podemos calcular o produto de um n´umero m por um inteiro n atrav´es
de um somat´orio de n parcelas constantes (e iguais a m).
Assim
n × m =
nX
i=1
m = m + m + · · · + m| {z }
n vezes
Este c´alculo pode ser efectuado somando n vezes a quantidade m a uma
vari´avel inicialmente com o valor 0.
Apresente uma defini¸c˜ao da fun¸c˜ao float multInt1 (int n, float m) baseada
nesta observa¸c˜ao: a uma vari´avel r (inicialmente com o valor 0) ser´a
somado o valor de m, n vezes. Essa vari´avel r vai ter os valores 0, m, 2*m,
3*m, . . . , e no final ter´a o valor desejado n*m.
*/

float multInt1 (int n , float m) {
    float r = 0;
    int i;
    //Ciclo for para somar n vezes
    /*for (i = 1; i <= n; i++) este foi a primeira ideia
    mas estou a typar vezes a mais, a seguinte é mais "preguiçosa"
    */
    for (i = 0; i < n; i++) {
        r += m;
    }

    return r;
}

/*
2. Uma forma alternativa (e muito mais eficiente) consiste em aproveitar a
representa¸c˜ao bin´aria dos inteiros (onde a multiplica¸c˜ao e divis˜ao
por 2 s˜ao pelo menos t˜ao eficientes como a adi¸c˜ao).
Dados dois n´umeros m e n podemos construir uma tabela em
que vamos dividindo (divis˜ao inteira) n por 2 e multiplicando
m por 2. A primeira linha da tabela tem o valor original de n
enquanto que a ´ultima corresponde a n ser 1.
Para obter o valor do produto de n por m basta somar os
valores de m correspondentes `as linhas em que n ´e impar.
A tabela ao lado corresponde a um exemplo em que n=81 e
m=423.
n m
1 81 423
2 40 846
3 20 1692
4 10 3384
5 5 6768
6 2 13536
7 1 27072
Se somarmos os valores de m para os quais n e impar (i.e., as linhas 1, 5 e 7)
obtemos 423 + 6768 + 27072 = 34263 = 81 ∗ 423.
Apresente uma defini¸c˜ao alternativa da fun¸c˜ao float multInt2 (int n, float m)
usando este processo.
Uma forma de nos certificarmos que de facto esta defini¸c˜ao ´e muito mais
eficiente ´e contar quantas opera¸c˜oes (entre floats) s˜ao feitas.
Modifique a sua defini¸c˜ao para ela produzir um resultado extra que conte
este n´umero e experimente para valores suficientemente grandes do valor de n.
*/

float multInt2 (int n, float m) {
    int opps = 0;
    float r = 0;
    //Ciclo While para percorrer operações até n == 1
    while (n > 0) {
        if (n % 2 != 0) {
            r += m;
            opps++;
        }
        n = n / 2;
        m = m * 2;
        opps++;
    }
    printf("Operações realizadas: %d\n", opps);

    return r;
}
/*mais eficiente, enquanto que a anterior com n = 90 teria 90 oppps
multInt2 resulta em apenas 11 opps
*/

/*
3. O c´alculo do m´aximo divisor comum entre dois n´umeros inteiros n˜ao
negativos pode ser feito, de uma forma muito pouco eficiente, procurando de
entre os divisores do menor deles, o maior que ´e tamb´em divisor do outro.
Defina uma fun¸c˜ao int mdc1 (int a, int b) que usa esse m´etodo para calcular
o m´aximo divisor comum entre dois n´umeros)
*/

int mdc1 (int a, int b) {
    //adicionei contador de iterações
    int i;
    //Começamos no menor dos dois como divisor
    int div = (a < b) ? a : b; //se a < b, guarda a caso contrario b
    //O Ciclo while só para quando ambas as condições forem falsas
    while (a % div != 0 || b % div != 0) {
        div--;
        i++;
    }
    printf("Iterações: %d\n", i);
    return div;
}

/*
4. Uma forma alternativa de calcular o m´aximo divisor comum (mdc) baseia-se
na seguinte propriedade demonstrada por Euclides: para a e b inteiros positivos,
mdc (a, b) = mdc (a + b, b)
esta propriedade podemos concluir que:
mdc (a, b) =



mdc (a − b, b) Se a > b
mdc (a, b − a) Se a < b
a Se a = b
O c´alculo do m´aximo dicvisor comum pode ser
feito por um processo repetitivo em que substitu-
imos o maior dos argumentos pela diferen¸ca en-
tre eles, at´e que um deles seja 0. Nessa altura, o
valor do outro corresponde ao valor pretendido.
Por exemplo, para calcularmos o m´aximo divisor
comum entre 126 e 45 passar´ıamos pelos estados
que se apresentam `a direita.
a b
126 45
81 (=126-45) 45
36 (=81-45) 45
36 9 (=45-36)
27 (=36-9) 9
18 (=27-9) 9
9 (=18-9) 9
0 (=9-9) 9
Apresente uma defini¸c˜ao alternativa da fun¸c˜ao int mdc2 (int a, int b) que 
usa esse m´etodo.
Mais uma vez, comprove que esta defini¸c˜ao ´e normalmente muito mais eficiente 
definindo uma vers˜ao que produz um resultado extra correspondente ao n´umero 
de itera¸c˜oes do ciclo.
*/

int mdc2 (int a, int b) {
    int i = 0;

    while (a > 0 && b > 0) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
        i++; //inscrementar o contador de ciclos
    }
    printf("Iterações: %d\n", i);

    return (a == 0) ? b : a; //se a for 0 retorna b else a
}

/*
eficiência mdc1 para a = 90 e b = 17 foram 16 iterações até chegar a 1.
Iterações: 16
MDC entre 90 e 17 é: 1

md2 conseguiu em menos 4 
Iterações: 12
MDC entre 90 e 17 é: 1

mdc3 conseguiu em 4...
Iterações: 4
MDC entre 90 e 17 é: 1
*/

/*
5. Uma forma de melhorar o comportamento do algoritmo de Euclides consiste em substi-
tuir as opera¸c˜oes de subtrac¸c˜ao por opera¸c˜oes de % (resto da divis˜ao inteira). Repita o
exerc´ıcio da al´ınea anterior para essa variante do algoritmo.
*/

int mdc3 (int a, int b) {
    int i = 0;
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b; //b passa a ser o resto
        a = temp; //a passa a ser o antigo b
        i++;
    }
    printf("Iterações: %d\n", i);
    return a;
}

/*
aumentando a = 1567890
mdc3 bate mdc2 por bastante...
Iterações: 92236
MDC entre 1567890 e 17 é: 1

mdc 3
Iterações: 5
MDC entre 1567890 e 17 é: 1
*/

/*
6. A sequˆencia de Fibonacci define-se como
fib (n) =



1 Se n < 2
fib (n − 1) + fib (n − 2) Se n ≥ 2
(a) Apresente uma defini¸c˜ao recursiva de uma fun¸c˜ao que int fib1 (int n) 
calcula o n-´esimo n´umero desta sequˆencia.
(b) O c´alculo do n-´esimo n´umero de Fibonacci pode ser definido de uma forma
mais eficiente (e iterativa) se repararmos que ele apenas necessita de 
conhecer os valores dos 2 valores anteriores. Apresente uma defini¸c˜ao 
alternativa (e iterativa) int fib2 (int n) da fun¸c˜ao da al´ınea anterior 
que calcula o n-´esimo n´umero de Fibonacci, usando duas vari´aveis auxiliares
que guardam os dois valores anteriores.
*/

//6(a)

int fibcursive (int n) {
    if (n < 2) {
        return 1;
    }
    else {
        return fibcursive (n - 1) + fibcursive (n -2); 
    }   
}

//6(b)

long long fib (int n) {
    if (n < 2) {
        return 1;
    }
    int i;
    long long a = 1; //fib(n-1)
    long long b = 1; //fib(n-2)
    long long res;

    for (i = 2; i < n; i++) {
        res = a + b;
        b = a;
        a = res;
    }
    return res;
}

int main() {
    int n = 90;
    long long resultado;

    resultado = fib(n);
    printf("Resultado: %lld\n", resultado);

    return 0;
}