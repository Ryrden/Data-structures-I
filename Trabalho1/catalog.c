#include "catalog.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

operation select_command(char *command) {

    if (!strcmp(command, "p"))
        return produtora;
    else if (!strcmp(command, "a"))
        return ano;
    else if (!strcmp(command, "i"))
        return imprime;
    else if (!strcmp(command, "u"))
        return posicao;
    else if (!strcmp(command, "mr"))
        return mover_direita;
    else if (!strcmp(command, "ml"))
        return mover_esquerda;

    return encerrar;
}