#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct big_numbers_st {
    
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