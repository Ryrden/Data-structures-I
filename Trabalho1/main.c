#include "catalog.h"
#include "game.h"
#include "list.h"
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
    LIST *catalog;
    FILE *arq1;

    arq1 = fopen("CSV.csv", "r");
    if (arq1 == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    catalog = create_list();

    char line[200];
    int key = 1;
    while (fgets(line, sizeof(line), arq1)) {

        while (1) {
            GAME *game;
            char *game_name = strtok(line, ";");
            // TRATAR ENTRADA - caracteres: ´╗┐
            while (*game_name < 'A')
                game_name++;
            
            int game_year = atoi(strtok(NULL, ";"));

            char *game_producer = strtok(NULL, ";");

            // Registrar na estrutura game
            game = register_game(game_name, game_producer, game_year, key);

            // Registrar na lista catalogo
            list_insert(catalog, game);

            printf("\n%s %d %s", game_name, game_year, game_producer);
            key++;
            break;
        }
    }

    while (1) {
        char command[2];
        scanf(" %[^(\r|\n)]*c", command);
        getchar();

        if (select_command(command) == produtora) {
            // ler produtora
            char producer[256];
            scanf(" %[^(\r|\n)]*c", producer);
            getchar();
            // criar vetor de games

            // buscar games da produtora

            // imprimir games da produtora
        } else if (select_command(command) == ano) {
            // ler ano
            int year;
            scanf("%d", &year);

            // buscar games deste ano

            // imprimir games do ano
        } else if (select_command(command) == imprime) {
            // imprimir todos os jogos
        } else if (select_command(command) == posicao) {
            // ler posição

            // buscar o jogo que está salvo na posição X

            // imprimir jogo da posiçaõ

        } else if (select_command(command) == mover_direita) {
            // ler posição

            // ler quantas casas mover

            // buscar posição no catalogo

            // executar movimentação
        } else if (select_command(command) == mover_esquerda) {
            // ler posição

            // ler quantas casas mover

            // buscar posição no catalogo

            // executar movimentação
        } else if (select_command(command) == encerrar) {
            // liberar espaço
            // break
        }
    }

    return EXIT_SUCCESS;
}
