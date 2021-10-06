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

BIG_NUMBER *create_number_part(char *number_part, int key, int tam);

char *sum_two_parts(const BIG_NUMBER *part1, const BIG_NUMBER *part2, int *carry);
void print_number_part(const BIG_NUMBER *part);
int get_key(const BIG_NUMBER *part);
void print_number(const BIG_NUMBER *part);

#endif //NUMBERS_H