#ifndef JOGO_H
#define JOGO_H

typedef struct game_st GAME;

GAME *register_game(char *name, char *producer, int year, int key);

int get_key(const GAME *game);

#endif // JOGO_H