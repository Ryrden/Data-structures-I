#include "Game/game.h"
#include "Tree/Tree.h"
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
typedef enum {
    PRE_ORDEM = 1,
    EM_ORDEM,
    POS_ORDEM
} tree_command;

//2019,2004,2012,2014,2016,2007,2015,2020,2010,2000,2013,2017,2021,2008

int main() {
    AVL_TREE *tree;
    FILE *arq1;

    arq1 = fopen("CSV-SemRep.csv", "r");
    if (arq1 == NULL) {
        perror("Error to open Archive");
        exit(EXIT_FAILURE);
    }

    tree = create_tree();

    int command;
    scanf("%d", &command);

    char line[200];
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
        GAME *game = create_game();
        int key = game_year;
        register_game(game, game_name, game_producer, game_year, key);

        // Registrar na lista catalogo
        insert_tree(tree, game);
    }
    int year;

    while (scanf("%d", &year)) {
        remove_tree(tree, year);
    }

    if (command == PRE_ORDEM)
        pre_order_tree(tree);
    else if (command == EM_ORDEM)
        in_order_tree(tree);
    else if (command == POS_ORDEM)
        pos_order_tree(tree);

    fclose(arq1);
    return erase_tree(&tree)
               ? EXIT_SUCCESS
               : EXIT_FAILURE;
}