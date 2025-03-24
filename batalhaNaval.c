#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    char letras[] = "ABCDEFGHIJ";

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona os navios (valores fixos)
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 6; // Navio vertical

    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("\nTABULEIRO BATALHA NAVAL\n\n");
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == NAVIO) {
                printf("\033[1;31m%d \033[0m", tabuleiro[i][j]); // Cor vermelha para navios
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
