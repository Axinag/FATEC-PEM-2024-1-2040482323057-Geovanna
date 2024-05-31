//Tabuleiro de Xadrez

#include <stdio.h>
// matrizes, vetores, representar a tabela = tabuleiro
// Função void para preencher o tabuleiro de xadrez com as peças

//Brncas (T1)(C1)(B1)RainhaRei(B2)(C2)(T2)
//Pretas (T1)(C1)(B1)ReiRainha(B2)(C2)(T2)

int main(){
void preencherTabuleiro(char tabuleiro[8][8]) {
    // Peças Brancas = B
    tabuleiro[0][0] = 'B'; 
    tabuleiro[0][1] = 'B'; 
    tabuleiro[0][2] = 'B';
    tabuleiro[0][3] = 'B'; 
    tabuleiro[0][4] = 'B'; 
    tabuleiro[0][5] = 'B'; 
    tabuleiro[0][6] = 'B';
    tabuleiro[0][7] = 'B'; 

    for (int i = 0; i < 8; i++) {
        tabuleiro[1][i] = 'B'; 
    }

    // Espaços vazios são o x
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = 'X'; 
        }
    }

    // Peças Pretas = P
    
    for (int i = 0; i < 8; i++) {
        tabuleiro[6][i] = 'P'; 
    }

    tabuleiro[7][0] = 'P';
    tabuleiro[7][1] = 'P'; 
    tabuleiro[7][2] = 'P'; 
    tabuleiro[7][3] = 'P';
    tabuleiro[7][4] = 'P'; 
    tabuleiro[7][5] = 'P'; 
    tabuleiro[7][6] = 'P'; 
    tabuleiro[7][7] = 'P';
}

void exibirTabuleiro(char tabuleiro[8][8]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
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
