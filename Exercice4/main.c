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
    char first_integer[300];
    char second_integer[300];

    big_number_one = create_list();
    big_number_two = create_list();

    int carry = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        scanf("%s", first_integer);
        scanf("%s", second_integer);

        if (select_command(command) == soma) {
            int partitions_int1 = 0;
            int partitions_int2 = 0;
            //converte inteiro para string

            if (strlen(first_integer) != strlen(second_integer)) {
                if (strlen(first_integer) > strlen(second_integer)) {
                    int zeros_to_add = strlen(first_integer) - strlen(second_integer);
                    for (int j = 0; j < zeros_to_add; j++) {
                        second_integer[strlen(second_integer) + 1] = '\0';
                        for (int k = strlen(second_integer) - 1; k >= 0; k--) {
                            second_integer[k + 1] = second_integer[k];
                            if (k == 0)
                                second_integer[k] = '0';
                        }
                    }
                } else {
                    int zeros_to_add = strlen(second_integer) - strlen(first_integer);
                    for (int j = 0; j < zeros_to_add; j++) {
                        first_integer[strlen(first_integer) + 1] = '\0';
                        for (int k = strlen(first_integer) - 1; k >= 0; k--) {
                            first_integer[k + 1] = first_integer[k];
                            if (k == 0)
                                first_integer[k] = '0';
                        }
                    }
                }
            }

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            int len_digit_part= partitions_int1 = partitions_int2;

            char sum[100][5] = {};
            for (int j = len_digit_part; j > 0; j--) {
                //print_number_part(sequential_search(big_number_one, j));
                //print_number_part(sequential_search(big_number_two, j));
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
            for (int k = 0; k < len_digit_part; k++)
                printf("%s", sum[k]);

        } else if (select_command(command) == maior) {
            if (strlen(first_integer) < strlen(second_integer)) {
                printf("True");
            } else if (strlen(first_integer) > strlen(second_integer)) {
                printf("False");
            } else {
                int index = 0;
                while (index < strlen(first_integer)) {
                    if ((int)first_integer[index] < (int)second_integer[index]) {
                        printf("True");
                        break;
                    } else if ((int)first_integer[index] > (int)second_integer[index]) {
                        printf("False");
                        break;
                    }
                    index++;
                }
            }
        } else if (select_command(command) == menor) {
            if (strlen(first_integer) < strlen(second_integer)) {
                printf("True");
            } else if (strlen(first_integer) > strlen(second_integer)) {
                printf("False");
            } else {
                int index = 0;
                while (index < strlen(first_integer)) {
                    if ((int)first_integer[index] > (int)second_integer[index]) {
                        printf("True");
                        break;
                    } else if ((int)first_integer[index] < (int)second_integer[index]) {
                        printf("False");
                        break;
                    }
                    index++;
                }
            }
        } else if (select_command(command) == igual) {
            if (strlen(first_integer) != strlen(second_integer)){
                printf("False");
            }
            else{
                int index = 0;
                while (index < strlen(first_integer)) {
                    if ((int)first_integer[index] > (int)second_integer[index]) {
                        printf("True");
                        break;
                    } else if ((int)first_integer[index] < (int)second_integer[index]) {
                        printf("False");
                        break;
                    }
                    index++;
                }
            }
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