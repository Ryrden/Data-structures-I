#ifndef CARTAS_H
#define CARTAS_H

#include "util.h"

#define ERRO (-32000)

typedef struct card_st CARD;

CARD *create_card(const char *nipe, const char *symbol);
boolean card_erase(CARD **card);
int value_last_card(const CARD *card) ;

#endif //CARTAS_H