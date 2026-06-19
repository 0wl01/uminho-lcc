#include <stdio.h>
#include <string.h> // Estritamente necessário para o strlen() usado na Q18 e Q19

/*
7. Apresente uma definicao da funcao pre-definida em C char *strcat (char s1[], char
s2[]) que concatena a string s2 a s1 (retornando o endereco da primeira).
*/

char *mystrcat (char s1[], char s2[]) {
    int i = 0, j = 0;
    //Avançamos até a posição de '\0' em s1
    while (s1[i] != '\0') i++;
    //Estando no final da primeira string começamos a avançar posições 
    while (s2[j] != '\0') {
        s1[i] = s2[j]; //copiando a sting2 à frente do fim da s1
        i++;
        j++;
    }

    //E fechamos a nova s1
    s1[i] = '\0';

    return s1;
}
/*
8. Apresente uma definicao da funcao pre-definida em C char *strcpy (char *dest, char
source[]) que copia a string source para dest retornando o valor desta  ́ultima.
*/

char *mystrcpy (char *dest, char source[]) {
    int i = 0;

    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

/*
9. Apresente uma definicao da funcao pre-definida em C int strcmp (char s1[], char s2[])
que compara (lexicograficamente) duas strings. O resultado devera ser
•0 se as strings forem iguais
•<0 se s1 < s2
•>0 se s1 > s2
*/

int mystrcmp (char s1[], char s2[]) {
    int i = 0;


    while (s1[i] == s2[i] && s1[i] != '\0') i++;

    return s1[i] - s2[i];
}

/*
10. Apresente uma definicao da funcao pre-definida em C char *strstr (char s1[], char
s2[]) que determina a posicao onde a string s2 ocorre em s1. A funcao devera retornar
NULL caso s2 nao ocorra em s1.
*/

char *mystrstr(char s1[], char s2[]) {
    char *res = NULL;
    int i,p;
    
    if (s2[0] == '\0') return s1;
    
    for(i = 0; s1[i] != '\0' && res == NULL; i++) {
        for(p = 0; s2[p] != '\0' && s2[p] == s1[i+p];p++);
        if (s2[p] == '\0')
        res = s1 + i;
    }
    return res;
}

/*
11. Defina uma funcao void strrev (char s[]) que inverte uma string.
*/

void strrev (char s[]) {
    char temp;
    int i = 0, j = 0;

    //Chegar ao fim da string
    while(s[i] != '\0') i++;
    i--;

    while (i > j) {
        temp = s[j]; // O char inicial vai para a temp
        s[j] = s[i]; // o char final vai para o inicio
        s[i] = temp; // o char inicial que estava na temp vai para o fim

        i--; // i vai para o penultimo
        j++; // j vai para o segundo
        //E continuamos até chegar ao meio efetivamente trocando abcde para edcba
    }  
}

/*
12. Defina uma funcao void strnoV (char s[]) que retira todas as vogais de uma string.
*/

//Função Auxiliar isVogal que retorna 0 (Falso) senão for Vogal e 1 (True) se for.
int isVogal (char c) {
    int i;
    char v [] = "aeiouAEIOU";
    for (i = 0; v[i] != '\0'; i++) {
        if (c == v[i]) return 1;
    }
    return 0;
}

void strnoV (char s[]) {
    int read, write = 0;
    for(read = 0; s[read] != '\0'; read++) {
        if (!isVogal(s[read])) {
            s[write] = s[read];
            write++;
        }
    }
    s[write] = '\0';
}

/*
13. Defina uma funcao void truncW (char t[], int n) que dado um texto t com varias palavras
(as palavras estao separadas em t por um ou mais espacos) e um inteiro n, trunca todas as 
palavras de forma a terem no maximo n caracteres. Por exemplo, se a string txt
contiver "liberdade, igualdade e fraternidade", a invocacao de truncW (txt, 4) deve
fazer com que passe a estar l ́a armazenada a string "libe igua e frat"
*/

void truncW (char t[], int n) {
    int read, write = 0;
    int counter = 0;

    for (read = 0; t[read] != '\0'; read++) {
        // Se lermos um ' ', escrevemos o espaço e damos reset ao counter
        if (t[read] == ' ') {
            t[write] = t[read];
            write++;
            counter = 0;
        }
        // Otherwise, se ultrupassarmos o counter truncamos
        else if (counter < n) {
            t[write] = t[read];
            write++;
            counter++;
        }
    }
    t[write] = '\0';
}

/*
14. Defina uma funcao char charMaisfreq (char s[]) que determina qual o caracter mais frequente
numa string. A funcao devera retornar 0 no caso de s ser a string vazia.
*/

char charMaisFreq (char s[]) {
    int freq[256] = {0}; // Criamos um Array de Frequências cheio de 0's
    int i = 0, max = 0;
    char a = 0;

    //Percorremos a String guardando as frequências
    for (i = 0; s[i] != '\0'; i++) {
        freq[ (unsigned char)s[i] ]++;
    }

    //Depois de ter a lista de frequências corremos a mesma
    for (i = 0; i < 256; i++) {
        if (freq[i] > max) {
            max = freq[i];
            a = i;
        }
    }
    return a;
}

/*
15. Defina uma funcao int iguaisConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres iguais. Por exemplo, iguaisConsecutivos
("ababaabcccaac") deve dar como resultado 3, correspondendo a repeticao "ccc".
*/

int iguaisConsecutivos (char s[]) {
    int i, freq = 1, max = 1;
    char atual = s[0];

    if (s[0] == '\0')
        return 0;


    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] != atual) {
            atual = s[i];
            freq = 1;
        }
        else {
            freq++;
            if (freq > max) {
                max = freq;
            }
        }
    }
    return max;
}

/*
16. Defina uma funcao int difConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres diferentes. Por exemplo, difConsecutivos
("ababcaccaac") deve dar como resultado 3, correspondendo (por exemplo) a string "abc".
*/

int difConsecutivos (char s[]) {
    int posicoes[256];
    int i, max = 0, inicio = 0;

    for (i = 0; i < 256; i++) posicoes[i] = -1;

    for (i = 0; s[i] != '\0'; i++) {
        // c é var local para cada letra da string
        unsigned char c = (unsigned char)s[i];

        if (posicoes[c] >= inicio) {
            inicio = posicoes[c] + 1;
        }

        posicoes[c] = i;

        int tamanho_atual = i - inicio + 1;
        if (tamanho_atual > max) {
            max = tamanho_atual;
        }
    }
    return max;
}
/*
17. Defina uma funcao int maiorPrefixo (char s1 [], char s2 []) que calcula o
comprimento do maior prefixo comum entre as duas strings.
*/

int maiorPrefixo (char s1[], char s2[]) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;

    }
    return i;
}


/*18. Defina uma fun ̧c ̃ao int maiorSufixo (char s1 [], char s2 []) que calcula o compri-
mento do maior sufixo comum entre as duas strings.
*/

int maiorSufixo (char s1[], char s2[]) {
    int i = strlen(s1);
    int j = strlen(s2);
    int contador = 0;

    while (i > 0 && j > 0 && s1[i -1] == s2[j - 1]){
        i--;
        j--;
        contador++;
    }
    return contador;
}

/*
19. Defina a funcao int sufPref (char s1[], char s2[]) que calcula o tamanho do maior
sufixo de s1 que  ́e um prefixo de s2. Por exemplo sufPref("batota","totalidade") deve
dar como resultado 4, uma vez que a string "tota" e um sufixo de "batota" e um prefixo de
"totalidade".
*/

int sufPref (char s1[], char s2[]) {
    int i, tamanho;
    int n1 = strlen(s1);

    for (i = 0; s1[i] != '\0'; i++) {
        tamanho = maiorPrefixo(&s1[i], s2);

        if (tamanho == (n1 - i)) {
            return tamanho;
        }
    }
    return 0;
}

/*
20. Defina uma funcao int contaPal (char s[]) que conta as palavras de uma string. Uma
palavra e uma sequencia de caracteres (diferentes de espaco) terminada por um ou mais
espacos. Assim se a string p tiver o valor "a a bb a", o resultado de contaPal (p) deve ser
4.
*/

int contaPal (char s[]) {
    int i, palavras = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            while(s[i] != ' ' && s[i] != '\0') {
                i++;
            
            }
            palavras++;
            i--; //senão o for salta s[i]
        }
    }
    return palavras;
}

/*
21. Defina uma funcao int contaVogais (char s[]) que retorna o numero de vogais da strings
Nao se esqueca de considerar tanto maiusculas como minusculas
*/

int contaVogais (char s[]) {
    int i,j, vogais = 0;
    char v [] = "aeiouAEIOU";

    // Ciclo para percorrer 
    for (i = 0; s[i] != '\0'; i++) {
        for(j = 0; v[j] != '\0';j++){
            if (s[i] == v[j]) {
                vogais++;
                break;
            }
        }
    }
    return vogais;
}

/*
22. Defina uma funcao int contida (char a[], char b[]) que testa se todos os caracteres da
primeira string tambem aparecem na segunda. Por exemplo, contida ("braga","bracara
augusta") deve retornar verdadeiro enquanto que contida ("braga","bracarense") deve
retornar falso.
*/

int contida (char s[], char b[]) {
    int i, j, flag;

    for (i = 0; s[i] != '\0'; i++) {
        flag = 0;
        for (j = 0; b[j] != '\0'; j++) {
            if (s[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return 0;
        }
    }
    return 1;
}

/*
23. Defina uma funcao int palindorome (char s[]) que testa se uma palavra  ́e palındrome,
i.e., le-se de igual forma nos dois sentidos.
*/

int palindrome (char s[]) {
    int i, j;

    for (j = 0; s[j] != '\0'; j++);
    j--;

    for (i = 0; i < j; ) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

/*
24. Defina uma funcao int remRep (char x[]) que elimina de uma string todos os caracteres
que se repetem sucessivamente deixando la apenas uma copia. A funcao devera retornar o
comprimento da string resultante. Assim, por exemplo, ao invocarmos a funcao com uma
vector contendo "aaabaaabbbaaa", o vector deve passar a conter a string "ababa" e a funcao
devera retornar o valor 5.
*/

int remRep (char x[]) {
    if (x[0] == '\0') return 0;

    int i;
    int j = 1;

    for (i = 1; x[i] != '\0'; i++) {
        if (x[i] != x[i - 1]) {
            x[j] = x[i];
            j++;
        }
    }
    x[j] = '\0';
    return j;
}

/*
25. Defina uma funcao int limpaEspacos (char t[]) que elimina repeticoes sucessivas de espacos
por um unico espaco. A funcao deve retornar o comprimento da string resultante.
*/

int limpaEspacos (char t[]) {
    // Se a string for vazia, devolvemos 0
    if (t[0] == '\0') return 0;

    int i;
    int j = 1; // A caneta começa na posição 1

    for (i = 1; t[i] != '\0'; i++) {
        
        // Se NÃO for um duplo espaço, escrevemos!
        if (t[i] != ' ' || t[i - 1] != ' ') {
            t[j] = t[i];
            j++;
        }
    }
    
    t[j] = '\0';
    return j;
}

int main() {
    printf("🚀 A INICIAR TESTES: char&string.c (Q7 a Q25)\n\n");

    char s1[50] = "Ola ";
    char s2[] = "Mundo";
    printf("Q7 (mystrcat): '%s'\n", mystrcat(s1, s2));

    char dest[50];
    printf("Q8 (mystrcpy): '%s'\n", mystrcpy(dest, "Copia Perfeita"));
    printf("Q9 (mystrcmp): %d\n", mystrcmp("abc", "abd")); // Esperado: < 0

    char texto[] = "Aprender C e incrivel";
    printf("Q10 (mystrstr): '%s'\n", mystrstr(texto, "C e")); 

    char rev[] = "Roma";
    strrev(rev);
    printf("Q11 (strrev): '%s'\n", rev);

    char semVogais[] = "Estruturas";
    strnoV(semVogais);
    printf("Q12 (strnoV): '%s'\n", semVogais);

    char trunc[] = "liberdade, igualdade e fraternidade";
    truncW(trunc, 4);
    printf("Q13 (truncW): '%s'\n", trunc);

    printf("Q14 (charMaisFreq): '%c'\n", charMaisFreq("abracadabra")); // Esperado: 'a'
    printf("Q15 (iguaisConsecutivos): %d\n", iguaisConsecutivos("ababaabcccaac")); // Esperado: 3
    printf("Q16 (difConsecutivos): %d\n", difConsecutivos("ababcaccaac")); // Esperado: 3
    printf("Q17 (maiorPrefixo): %d\n", maiorPrefixo("carro", "caravana")); // Esperado: 3
    printf("Q18 (maiorSufixo): %d\n", maiorSufixo("programacao", "computacao")); // Esperado: 4
    printf("Q19 (sufPref): %d\n", sufPref("batota", "totalidade")); // Esperado: 4
    printf("Q20 (contaPal): %d\n", contaPal(" a a bb a ")); // Esperado: 4
    printf("Q21 (contaVogais): %d\n", contaVogais("Universidade")); // Esperado: 6
    printf("Q22 (contida): %d\n", contida("braga", "bracara augusta")); // Esperado: 1
    printf("Q23 (palindrome): %d\n", palindrome("radar")); // Esperado: 1

    char reps[] = "aaabaaabbbaaa";
    int len24 = remRep(reps);
    printf("Q24 (remRep): '%s' (Len: %d)\n", reps, len24);

    char espacos[] = "muitos    espacos   juntos";
    int len25 = limpaEspacos(espacos);
    printf("Q25 (limpaEspacos): '%s' (Len: %d)\n\n", espacos, len25);

    printf("🎉 TESTES CONCLUIDOS!\n");
    return 0;
}