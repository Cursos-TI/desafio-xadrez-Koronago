
#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para verificar se é possível posicionar um navio no tabuleiro
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != VALOR_AGUA) {
                return 0; // Sobreposição
            }
        }
    } else if (orientacao == 1) { // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != VALOR_AGUA) {
                return 0; // Sobreposição
            }
        }
    } else {
        return 0; // Orientação inválida
    }
    return 1; // Pode posicionar
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (podePosicionarNavio(tabuleiro, linha, coluna, orientacao)) {
        if (orientacao == 0) { // Horizontal
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha][coluna + i] = VALOR_NAVIO;
            }
        } else if (orientacao == 1) { // Vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = VALOR_NAVIO;
            }
        }
    } else {
        printf("Erro: Não é possível posicionar o navio na posição (%d, %d) com orientação %d.\n", linha, coluna, orientacao);
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Definir posições iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;
    int orientacaoHorizontal = 0; // 0 para horizontal

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;
    int orientacaoVertical = 1; // 1 para vertical

    // Posicionar os navios no tabuleiro
    posicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, orientacaoHorizontal);
    posicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, orientacaoVertical);

    // Exibir o tabuleiro
    printf("Tabuleiro Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

 
