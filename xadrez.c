#include <stdio.h>

// Define quantas casas cada peça vai andar
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8

// Constantes para o movimento do Cavalo
#define PASSOS_BAIXO_CAVALO 2
#define PASSOS_ESQUERDA_CAVALO 1

// Funções para mover cada peça, retornando int
int moverTorre();
int moverBispo();
int moverRainha();
int moverCavalo(); // Nova função para o Cavalo

int main() {
    printf("--- Movimentando a Torre ---\n");
    moverTorre(); // Chama a função da Torre
    printf("\n");

    printf("--- Movimentando o Bispo ---\n");
    moverBispo(); // Chama a função do Bispo
    printf("\n");

    printf("--- Movimentando a Rainha ---\n");
    moverRainha(); // Chama a função da Rainha
    printf("\n");

    // Movimento do Cavalo
    printf("--- Movimentando o Cavalo ---\n");
    moverCavalo(); // Chama a função do Cavalo
    printf("\n");

    return 0; // Indica que o programa principal terminou com sucesso.
}

/**
 * Move a Torre CASAS_TORRE casas para a direita usando 'for'.
 * Retorna 0 para indicar que a função completou.
 */
int moverTorre() {
    // Loop 'for': repete o movimento CASAS_TORRE vezes.
    for (int i = 0; i < CASAS_TORRE; i++) {
        printf("Direita\n"); // Mostra o movimento.
    }
    return 0; // Retorna 0 indicando sucesso.
}

/**
 * Move o Bispo CASAS_BISPO casas na diagonal (cima, direita) usando 'while'.
 * Retorna 0 para indicar que a função completou.
 */
int moverBispo() {
    int casasMovidas = 0; // Conta as casas que o Bispo já andou.

    // Loop 'while': repete enquanto 'casasMovidas' for menor que CASAS_BISPO.
    while (casasMovidas < CASAS_BISPO) {
        printf("Cima, Direita\n"); // Mostra o movimento diagonal.
        casasMovidas++;             // Incrementa o contador.
    }
    return 0; // Retorna 0 indicando sucesso.
}

/**
 * Move a Rainha CASAS_RAINHA casas para a esquerda usando 'do-while'.
 * Retorna 0 para indicar que a função completou.
 */
int moverRainha() {
    int casasPercorridas = 0; // Conta as casas que a Rainha já andou.

    // Só executa se houver casas para mover.
    if (CASAS_RAINHA > 0) {
        // Loop 'do-while': primeiro faz o movimento, depois verifica.
        do {
            printf("Esquerda\n");     // Mostra o movimento.
            casasPercorridas++;   // Incrementa o contador.
        } while (casasPercorridas < CASAS_RAINHA);
    }
    return 0; // Retorna 0 indicando sucesso.
}

/**
 * Simula o movimento do Cavalo: 2 casas para baixo, 1 para a esquerda.
 * Utiliza um loop 'for' externo obrigatório e loops 'while' internos aninhados.
 * Retorna 0 para indicar que a função completou.
 */
int moverCavalo() {
    // Loop 'for' externo: controla as duas fases principais do movimento em "L".
    // fase_movimento = 0: movimento vertical (para baixo).
    // fase_movimento = 1: movimento horizontal (para a esquerda).
    for (int fase_movimento = 0; fase_movimento < 2; fase_movimento++) {
        
        if (fase_movimento == 0) { // Primeira fase: mover para baixo
            // Loop 'while' interno para os passos verticais.
            // Este loop está aninhado dentro do 'for' e executa para os PASSOS_BAIXO_CAVALO.
            int contador_passos_verticais = 0;
            while (contador_passos_verticais < PASSOS_BAIXO_CAVALO) {
                printf("Baixo\n");
                contador_passos_verticais++;
            }
        } else { // Segunda fase: mover para a esquerda (ocorre quando fase_movimento == 1)
            // Loop 'while' interno para os passos horizontais.
            // Este loop também está aninhado dentro do 'for' (no bloco 'else')
            // e executa para os PASSOS_ESQUERDA_CAVALO.
            int contador_passos_horizontais = 0;
            while (contador_passos_horizontais < PASSOS_ESQUERDA_CAVALO) {
                printf("Esquerda\n");
                contador_passos_horizontais++;
            }
        }
    }
    return 0; // Retorna 0 indicando sucesso.
}