#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct big_numbers_st {
    char number_part[5];
};

operation select_command(char *command){

    if (!strcmp(command, "soma"))
        return soma;
    else if (!strcmp(command, "maior"))
        return maior;
    else if (!strcmp(command, "menor"))
        return menor;
    else if (!strcmp(command, "igual"))
        return igual;
    
    return ERRO;
}

BIG_NUMBER *create_number_part(char *number_part, int tam){
    BIG_NUMBER *number;

    number = (BIG_NUMBER *)malloc(sizeof(BIG_NUMBER)*tam);

    if (number_part == NULL)
        exit(EXIT_FAILURE);

    strcpy(number->number_part, number_part);

    return number;
}