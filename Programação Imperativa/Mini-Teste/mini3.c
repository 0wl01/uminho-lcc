#include <stdio.h>
#include <stdlib.h>

typedef struct message {
    int value;
    int timestamp;
    struct message *next;
} *LLig;

// Função auxiliar para adicionar nós no fim da lista
LLig addNode(LLig list, int v, int t) {
    LLig new = malloc(sizeof(struct message));
    new->value = v;
    new->timestamp = t;
    new->next = NULL;

    if (list == NULL) return new;

    LLig pt = list;
    while (pt->next != NULL) {
        pt = pt->next;
    }
    pt->next = new;
    return list;
}

// A função principal do exercício
long long processarMensagens(LLig lista) {
    // Array para guardar o maior timestamp para cada value (de 0 a 9)
    // Inicializamos tudo a 0
    long long max_timestamps[10] = {0}; 
    long long soma_cubos = 0;

    // 1. Percorrer a lista ligada
    LLig pt = lista;
    while (pt != NULL) {
        int v = pt->value;
        int t = pt->timestamp;
        
        // 2. Se o timestamp atual for maior que o que temos guardado para este valor, atualizamos
        if (t > max_timestamps[v]) {
            max_timestamps[v] = t;
        }
        
        pt = pt->next; // Avançar para o próximo nó
    }

    // 3. Calcular a soma dos cubos dos valores finais no array
    for (int i = 0; i < 10; i++) {
        if (max_timestamps[i] > 0) { // Se o valor existir (timestamp > 0)
            // Calculamos o cubo e somamos (usamos long long para evitar overflow)
            soma_cubos += (max_timestamps[i] * max_timestamps[i] * max_timestamps[i]);
        }
    }

    return soma_cubos;
}

// Função auxiliar para libertar a memória da lista
void freeList(LLig list) {
    LLig temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

int main() {
    LLig lista = NULL;
    
    // Lista do mini teste
    int dados[][2] = {
        {9,32}, {2,26}, {5,24}, {3,22}, {3,28}, {3,24}, {9,15}, {7,37}, 
        {2,24}, {7,36}, {7,7}, {1,30}, {7,24}, {8,22}, {7,25}, {8,6}, 
        {3,20}, {5,24}, {6,39}, {1,21}, {9,10}, {9,27}, {9,27}, {8,33}, 
        {8,28}, {2,5}, {2,5}, {3,38}, {9,37}, {8,33}
    };
    
    int num_nodos = sizeof(dados) / sizeof(dados[0]);
    for (int i = 0; i < num_nodos; i++) {
        lista = addNode(lista, dados[i][0], dados[i][1]);
    }

    long long resultado = processarMensagens(lista);
    
    // Imprimir o resultado
    printf("A soma dos cubos e: %lld\n", resultado);

    // Limpar a memória no fim
    freeList(lista);

    return 0;
}