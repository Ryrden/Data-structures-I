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

void add_number_to_list(char *int_to_str, LIST *big_number, int *partitions_num);

int main() {

    LIST *big_number_one;
    LIST *big_number_two;
    int n;
    scanf("%d", &n);
    char command[6];
    int first_integer;
    int second_integer;

    big_number_one = create_list();
    big_number_two = create_list();

    int carry = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        scanf("%d", &first_integer);
        scanf("%d", &second_integer);

        if (select_command(command) == soma) {
            char int_to_str[15];
            int partitions_num1 = 0;
            int partitions_num2 = 0;
            //converte inteiro para string
            snprintf(int_to_str, sizeof(int_to_str), "%d", first_integer);
            int_to_str[strlen(int_to_str)] = '\0';

            add_number_to_list(int_to_str, big_number_one, &partitions_num1);

            snprintf(int_to_str, sizeof(int_to_str), "%d", second_integer);
            int_to_str[strlen(int_to_str)] = '\0';

            add_number_to_list(int_to_str, big_number_two, &partitions_num2);

            char sum[100][5] = {};
            for (int j = partitions_num1; j > 0; j--) {
                print_number_part(sequential_search(big_number_one, j));
                print_number_part(sequential_search(big_number_two, j));
                char temp_sum[5];
                strcpy(temp_sum, sum_two_parts(sequential_search(big_number_one, j), sequential_search(big_number_two, j), &carry));
                if (j != 1) {
                    strcpy(sum[j - 1], temp_sum);
                } else {
                    char *index = temp_sum;
                    while (*index++ == '0')
                    strcpy(sum[j - 1], index);
                }   
            }
            printf("\n\n Soma: ");
            for (int k = 0; k < partitions_num1; k++) 
                printf("%s", sum[k]);
            

        } else if (select_command(command) == maior) {

        } else if (select_command(command) == menor) {

        } else if (select_command(command) == igual) {

        } else {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void add_number_to_list(char *int_to_str, LIST *big_number, int *partitions_num) {
    BIG_NUMBER *number_part;

    //ponteiro para comparação
    char *str = int_to_str;
    int key = 0;
    //divide o big number em partes
    int cont = 0;
    int max = strlen(int_to_str) / 4;
    int mod = strlen(int_to_str) % 4;
    if (mod > 0) {
        char answer[mod + 1];
        strncpy(answer, str, mod);
        answer[mod] = '\0';
        key++;

        //Adiciona na lista
        number_part = create_number_part(answer, key, mod);
        list_insert(big_number, number_part);
        str += mod;
    }
    while (cont < max) {
        char answer[5];
        strncpy(answer, str, 4);
        answer[4] = '\0';
        key++;

        //Adiciona na lista
        number_part = create_number_part(answer, key, 4);
        list_insert(big_number, number_part);
        str += 4;
        cont++;
    }
    *partitions_num = key;
}