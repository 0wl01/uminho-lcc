#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do estudante
struct Student {
    int number;
    char activity[100];
};

// Conta o número de atividades únicas na string
int distinctActivities(const char *activity) {
    int counts[256] = {0}; // Array para marcar os caracteres encontrados
    int distinct = 0;
    
    for (int i = 0; activity[i] != '\0'; i++) {
        // Se a atividade ainda não foi contada, incrementa
        if (counts[(unsigned char)activity[i]] == 0) {
            distinct++;
            counts[(unsigned char)activity[i]] = 1;
        }
    }
    return distinct;
}

// Encontra a maior sequência consecutiva da mesma atividade
int longestStreak(const char *activity) {
    if (activity == NULL || activity[0] == '\0') {
        return 0;
    }
    
    int max_streak = 1;
    int current_streak = 1;
    
    for (int i = 1; activity[i] != '\0'; i++) {
        if (activity[i] == activity[i - 1]) {
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 1; // Reinicia a contagem
        }
    }
    
    // Verifica uma última vez no final da string
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }
    
    return max_streak;
}

// Calcula a pontuação final
int engagement(const char *activity) {
    return distinctActivities(activity) * longestStreak(activity);
}

// Função de comparação para o qsort
int compareStudents(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    
    int scoreA = engagement(studentA->activity);
    int scoreB = engagement(studentB->activity);
    
    // Critério 1: Ordenar por pontuação de forma decrescente
    if (scoreA != scoreB) {
        return scoreB - scoreA; 
    } 
    // Critério 2: Em caso de empate, ordenar por número de forma crescente
    else {
        return studentA->number - studentB->number;
    }
}

struct Student escola [] = {
    {5,  "EEPRRPP"}, {8,  "LLLSSLL"}, {24, "RPRPRRL"}, {3,  "SSSPPSS"}, {1,  "PPPEEEPPP"},
    {15, "LRLLLLR"}, {11, "ERRREEE"}, {2,  "SSSLLLSS"}, {7,  "PPLLPPLL"}, {12, "RRRSSSRR"},
    {19, "EEERRREEE"}, {4,  "LLPPSSLL"}, {9,  "SSSEEESSL"}, {16, "PPPRRRLLL"}, {21, "LLLSSSLLL"},
    {6,  "ERRRRPPP"}, {13, "PPPSSSPP"}, {25, "RRRLLLERR"}, {10, "SSSPPPSS"}, {18, "LLLEEELLL"},
    {14, "EEERRREEE"}, {17, "SSSPPPSSS"}, {20, "LLLEEERRR"}, {22, "PPPLLLLLL"}, {23, "SSSRRRSSS"},
    {26, "EEEPPPLL"}, {27, "LLRRRRPPP"}
};

int main() {
    
    int num_students = sizeof(escola) / sizeof(escola[0]);
    
    qsort(escola, num_students, sizeof(struct Student), compareStudents);
    
    // Impressão do resultado
    printf("Final rank:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Rank %d -> number %d\n", i + 1, escola[i].number);
    }
    
    return 0;
}