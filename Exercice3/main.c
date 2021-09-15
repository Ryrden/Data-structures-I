#include "cartas.h"
#include "stack.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*INFORMAÇÕES:
    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Estrutura de Dados I
    Professor: Leonardo Tórtoro Pereira
*/

struct card_st {
    int key;
    char nipe[8];
    char symbol[3];
};

int main() {

    STACK *stack;
    stack = create_stack();
    int key = 1;
    while (key <= 52) {
        char nipe[10];
        char symbol[5];
        //scanf("%[^(\r|\n)]*c", nipe);
        scanf("%s", nipe);
        getchar();
        //scanf("%[^(\r|\n)]*c", symbol);
        scanf("%s", symbol);
        getchar();
        

        CARD *card;
        card = create_card(key, nipe, symbol);
        stack_stackup(stack, card);
        key++;
    }

    int sum = 0;
    int hand = 3;

    while (key > 0) {
        CARD *card;
        card = stack_top(stack);

        sum = sum_last_card(card);
        hand--;

        card = stack_unstack(stack);
        if (sum == 21) {
            printf("Ganhou ;)");
            break;
        } else if (sum > 21) {
            printf("Perdeu :(\n");
            printf("Soma :: %d", sum);
        }
    }

    return EXIT_SUCCESS;
}
