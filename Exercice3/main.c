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

int main() {

    STACK *card_pack;
    CARD *card;
    card_pack = create_stack();

    char nipe[10];
    char symbol[5];
    while (stack_size(card_pack) != 52) {
        scanf("%s", nipe);
        getchar(); 
        scanf("%s", symbol);
        getchar();

        card = create_card(nipe, symbol);
        stack_stackup(card_pack, card);
    }

    int sum = 0;
    int card_value = 0;

    while (!stack_empty(card_pack)) {
        card = stack_unstack(card_pack);
        card_value = value_last_card(card);
        card_erase(&card);
        sum += card_value;

        if (sum == 21) {
            printf("Ganhou ;)\n");
            break;
        } else if (sum > 21) {
            printf("Perdeu :(\n");
            printf("Soma :: %d\n", sum);
            break;
        }
    }

    stack_erase(&card_pack);

    return EXIT_SUCCESS;
}
