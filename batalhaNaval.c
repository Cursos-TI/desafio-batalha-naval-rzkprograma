#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                return 0; // sobreposição detectada
            }
        }
    } else if (orientacao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                return 0; // sobreposição detectada
            }
        }
    }
    return 1; // pode posicionar
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3; // 3 representa navio
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3; // 3 representa navio
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime o cabeçalho (colunas com letras A-J)
    printf("   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%c ", 'A' + col);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas diretamente)
    int linhaNavioH = 2, colunaNavioH = 4; // navio horizontal
    int linhaNavioV = 5, colunaNavioV = 1; // navio vertical

    // Validação e posicionamento do navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H')) {
        posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H');
    } else {
        printf("Erro: não foi possível posicionar o navio horizontal.\n");
    }

    // Validação e posicionamento do navio vertical
    if (podePosicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V')) {
        posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V');
    } else {
        printf("Erro: não foi possível posicionar o navio vertical.\n");
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
