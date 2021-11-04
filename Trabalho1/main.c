#include "Catalogo/catalog.h"
#include "Game/game.h"
#include "Lista/list.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INEXISTENT_KEY (-32000)

/*INFORMAÇÕES:
    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Estrutura de Dados I
    Professor: Leonardo Tórtoro Pereira
*/

void producers_found(LIST *catalog, char **found_games, char *producer, int *search_number);
void years_found(LIST *catalog, char **found_games, int year, int *search_number);
void print_catalog(LIST *catalog);
void move_right(LIST *catalog, int index, int moves);
void move_left(LIST *catalog, int index, int moves);
void found_duplicates(LIST *catalog, int *duplicate_games);
void delete_repeated_games(LIST *catalog, int *duplicate_games, int registers);
void move_keys_to_right(LIST *catalog, int key_to_move);
void set_game_as_first(LIST *catalog, GAME *game);
void set_game_as_last(LIST *catalog, GAME *game);

int main() {
    LIST *catalog;
    FILE *arq1;

    arq1 = fopen("Testes/2.csv", "r");
    if (arq1 == NULL) {
        perror("Error to open Archive");
        exit(EXIT_FAILURE);
    }

    catalog = create_list();

    char line[200];
    int key = 0;
    while (fgets(line, sizeof(line), arq1)) {

        char *game_name = strtok(line, ";");
        // TRATAR ENTRADA - caracteres: ´╗┐
        while (*game_name < 'A')
            game_name++;

        int game_year = atoi(strtok(NULL, ";"));

        char *game_producer = strtok(NULL, ";");
        // TRATAR ENTRADA - remover /n do final (caso houver)
        if (game_producer[strlen(game_producer) - 1] == '\n')
            game_producer[strlen(game_producer) - 1] = '\0';

        // Registrar na estrutura game
        GAME *game;
        game = register_game(game_name, game_producer, game_year, key);
        key++;

        // Registrar na lista catalogo
        list_insert(catalog, game);
    }

    while (1) {
        char command[2];
        scanf("%s", command);

        int number_of_register = list_size(catalog);
        if (select_command(command) == remove_duplicados) {
            int *duplicate_games = create_duplicate_games(number_of_register);

            // busca duplicados e salva a chave deles no vetor
            found_duplicates(catalog, duplicate_games);

            // exclui todos games do catalogo enquanto o vetor tem chaves
            delete_repeated_games(catalog, duplicate_games, number_of_register);

            // limpa vetor
            free_duplicate_games(&duplicate_games);

        } else if (select_command(command) == produtora) {
            // ler produtora
            char producer[256];
            getchar();
            fgets(producer, 256, stdin);
            producer[strlen(producer) - 1] = '\0';

            // Criar vetor de buscas
            int size_search = list_size(catalog);
            char **found_games;
            found_games = create_found_games_catalog(size_search);

            // buscar games da produtora
            int search_number = 0;
            producers_found(catalog, found_games, producer, &search_number);

            // imprimir games da produtora
            print_found_games(found_games, search_number);

            // liberar vetor
            free_found_games_catalog(found_games, size_search);

        } else if (select_command(command) == ano) {
            // ler ano
            int year;
            scanf("%d", &year);

            // Criar vetor de buscas
            int size_search = list_size(catalog);
            char **found_games;
            found_games = create_found_games_catalog(size_search);

            // buscar games deste ano
            int search_number = 0;
            years_found(catalog, found_games, year, &search_number);

            // imprimir games da produtora
            print_found_games(found_games, search_number);

            // liberar vetor
            free_found_games_catalog(found_games, size_search);

        } else if (select_command(command) == imprime) {
            // imprimir todos os jogos
            print_catalog(catalog);
        } else if (select_command(command) == posicao) {
            // ler posição
            int position;
            scanf("%d", &position);

            // buscar o jogo que está salvo na posição X
            GAME *game = sequential_search(catalog, position);

            // imprimir jogo da posiçaõ
            print_game_name(game);

        } else if (select_command(command) == mover_direita) {
            // ler posição
            int index;
            scanf("%d", &index);
            // ler quantas casas mover
            int moves;
            scanf("%d", &moves);
            // buscar posição no catalogo

            // Mover game
            move_right(catalog, index, moves);

        } else if (select_command(command) == mover_esquerda) {
            // ler posição
            int index;
            scanf("%d", &index);
            // ler quantas casas mover
            int moves;
            scanf("%d", &moves);
            // buscar posição no catalogo

            // Mover game
            move_left(catalog, index, moves);

        } else if (select_command(command) == encerrar) {
            // liberar espaço
            list_erase(&catalog);
            fclose(arq1);
            // break
            break;
        }
    }
    return EXIT_SUCCESS;
}


void producers_found(LIST *catalog, char **found_games, char *producer, int *search_number) {
    int records = list_size(catalog);
    for (int i = 0; i < records; i++) {
        char *search = search_producer(sequential_search(catalog, i), producer);
        if (search != FALSE) {
            strncpy(found_games[*search_number], search, strlen(search));
            *search_number += 1;
        }
    }
}

void years_found(LIST *catalog, char **found_games, int year, int *search_number) {
    int records = list_size(catalog);
    for (int i = 0; i < records; i++) {
        char *search = search_year(sequential_search(catalog, i), year);
        if (search != FALSE) {
            strcpy(found_games[*search_number], search);
            *search_number += 1;
        }
    }
}

void print_catalog(LIST *catalog) {
    int records = list_size(catalog);
    for (int i = 0; i < records; i++) {
        print_game_name(sequential_search(catalog, i));
    }
}

void move_right(LIST *catalog, int index, int moves) {
    int registers = list_size(catalog) - 1;
    for (int i = 0; i < moves; i++) {
        GAME *game1 = sequential_search(catalog, index);
        GAME *game2 = next_item(catalog, index);
        if (index + 1 > registers) {
            index = 0;
            set_game_as_first(catalog, game1);
        }

        // executar movimentação
        if (swap_games(game1, game2)) {
            index++;
        } else {
            printf("Error to swap games");
            break;
        }
    }
}

void move_left(LIST *catalog, int index, int moves) {
    int registers = list_size(catalog);
    for (int i = 0; i < moves; i++) {
        GAME *game1 = sequential_search(catalog, index);
        GAME *game2 = previous_item(catalog, index);
        if (index - 1 < 0) {
            index = registers - 1;
            set_game_as_last(catalog, game1);
        }

        // executar movimentação
        if (swap_games(game1, game2)) {
            index--;
        } else {
            printf("Error to swap games");
            break;
        }
    }
}

void found_duplicates(LIST *catalog, int *duplicate_games) {
    int records = list_size(catalog);

    int index = 0;

    for (int i = 0; i < records; i++) {
        GAME *duplicate_game = sequential_search(catalog, i);
        for (int j = i + 1; j < records; j++) {
            GAME *possible_duplicate_game = sequential_search(catalog, j);

            if (compare_games(duplicate_game, possible_duplicate_game)) {
                int key = get_key(possible_duplicate_game);
                boolean can_add = TRUE;
                for (int k = 0; k < records; k++) {
                    if (duplicate_games[k] == key) {
                        can_add = FALSE;
                        break;
                    }
                }
                if (can_add) {
                    duplicate_games[index] = key;
                    index++;
                }
            }
        }
    }
}

void move_keys_to_right(LIST *catalog, int key_to_move) {
    int size_catalog = list_size(catalog);

    for (int i = key_to_move + 1; i <= size_catalog; i++) {
        GAME *game = sequential_search(catalog, i);
        set_key(game, i - 1);
    }
}

void set_game_as_first(LIST *catalog, GAME *game) {
    int catalog_size = list_size(catalog) - 1;

    for (int i = catalog_size - 1; i >= 0; i--) {
        GAME *game_to_move = sequential_search(catalog, i);
        set_key(game_to_move, i + 1);
    }
    list_insert_start(catalog, game);
    list_remove_item(catalog, catalog_size);
    set_key(game, 0);
}

void set_game_as_last(LIST *catalog, GAME *game) {
    int catalog_size = list_size(catalog);

    for (int i = 1; i < catalog_size; i++) {
        GAME *game_to_move = sequential_search(catalog, i);
        set_key(game_to_move, i - 1);
    }
    list_insert(catalog, game);
    list_remove_item(catalog, 0);
    set_key(game, catalog_size - 1);
}

void delete_repeated_games(LIST *catalog, int *duplicate_games, int registers) {
    int index = 0;
    while (duplicate_games[index] != INEXISTENT_KEY) {
        int key = duplicate_games[index];
        list_remove_item(catalog, key);
        move_keys_to_right(catalog, key);
        ajust_duplicate_key_games(duplicate_games, registers, key);
        index++;
    }
}