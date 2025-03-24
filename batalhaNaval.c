#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 0) {
            // Posiciona na horizontal
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            // Posiciona na vertical
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    char letras[] = "ABCDEFGHIJ";
    
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
}

int validarPosicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 0) {
            if (coluna + i >= TAMANHO || tabuleiro[linha][coluna + i] != 0) return 0;
        } else {
            if (linha + i >= TAMANHO || tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Definição das coordenadas iniciais
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 6; // Navio vertical
    
    if (validarPosicao(tabuleiro, linhaH, colunaH, 0)) {
        posicionarNavio(tabuleiro, linhaH, colunaH, 0);
    }
    
    if (validarPosicao(tabuleiro, linhaV, colunaV, 1)) {
        posicionarNavio(tabuleiro, linhaV, colunaV, 1);
    }
    
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
