#include <stdio.h>

/*
1. Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros inteiros ter-
minada com o n´umero 0 e imprime no ecran o maior elemento da sequˆencia.
*/

int maiorNum() {
    int numero;
    int maior;

    printf("Introduza uma sequência de números a terminar em '0'\n");

    //Lê o primeiro numero
    scanf("%d" , &numero);

    //Se for igual a 0 a sequência está vazia
    if (numero == 0) {
        printf("A sequência está vazia\n");
        return 0;
    }
    
    maior = numero;

    //Caso contrário continuamos a ler até encontrarmos 0
    while (numero != 0) {
        if (numero > maior) {
            maior = numero;
        }
        scanf("%d", &numero);
    }
    printf("O maior elemento da sequência é: %d\n", maior);

    return 0;
}

/*
2. Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros inteiros ter-
minada com o n´umero 0 e imprime no ecran a m´edia da sequˆencia.
*/

int media() {
    int numero;
    int somatorio = 0;
    int elementos = 0;

    printf("Introduza uma sequência de números a terminar em '0'\n");

    scanf("%d" , &numero);

    //Lemos a sequência até atingir 0 e vamos incrementando os elementos e somando numero ao somatorio
    while (numero != 0) {
        somatorio += numero;
        elementos++;
        scanf("%d" , &numero); //lemos o próximo numero e atribuimos à var
    }

    //calculo e impressão da media

    if (elementos == 0) {
        printf("Nenhum número introduzido\n"); //não podemos dividir por 0 portanto precisamos de evitar o erro
    }
    else { 
        double resultado = (double)somatorio / elementos;
        printf("A média é %f\n" , resultado);
    }

    return 0;
}

/*
3. Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia 
de n´umeros inteiros terminada com o n´umero 0 e imprime no ecran o 
segundo maior elemento.
*/

int segMaior() {
    int numero, maior = -1, secmaior = -1;

    printf("Insira a sequência de números a terminar em '0':\n");
    //Lê o primeiro numero
    scanf("%d", &numero);
    maior = numero;

    if (numero == 0) {
        printf("Sequência vazia\n");
        return 0;
    }

    while (numero != 0) {
        scanf("%d", &numero);
        if (maior < numero) {
            secmaior = maior; //o antigo maior passa para baixo
            maior = numero; //o novo maior sobe ao torno
        }

        else if (numero > secmaior && numero != maior) {
            secmaior = numero;
        }
    }

    printf("O segundo maior número é: %d\n", secmaior);

    return 0;
}

/*
4. Defina uma fun¸c˜ao int bitsUm (unsigned int n) que calcula o 
n´umero de bits iguais a 1 usados na representa¸c˜ao bin´aria de 
um dado n´umero n
*/

int bitsUm (unsigned int n) {
    int contador = 0;

    while (n != 0) {
        if (n % 2 == 1 ) {
            contador++;
        }
    n /= 2;
    }
    return contador;

}

/*
5. Defina uma fun¸c˜ao int trailingZ (unsigned int n) que 
calcula o n´umero de bits a 0 no final da representa¸c˜ao 
bin´aria de um n´umero (i.e., o expoente da maior potˆencia 
de 2 que ´e divisor desse n´umero).
*/

int trailingZ (unsigned int n) {
    int i, contador = 0;

    for (i = n; i < n; i /= 2) {
        if (i % 2 == 0) contador++;
    }
    return contador;
}

/*
6. Defina uma funcao int qDig (unsigned int n) que calcula o numero de dıgitos necessarios
para escrever o inteiro n em base decimal. Por exemplo, qDig (440) deve retornar 3.
*/

int qDig (unsigned int n) {
    int digitos = 0;

    do {
        digitos++;
        n /= 10;
    } while (n > 0);

    return digitos;
}

int main() {
    printf("🚀 A INICIAR TESTES: numeros.c (Q1 a Q6)\n\n");

    // Para testar Q1, Q2 e Q3 descomenta as chamadas abaixo (requerem input manual no terminal):
    // printf("--- Q1: maiorNum ---\n"); maiorNum();
    // printf("\n--- Q2: media ---\n"); media();
    // printf("\n--- Q3: segMaior ---\n"); segMaior();

    printf("--- Q4: bitsUm ---\n");
    unsigned int n4 = 13; // Binário: 1101 (três 1s)
    printf("Bits '1' em %u: %d (Esperado: 3)\n\n", n4, bitsUm(n4));

    printf("--- Q5: trailingZ ---\n");
    unsigned int n5 = 8; // Binário: 1000 (três 0s)
    printf("Trailing zeros em %u: %d (Esperado: 3)\n\n", n5, trailingZ(n5));

    printf("--- Q6: qDig ---\n");
    unsigned int n6 = 440;
    printf("Dígitos de %u: %d (Esperado: 3)\n\n", n6, qDig(n6));

    printf("🎉 TESTES CONCLUIDOS!\n");
    return 0;
}