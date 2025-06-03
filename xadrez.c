#include <stdio.h>

// --- Constantes para Movimento das Peças ---
#define CASAS_TORRE 5                // Torre: 5 casas para direita
#define CASAS_BISPO 5                // Bispo: 5 casas diagonal (Cima, Direita)
#define CASAS_RAINHA 8               // Rainha: 8 casas para esquerda
#define PASSOS_CIMA_CAVALO_NOVO 2    // Cavalo: 2 casas para cima (novo movimento)
#define PASSOS_DIREITA_CAVALO_NOVO 1 // Cavalo: 1 casa para direita (novo movimento)

// --- Protótipos das Funções ---

// Funções principais de cada peça (interface para o main)
int moverTorre();
int moverBispo();
int moverRainha();
int moverCavalo();

// Funções auxiliares para a lógica recursiva
int moverTorreRecursivo(int casasRestantes);
int moverBispoRecursivo(int passosDiagonaisRestantes);
int moverRainhaRecursivo(int casasRestantes);

// Função auxiliar do Bispo para demonstrar loops aninhados em um passo diagonal
int imprimirPassoDiagonalBispoComLoopsAninhados();


// --- Função Principal ---
int main() {
    printf("--- Movimentando a Torre (Recursivo) ---\n");
    moverTorre();
    printf("\n");

    printf("--- Movimentando o Bispo (Recursivo e Loops Aninhados) ---\n");
    moverBispo();
    printf("\n");

    printf("--- Movimentando a Rainha (Recursivo) ---\n");
    moverRainha();
    printf("\n");

    printf("--- Movimentando o Cavalo (Loops Complexos: 2 Cima, 1 Direita) ---\n");
    moverCavalo();
    printf("\n");

    return 0; // Programa finalizado com sucesso
}

// --- Implementações das Funções de Movimento ---

// TORRE (Implementação Recursiva)
/**
 * @brief Inicia o movimento da Torre.
 * Chama a função recursiva correspondente.
 */
int moverTorre() {
    // Delega para a função recursiva, passando o total de casas a mover.
    return moverTorreRecursivo(CASAS_TORRE);
}

/**
 * @brief Função recursiva que simula o movimento da Torre.
 * @param casasRestantes Número de casas que ainda faltam para a Torre se mover.
 */
int moverTorreRecursivo(int casasRestantes) {
    // Caso base: Se não há mais casas para mover, a recursão termina.
    if (casasRestantes <= 0) {
        return 0; // Fim do movimento
    }

    // Ação do passo: Imprime o movimento ("Direita").
    printf("Direita\n");

    // Chamada recursiva: Continua para a próxima casa, decrementando casasRestantes.
    return moverTorreRecursivo(casasRestantes - 1);
}


// BISPO (Implementação Recursiva com Loops Aninhados por passo)
/**
 * @brief Inicia o movimento do Bispo.
 * Utiliza recursão para o número de passos e loops aninhados para a impressão de cada passo.
 */
int moverBispo() {
    // Delega para a função recursiva, passando o total de passos diagonais.
    return moverBispoRecursivo(CASAS_BISPO);
}

/**
 * @brief Função recursiva para os passos diagonais do Bispo.
 * @param passosDiagonaisRestantes Número de passos diagonais que ainda faltam.
 */
int moverBispoRecursivo(int passosDiagonaisRestantes) {
    // Caso base: Se não há mais passos diagonais, a recursão termina.
    if (passosDiagonaisRestantes <= 0) {
        return 0; // Fim do movimento
    }

    // Ação do passo: Imprime um passo diagonal ("Cima, Direita")
    // usando a função auxiliar com loops aninhados.
    imprimirPassoDiagonalBispoComLoopsAninhados();

    // Chamada recursiva: Avança para o próximo passo diagonal.
    return moverBispoRecursivo(passosDiagonaisRestantes - 1);
}

/**
 * @brief Imprime um único passo diagonal ("Cima, Direita") do Bispo.
 * Demonstra o uso de loops aninhados conforme especificado:
 * loop externo para o componente vertical e interno para o horizontal.
 */
int imprimirPassoDiagonalBispoComLoopsAninhados() {
    // Loop externo: representa o componente vertical ("Cima") do passo diagonal.
    // Para um único passo, este loop executa uma vez.
    for (int mov_vertical_componente = 0; mov_vertical_componente < 1; mov_vertical_componente++) {
        // Loop interno: representa o componente horizontal ("Direita") do passo diagonal.
        // Também executa uma vez para um único passo.
        for (int mov_horizontal_componente = 0; mov_horizontal_componente < 1; mov_horizontal_componente++) {
            // Imprime o movimento diagonal combinado.
            printf("Cima, Direita\n");
        }
    }
    return 0;
}


// RAINHA (Implementação Recursiva)
/**
 * @brief Inicia o movimento da Rainha.
 * Chama a função recursiva correspondente.
 */
int moverRainha() {
    // Delega para a função recursiva, passando o total de casas a mover.
    return moverRainhaRecursivo(CASAS_RAINHA);
}

/**
 * @brief Função recursiva que simula o movimento da Rainha.
 * @param casasRestantes Número de casas que ainda faltam para a Rainha se mover.
 */
int moverRainhaRecursivo(int casasRestantes) {
    // Caso base: Se não há mais casas para mover, a recursão termina.
    if (casasRestantes <= 0) {
        return 0; // Fim do movimento
    }

    // Ação do passo: Imprime o movimento ("Esquerda").
    printf("Esquerda\n");

    // Chamada recursiva: Continua para a próxima casa.
    return moverRainhaRecursivo(casasRestantes - 1);
}


// CAVALO (Implementação com Loops Complexos)
/**
 * @brief Move o Cavalo em "L": 2 casas para Cima, 1 casa para Direita.
 * Utiliza loops com múltiplas variáveis, condições, e as instruções 'continue' e 'break'.
 */
int moverCavalo() {
    // Contadores para os passos do movimento em "L" do Cavalo.
    int passos_cima_dados = 0;         // Guarda quantos passos para cima já foram dados.
    int passos_direita_dados = 0;      // Guarda quantos passos para direita já foram dados.
    int total_passos_L_executados = 0; // Total de etapas do "L" que foram concluídas (de 3).

    // Define o total de etapas para um movimento em "L" completo (2 Cima + 1 Direita = 3).
    const int TOTAL_ETAPAS_L_CAVALO = PASSOS_CIMA_CAVALO_NOVO + PASSOS_DIREITA_CAVALO_NOVO;

    // Loop principal de controle:
    // O loop é configurado para rodar um pouco mais (MAX_ITER_DEMO) do que as 3 etapas
    // necessárias, para demonstrar o uso do 'break' quando o movimento "L" se completa.
    const int MAX_ITER_DEMO = 5; // Um valor maior que TOTAL_ETAPAS_L_CAVALO.
    for (int iter_controle = 0; iter_controle < MAX_ITER_DEMO; iter_controle++) {

        // Condição de parada (uso do 'break'):
        // Se o total de passos do "L" já foi executado, o movimento está completo.
        // O 'break' interrompe o loop 'for' imediatamente.
        if (total_passos_L_executados >= TOTAL_ETAPAS_L_CAVALO) {
            break; // Sai do loop 'for', pois o Cavalo completou seu movimento.
        }

        // Fase 1 do "L": Movimento para Cima.
        // Verifica se ainda é necessário dar passos para cima.
        if (passos_cima_dados < PASSOS_CIMA_CAVALO_NOVO) {
            printf("Cima\n");
            passos_cima_dados++;          // Incrementa o contador de passos para cima.
            total_passos_L_executados++;  // Incrementa o contador total de etapas do "L".

            // Condição para 'continue':
            // Se o movimento "L" ainda não terminou, 'continue' pula o resto desta
            // iteração do loop 'for' e avança para a próxima. Isso permite que o Cavalo
            // dê o próximo passo (que pode ser outro para cima ou a verificação de 'break').
            if (total_passos_L_executados < TOTAL_ETAPAS_L_CAVALO) {
                continue; // Pula para a próxima iteração, para o próximo passo do "L".
            } else {
                // Se o "L" terminou exatamente após este passo para cima (ocorreria
                // apenas se PASSOS_DIREITA_CAVALO_NOVO fosse 0).
                break; // Movimento completo, sai do loop.
            }
        }
        // Fase 2 do "L": Movimento para Direita.
        // Esta parte só é executada se todos os passos para Cima já foram dados
        // (porque a condição do 'if' acima será falsa e o 'continue' não terá sido chamado).
        else if (passos_direita_dados < PASSOS_DIREITA_CAVALO_NOVO) {
            printf("Direita\n");
            passos_direita_dados++;       // Incrementa o contador de passos para direita.
            total_passos_L_executados++;  // Incrementa o contador total de etapas do "L".

            // Se o movimento "L" foi completado após este passo para direita
            // (esta é a forma usual de completar o "L" neste exemplo).
            if (total_passos_L_executados >= TOTAL_ETAPAS_L_CAVALO) {
                break; // Sai do loop, movimento completo.
            }
            // Se houvesse múltiplos passos para direita e o "L" ainda não estivesse completo,
            // um 'continue' aqui poderia ser usado (similar à lógica dos passos para cima).
        }
    }
    return 0; // Indica que a função do Cavalo completou.
    
}