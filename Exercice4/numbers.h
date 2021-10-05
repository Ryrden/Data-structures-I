#ifndef NUMBERS_H
#define NUMBERS_H
#include <stdio.h>

typedef struct big_numbers_st BIG_NUMBER;

typedef enum {
    soma = 1,
    maior,
    menor,
    igual,
    ERRO = NULL
} operation;

operation select_command(char *command);

#endif //NUMBERS_H