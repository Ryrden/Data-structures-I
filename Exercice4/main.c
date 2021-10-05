#include "list.h"
#include "numbers.h"
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

void add_number_to_list(char *int_to_str, LIST *big_number);

int main() {

    LIST *big_number;
    int n;
    scanf("%d", &n);
    char command[6];
    int first_integer;
    int second_integer;

    big_number = create_list();

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        scanf("%d", &first_integer);
        scanf("%d", &second_integer);

        if (select_command(command) == soma) {
            char int_to_str[15];
            //converte inteiro para string
            snprintf(int_to_str, sizeof(int_to_str), "%d", first_integer);
            int_to_str[strlen(int_to_str)] = '\0';

            add_number_to_list(int_to_str, big_number);

            snprintf(int_to_str, sizeof(int_to_str), "%d", second_integer);
            int_to_str[strlen(int_to_str)] = '\0';

            add_number_to_list(int_to_str, big_number);


        } else if (select_command(command) == maior) {

        } else if (select_command(command) == menor) {

        } else if (select_command(command) == igual) {

        } else {
            return EXIT_FAILURE;
        }
    }

    for (int i = n; i > 0; i--) {
        /* code */
    }

    return EXIT_SUCCESS;
}

void add_number_to_list(char *int_to_str, LIST *big_number) {
    BIG_NUMBER *number_part;

    //ponteiro para comparação
    char *str = int_to_str;
    int cont = 0;
    //divide o big number em partes
    int max = strlen(int_to_str) / 4;
    int mod = strlen(int_to_str) % 4;
    if (mod > 0) {
        char answer[mod];
        strncat(answer, str, mod);

        //Adiciona na lista
        number_part = create_number_part(answer, mod);
        list_insert(big_number, answer);
        str += mod;
    }
    while (cont <= max) {
        char answer[4];
        strncat(answer, str, 4);

        //Adiciona na lista
        number_part = create_number_part(answer, 4);
        list_insert(big_number, answer);
        str += 4;
        cont++;
    }
}