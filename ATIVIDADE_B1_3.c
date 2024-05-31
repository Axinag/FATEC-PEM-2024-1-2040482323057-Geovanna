//Tabuleiro de Xadrez

#include <stdio.h>

// Função void para preencher o tabuleiro de xadrez com peças
void preencherTabuleiro(char tabuleiro[8][8]) {
    // Peças Brancas = B
    tabuleiro[0][0] = 'B'; // Torre à esquerda (T1)
    tabuleiro[0][1] = 'B'; // Cavalo à esquerda (C1)
    tabuleiro[0][2] = 'B'; // Bispo à esquerda (B1)
    tabuleiro[0][3] = 'B'; // Rainha
    tabuleiro[0][4] = 'B'; // Rei
    tabuleiro[0][5] = 'B'; // Bispo à direita (B2)
    tabuleiro[0][6] = 'B'; // Cavalo à direita (C2)
    tabuleiro[0][7] = 'B'; // Torre à direita (T2)

    for (int i = 0; i < 8; i++) {
        tabuleiro[1][i] = 'B'; // Peões Brancos (BP1 até BP8)
    }

    // Espaços vazios = X
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = 'X'; // Espaço vazio
        }
    }

    // Peças Pretas = P
    for (int i = 0; i < 8; i++) {
        tabuleiro[6][i] = 'P'; // Peões Pretos (PP1 até PP8)
    }

    tabuleiro[7][0] = 'P'; // Torre à esquerda (T1)
    tabuleiro[7][1] = 'P'; // Cavalo à esquerda (C1)
    tabuleiro[7][2] = 'P'; // Bispo à esquerda (B1)
    tabuleiro[7][3] = 'P'; // Rainha
    tabuleiro[7][4] = 'P'; // Rei
    tabuleiro[7][5] = 'P'; // Bispo à direita (B2)
    tabuleiro[7][6] = 'P'; // Cavalo à direita (C2)
    tabuleiro[7][7] = 'P'; // Torre à direita (T2)
}

// Função void para exibir o tabuleiro de xadrez
void exibirTabuleiro(char tabuleiro[8][8]) {
    printf("  a b c d e f g h\n"); // Números de colunas
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i); // Números de fileiras
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]); // Exibir peça ou espaço vazio
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[8][8];

    preencherTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);

    return 0;
}
