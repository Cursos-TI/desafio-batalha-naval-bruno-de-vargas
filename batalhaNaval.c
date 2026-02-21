#include <stdio.h>

const int TAM = 10;

// Funções
void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void mostrarTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("  ");
    for (int j = 0; j < TAM; j++)
        printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM][TAM];
    int tamanhoNavio = 3;

    // NÍVEL NOVATO

    limparTabuleiro(tabuleiro);

    int linhaH = 2, colunaH = 2;
    int linhaV = 5, colunaV = 6;

    for (int i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaH][colunaH + i] = 3;

    for (int i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaV + i][colunaV] = 3;

    printf("\nTABULEIRO BATALHA NAVAL - NOVATO\n");
    mostrarTabuleiro(tabuleiro);

    // NÍVEL AVENTUREIRO

    limparTabuleiro(tabuleiro);

    // Navio horizontal
    for (int i = 0; i < tamanhoNavio; i++)
        tabuleiro[2][3 + i] = 3;

    // Navio vertical
    for (int i = 0; i < tamanhoNavio; i++)
        tabuleiro[5 + i][6] = 3;

    // Diagonal principal
    for (int i = 0; i < tamanhoNavio; i++)
        tabuleiro[i + 1][i + 1] = 3;

    // Diagonal secundária
    for (int i = 0; i < tamanhoNavio; i++)
        tabuleiro[i + 1][8 - i] = 3;

    printf("\nTABULEIRO BATALHA NAVAL - AVENTUREIRO\n");
    mostrarTabuleiro(tabuleiro);

    // NÍVEL MESTRE

    limparTabuleiro(tabuleiro);

    // Cruz - 3
    // Vertical
    for (int i = 0; i <= 4; i++)
        tabuleiro[i][3] = 3;

    // Horizontal
    for (int j = 1; j <= 5; j++)
        tabuleiro[2][j] = 3;

    // Cone - 1
    int origemConeL = 5, origemConeC = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {

            int l = origemConeL + i;
            int c = origemConeC + j;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM)
                tabuleiro[l][c] = 1;
        }
    }

    // Octaedro - 2
    int origemOctL = 5, origemOctC = 7;

    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {

            int absI = i < 0 ? -i : i;
            int absJ = j < 0 ? -j : j;

            if (absI + absJ <= 2) {

                int l = origemOctL + i;
                int c = origemOctC + j;

                if (l >= 0 && l < TAM && c >= 0 && c < TAM)
                    tabuleiro[l][c] = 2;
            }
        }
    }

    printf("\nTABULEIRO BATALHA NAVAL - MESTRE\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}