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

    int n;
    scanf("%d", &n);
    char command[6];
    char first_integer[300];
    char second_integer[300];
    int len_digit_part;
    int carry = 0;

    for (int i = 0; i < n; i++) {
        LIST *big_number_one = create_list();
        LIST *big_number_two = create_list();

        scanf("%s", command);
        scanf("%s", first_integer);
        scanf("%s", second_integer);
        int partitions_int1 = 0;
        int partitions_int2 = 0;

        if (select_command(command) == soma) {
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

            len_digit_part = partitions_int1 = partitions_int2;

            char sum[100][5] = {};
            for (int j = len_digit_part; j > 0; j--) {
                //print_number_part(sequential_search(big_number_one, j));
                //print_number_part(sequential_search(big_number_two, j));
                char *temp_sum = sum_two_parts(sequential_search(big_number_one, j), sequential_search(big_number_two, j), &carry);
                if (j != 1) {
                    strcpy(sum[j - 1], temp_sum);
                } else {
                    char *index = temp_sum;
                    while (*index++ == '0')
                        strcpy(sum[j - 1], index);
                }
                free(temp_sum);
            }
            printf("Resultado :: ");
            for (int k = 0; k < len_digit_part; k++)
                printf("%s", sum[k]);
            printf("\n");

        } else if (select_command(command) == maior) {
            boolean is_bigger = FALSE;
            char *str1 = first_integer;
            char *str2 = second_integer;
            while (*str1 == '0') {
                str1++;
                strcpy(first_integer, str1);
                str1 = first_integer;
            }
            while (*str2 == '0') {
                str2++;
                strcpy(second_integer, str2);
                str2 = second_integer;
            }

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            if (partitions_int1 > partitions_int2 || (*str1 != '-' && *str2 == '-')) {
                is_bigger = TRUE;
            } else if (partitions_int1 == partitions_int2) {
                int part_index = 1;
                BIG_NUMBER *num1_part = sequential_search(big_number_one, part_index);
                BIG_NUMBER *num2_part = sequential_search(big_number_two, part_index);
                while (is_equal_part(num1_part, num2_part)) {
                    part_index++;
                    num1_part = sequential_search(big_number_one, part_index);
                    num2_part = sequential_search(big_number_two, part_index);
                }

                if (is_bigger_part(num1_part, num2_part))
                    is_bigger = TRUE;
            }

            if (is_bigger)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        } else if (select_command(command) == menor) {
            boolean is_smaller = FALSE;
            char *str1 = first_integer;
            char *str2 = second_integer;
            while (*str1 == '0') {
                str1++;
                strcpy(first_integer, str1);
                str1 = first_integer;
            }
            while (*str2 == '0') {
                str2++;
                strcpy(second_integer, str2);
                str2 = second_integer;
            }

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            if (partitions_int1 < partitions_int2 || (*str1 == '-' && *str2 != '-')) {
                is_smaller = TRUE;
            } else if (partitions_int1 == partitions_int2) {
                int part_index = 1;
                BIG_NUMBER *num1_part = sequential_search(big_number_one, part_index);
                BIG_NUMBER *num2_part = sequential_search(big_number_two, part_index);
                while (is_equal_part(num1_part, num2_part)) {
                    part_index++;
                    num1_part = sequential_search(big_number_one, part_index);
                    num2_part = sequential_search(big_number_two, part_index);
                }

                if (is_smaller_part(num1_part, num2_part))
                    is_smaller = TRUE;
            }

            if (is_smaller)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        } else if (select_command(command) == igual) {
            boolean is_equal = TRUE;

            char *str1 = first_integer;
            char *str2 = second_integer;
            while (*str1 == '0') {
                str1++;
                strcpy(first_integer, str1);
                str1 = first_integer;
            }
            while (*str2 == '0') {
                str2++;
                strcpy(second_integer, str2);
                str2 = second_integer;
            }

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            if (partitions_int1 == partitions_int2) {
                len_digit_part = partitions_int1 = partitions_int2;
                for (int i = 1; i <= len_digit_part; i++) {
                    if (!is_equal_part(sequential_search(big_number_one, i), sequential_search(big_number_two, i))) {
                        is_equal = FALSE;
                        break;
                    }
                }
            } else if (partitions_int1 != partitions_int2) {
                is_equal = FALSE;
            }

            if (is_equal)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        } else {
            return EXIT_FAILURE;
        }
        list_erase(&big_number_one);
        list_erase(&big_number_two);
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
        key++;
        if (mod == 1 && int_to_str[mod - 1] == '-') {
            char answer[6];
            strncpy(answer, str, 5);
            answer[5] = '\0';
            number_part = create_number_part(answer, key, 5);
            max--;
            mod = 5;
        } else {
            char answer[mod + 1];
            strncpy(answer, str, mod);
            answer[mod] = '\0';
            number_part = create_number_part(answer, key, mod);
        }

        //Adiciona na lista
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