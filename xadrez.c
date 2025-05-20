#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
   #include <stdio.h>

   int i, casas;
    
    // Movimento da Torre (for): 4 casas para cima
    printf("Movimento da Torre (for):\n");
    casas = 4;
    for (i = 1; i <= casas; i++) {
        printf("Torre move para cima: casa %d\n", i);
    }
    printf("\n");
    
    // Movimento do Bispo (while): 3 casas na diagonal cima-direita
    printf("Movimento do Bispo (while):\n");
    casas = 3;
    i = 1;
    while (i <= casas) {
        printf("Bispo move diagonal para cima-direita: casa %d\n", i);
        i++;
    }
    printf("\n");
    
    // Movimento da Rainha (do-while): 5 casas na diagonal baixo-esquerda
    printf("Movimento da Rainha (do-while):\n");
    casas = 5;
    i = 1;
    do {
        printf("Rainha move diagonal para baixo-esquerda: casa %d\n", i);
        i++;
    } while (i <= casas);

    return 0;
}
