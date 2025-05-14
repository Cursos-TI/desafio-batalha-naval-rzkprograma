#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para verificar se é possível posicionar um navio
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

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha][coluna + i] = 3; // 3 representa o navio
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha + i][coluna] = 3; // 3 representa o navio
    }
}

// Funções para criar as matrizes das habilidades

void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i >= j && i + j < TAMANHO_HABILIDADE - 1) {
                habilidade[i][j] = 1; // Define as áreas afetadas como 1
            } else {
                habilidade[i][j] = 0; // Áreas não afetadas
            }
        }
    }
}

void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 2; // Define as áreas afetadas como 2 (Cruz)
            } else {
                habilidade[i][j] = 0; // Áreas não afetadas
            }
        }
    }
}

void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i + j >= TAMANHO_HABILIDADE / 2 && i + j <= 3 * TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 3; // Define as áreas afetadas como 3 (Octaedro)
            } else {
                habilidade[i][j] = 0; // Áreas não afetadas
            }
        }
    }
}

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = linhaOrigem + i - TAMANHO_HABILIDADE / 2;
            int coluna = colunaOrigem + j - TAMANHO_HABILIDADE / 2;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5; // 5 representa a área afetada pela habilidade
                } else if (habilidade[i][j] == 2 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5; // 5 representa a área afetada pela habilidade
                } else if (habilidade[i][j] == 3 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5; // 5 representa a área afetada pela habilidade
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%c ", 'A' + col);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf("0 ");  // Água
            else if (tabuleiro[i][j] == 3) printf("3 ");  // Navio
            else if (tabuleiro[i][j] == 5) printf("5 ");  // Área afetada pela habilidade
            else printf("%d ", tabuleiro[i][j]);  // 1, 2, ou 3 para as formas
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Criando as habilidades
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Posicionando alguns navios para o teste
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

    // Aplicando as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 5, 5);   // Habilidade Cone
    aplicarHabilidade(tabuleiro, habilidadeCruz, 4, 4);   // Habilidade Cruz
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 6, 6); // Habilidade Octaedro

    // Exibindo o tabuleiro com as habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}