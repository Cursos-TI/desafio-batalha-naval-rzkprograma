#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linha][coluna + i] != 0) return 0;
    } else if (orientacao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha][coluna + i] = 3;
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha + i][coluna] = 3;
    }
}

int podePosicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'P') { // principal ( \ )
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linha + i][coluna + i] != 0) return 0;
    } else if (direcao == 'S') { // secundaria ( / )
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - (TAMANHO_NAVIO - 1) < 0) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linha + i][coluna - i] != 0) return 0;
    }
    return 1;
}

void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'P') {
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha + i][coluna + i] = 3;
    } else if (direcao == 'S') {
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha + i][coluna - i] = 3;
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%c ", 'A' + col);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Navios horizontais/verticais
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    if (podePosicionarNavio(tabuleiro, linhaH, colunaH, 'H'))
        posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    else
        printf("Erro: navio horizontal invalido.\n");

    if (podePosicionarNavio(tabuleiro, linhaV, colunaV, 'V'))
        posicionarNavio(tabuleiro, linhaV, colunaV, 'V');
    else
        printf("Erro: navio vertical invalido.\n");

    // Navios diagonais
    int linhaD1 = 0, colunaD1 = 0; // diagonal principal
    int linhaD2 = 0, colunaD2 = 9; // diagonal secundaria

    if (podePosicionarNavioDiagonal(tabuleiro, linhaD1, colunaD1, 'P'))
        posicionarNavioDiagonal(tabuleiro, linhaD1, colunaD1, 'P');
    else
        printf("Erro: navio diagonal principal invalido.\n");

    if (podePosicionarNavioDiagonal(tabuleiro, linhaD2, colunaD2, 'S'))
        posicionarNavioDiagonal(tabuleiro, linhaD2, colunaD2, 'S');
    else
        printf("Erro: navio diagonal secundaria invalido.\n");

    exibirTabuleiro(tabuleiro);


}
