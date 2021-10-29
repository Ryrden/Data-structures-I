#ifndef JOGO_H
#define JOGO_H
#include "../Util/util.h"

typedef struct game_st GAME;

GAME *register_game(char *name, char *producer, int year, int key);

int get_key(const GAME *game);

GAME *create_empty_item();

GAME *create_game();

boolean swap_games(GAME *game1, GAME *game2);

boolean compare_games(GAME *game1, GAME *game2);

boolean copy_games(GAME *game1, GAME *game2);

char *search_producer(GAME *game, char *game_producer);

char *search_year(GAME *game, int game_year);

void print_game_name(GAME *game);

int set_key(GAME *item, int key);

void decrease_key_value(GAME *game);

#endif // JOGO_H