#include <stdio.h>

struct ticket {
    int arrivalTime;
    int timeToSolve;
    int premiumCustomer;
};

int main() {

    struct ticket tickets[] = { 
        {1, 2, 0}, {6, 3, 1}, {10, 6, 1}, {15, 3, 1}, {16, 8, 1}, {19, 1, 1}, 
        {21, 8, 1}, {23, 6, 0}, {24, 3, 0}, {25, 4, 1}, {26, 2, 0}, {27, 4, 0}, 
        {28, 2, 0}, {29, 1, 1}, {30, 2, 0}, {38, 1, 0}, {52, 2, 0}, {62, 2, 0}, 
        {71, 2, 0}, {84, 3, 0}, {90, 6, 0}, {97, 1, 1}, {105, 5, 1}, {110, 2, 1}, 
        {113, 4, 0}, {116, 1, 0}, {119, 1, 0}, {121, 4, 0}, {123, 5, 0}, {126, 1, 0}, 
        {127, 5, 0}, {128, 6, 1}, {131, 5, 0}, {133, 4, 1}, {136, 1, 0}, {137, 4, 1}, 
        {139, 4, 0}, {142, 1, 1}, {144, 6, 0}, {145, 3, 0}, {148, 2, 1}, {149, 2, 0}, 
        {151, 5, 1}, {154, 5, 0}, {157, 13, 1}, {161, 15, 1}, {162, 8, 0}, {166, 14, 0}, 
        {170, 12, 1}, {174, 13, 0} 
    };

    int n = 50;
    int atendidos[50] = {0}; // Array para marcar os tickets já resolvidos (0 = não, 1 = sim)
    
    int total_atendidos = 0;
    int tempo_atual = 0;
    int max_tempo_servico = 0;

    // O ciclo continua até atendermos todos os 50 tickets
    while (total_atendidos < n) {
        int escolhido = -1;

        // 1. Procurar o melhor ticket para atender agora
        for (int i = 0; i < n; i++) {
            // Só olhamos para tickets que já chegaram e ainda não foram atendidos
            if (atendidos[i] == 0 && tickets[i].arrivalTime <= tempo_atual) {
                
                // Se ainda não escolhemos nenhum candidato, este é o primeiro
                if (escolhido == -1) {
                    escolhido = i;
                } 
                // Se já temos um candidato, mas o atual é premium e o candidato não é, trocamos!
                else if (tickets[i].premiumCustomer == 1 && tickets[escolhido].premiumCustomer == 0) {
                    escolhido = i;
                }
                // Se ambos tiverem a mesma prioridade, mantemos o 'escolhido' atual
                // (Como o array está ordenado por chegada, o primeiro que encontramos é sempre o mais antigo)
            }
        }

        // 2. Se não encontramos nenhum ticket à espera, o sistema está parado
        if (escolhido == -1) {
            // Avançamos o relógio para a hora de chegada do próximo ticket
            for (int i = 0; i < n; i++) {
                if (atendidos[i] == 0) {
                    tempo_atual = tickets[i].arrivalTime;
                    break; 
                }
            }
        } 
        // 3. Se escolhemos um ticket, vamos processá-lo
        else {
            // O tempo que demora = tempo atual + tempo de resolução
            int tempo_fim = tempo_atual + tickets[escolhido].timeToSolve;
            
            // O tempo de serviço = instante em que terminou - instante em que chegou
            int tempo_servico = tempo_fim - tickets[escolhido].arrivalTime;

            // Se for o maior tempo de serviço até agora, guardamos
            if (tempo_servico > max_tempo_servico) {
                max_tempo_servico = tempo_servico;
            }

            // Atualizamos o estado do sistema
            tempo_atual = tempo_fim;
            atendidos[escolhido] = 1;
            total_atendidos++;
        }
    }

    printf("%d\n", max_tempo_servico);

    return 0;
}