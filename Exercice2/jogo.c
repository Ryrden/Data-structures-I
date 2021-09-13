#include "jogo.h"
#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_st {
    char name[256];
    char producer[256];
    int year;
};

int register_games(GAME *game,int i) {
    scanf(" %[^(\r|\n)]*c", game[i].name);
    getchar();
    if (strcmp(game[i].name, "F") == 0) {
        return 0;
    }
    scanf(" %[^(\r|\n)]*c", game[i].producer);
    getchar();
    scanf("%d", &game[i].year);
    return 1;
}

void found_game_year(const GAME *game, char **found_games,int game_year, int number_of_register, int *search_index) {
    int not_found_year = 1;
    for (int i = 0; i < number_of_register; i++) {
        if (game[i].year == game_year) {
            strcpy(found_games[*search_index], game[i].name);
            not_found_year = 0;
            (*search_index)++;
        }
    }
    if (not_found_year) { //Se realmente não encontrou nada
        strcpy(found_games[*search_index], "Nada encontrado");
        (*search_index)++;
    }
}

void found_game_producer(const GAME *game, char **found_games,char *game_producer, int number_of_register, int *search_index){
    int not_found_producer = 1;
    for (int i = 0; i < number_of_register; i++) {
        if (!(strcmp(game[i].producer, game_producer))) {
            strcpy(found_games[*search_index], game[i].name);
            not_found_producer = 0;
            (*search_index)++;
        }
    }
    if (not_found_producer) { //Se realmente não encontrou nada
        strcpy(found_games[*search_index], "Nada encontrado");
        (*search_index)++;
    }
}