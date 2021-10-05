#ifndef NUMBERS_H
#define NUMBERS_H
#include <stdio.h>

typedef struct big_numbers_st BIG_NUMBER;

typedef enum {
    soma = 1,
    maior,
    menor,
    igual,
    ERRO = -1
} operation;

operation select_command(char *command);

BIG_NUMBER *create_number_part(char *number_part, int tam);

#endif //NUMBERS_H