#include "catalogo.h"
#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*INFORMAÇÕES:
    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Estrutura de Dados I
    Professor: Leonardo Tórtoro Pereira
*/
int main() {
    int size = 1000;        //Tamanho do catalogo, variável de acordo com a entrada
    int size_search = 1000; //tamanho do vetor de buscas, variável de acordo com a entrada.

    //Digitar os games até encontrar o F
    GAME *game_catalog;
    game_catalog = create_catalog(size);
    int number_of_register = 0;
    int index = 0;
    while (register_games(game_catalog, index)) {
        number_of_register++;
        index++;
        //Aumenta 15% do limite estabelecido
        if (number_of_register >= size) 
            game_catalog = realloc_catalog(game_catalog, &size);
    }

    //Digitas as pesquisas até que seja digitado F
    char **found_games;
    found_games = create_found_games_catalog(size_search);
    char letter[2];
    int number_of_searches = 0;
    while (1) {
        scanf(" %[^(\r|\n)]*c", letter);
        getchar();

        if (!(strcmp(letter, "F"))) {
            break;
        } else if (!(strcmp(letter, "A"))) {
            int game_year;
            scanf("%d", &game_year);
            found_game_year(game_catalog, found_games, game_year, number_of_register, &number_of_searches);
        } else if (!(strcmp(letter, "E"))) {
            char game_producer[256];
            scanf(" %[^(\r|\n)]*c", game_producer);
            getchar();
            found_game_producer(game_catalog, found_games, game_producer, number_of_register, &number_of_searches);
        }
        //Caso o numbero de buscas feitas encontradas estiver muito perto, aumenta 35% o limite
        if (number_of_searches >= size_search - 100)
            found_games = realloc_found_games_catalog(found_games, &size_search);
    }

    //Imprimir resultado das pesquisas
    print_found_games(found_games, number_of_searches);

    //Liberar todos os vetores alocados/realocados...
    free_found_games_catalog(found_games, size_search);
    free(game_catalog);
    return EXIT_SUCCESS;
}