#include "cartas.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct quantas_cartas_st {
    char *nipes[4] = {"Espadas", "Paus", "Ouros", "Copas"};
    char *simbolos[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "V", "D", "R"};
    int quantidade = 0;
};*/

struct card_st {
    int key;
    char nipe[8];
    char symbol[3];
};

CARD *create_card(const char *nipe, const char *symbol) {
    CARD *card;

    card = (CARD *)malloc(sizeof(CARD));

    if (card == NULL)
        exit(EXIT_FAILURE);

    strcpy(card->nipe, nipe);
    strcpy(card->symbol, symbol);

    return card;
}

int value_last_card(CARD *card) {
    int value = 0;

    if (!strcmp(card->symbol, "V"))
        value = 10;
    else if (!strcmp(card->symbol, "D"))
        value = 10;
    else if (!strcmp(card->symbol, "R"))
        value = 10;
    else
        value = atoi(card->symbol);

    if (value >= 1 && value <= 10)
        return value;
    return ERRO;
}

boolean card_erase(CARD **card) {
    if (*card == NULL)
        return FALSE;

    (*card)->key = ERRO; //Chave assume valor impossivel -> Apagar simbolicamente
    free(*card);
    *card = NULL;
    return TRUE;
}