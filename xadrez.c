#include <stdio.h>

// Define quantas casas cada peça vai andar
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8

// Funções para mover cada peça, agora retornando int
int moverTorre();
int moverBispo();
int moverRainha();

int main() {
    printf("--- Movimentando a Torre ---\n");
    moverTorre(); // Chama a função da Torre. O valor de retorno não é usado aqui.
    printf("\n");

    printf("--- Movimentando o Bispo ---\n");
    moverBispo(); // Chama a função do Bispo. O valor de retorno não é usado aqui.
    printf("\n");

    printf("--- Movimentando a Rainha ---\n");
    moverRainha(); // Chama a função da Rainha. O valor de retorno não é usado aqui.
    printf("\n");

    return 0; // Indica que o programa principal terminou com sucesso.
}

/**
 * Move a Torre CASAS_TORRE casas para a direita usando 'for'.
 * Retorna 0 para indicar que a função completou.
 */
int moverTorre() {
    // Loop 'for': repete o movimento CASAS_TORRE vezes.
    // 'i' conta de 0 até CASAS_TORRE - 1.
    for (int i = 0; i < CASAS_TORRE; i++) {
        printf("Direita\n"); // Mostra o movimento.
    }
    return 0; // Retorna 0 indicando sucesso/conclusão.
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
        casasMovidas++;             // Incrementa o contador de casas movidas.
    }
    return 0; // Retorna 0 indicando sucesso/conclusão.
}

/**
 * Move a Rainha CASAS_RAINHA casas para a esquerda usando 'do-while'.
 * Retorna 0 para indicar que a função completou.
 */
int moverRainha() {
    int casasPercorridas = 0; // Conta as casas que a Rainha já andou.

    // Só executa o movimento se CASAS_RAINHA for maior que 0.
    if (CASAS_RAINHA > 0) {
        // Loop 'do-while': primeiro faz o movimento, depois verifica se continua.
        // Repete enquanto 'casasPercorridas' for menor que CASAS_RAINHA.
        do {
            printf("Esquerda\n");     // Mostra o movimento.
            casasPercorridas++;   // Incrementa o contador de casas percorridas.
        } while (casasPercorridas < CASAS_RAINHA);
    }
    return 0; // Retorna 0 indicando sucesso/conclusão.
}