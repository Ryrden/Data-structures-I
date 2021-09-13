#ifndef JOGO_H
#define JOGO_H

typedef struct game_st GAME;

int register_games(GAME *game, int i);

void found_game_year(const GAME *game, char **found_games, int game_year, int number_of_register, int *search_index);

void found_game_producer(const GAME *game, char **found_games, char *game_producer, int number_of_register, int *search_index);

#endif //JOGO_H