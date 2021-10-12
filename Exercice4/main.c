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
void add_zeros_to_sum(char *first_integer, char *second_integer);
void remove_zeros(char *first_integer, char *second_integer);
char **sum_big_number(LIST *big_number_one, LIST *big_number_two, int *partition_len);
static char **create_sum();
static void free_sum(char **sum);
void print_sum(char **sum, int partition_len);
int find_different_MSD(LIST *big_number_one, LIST *big_number_two);

int main() {

    int n;
    scanf("%d", &n);
    char command[6];
    char first_integer[300];
    char second_integer[300];
    int partition_len;

    for (int i = 0; i < n; i++) {
        LIST *big_number_one = create_list();
        LIST *big_number_two = create_list();

        scanf("%s", command);
        scanf("%s", first_integer);
        scanf("%s", second_integer);
        int partitions_int1 = 0;
        int partitions_int2 = 0;

        if (select_command(command) == soma) {

            add_zeros_to_sum(first_integer, second_integer);

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            partition_len = partitions_int1 = partitions_int2;

            char **sum;
            sum = sum_big_number(big_number_one, big_number_two, &partition_len);

            print_sum(sum, partition_len);
            free_sum(sum);
        } else if (select_command(command) == maior) {

            remove_zeros(first_integer, second_integer);

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            boolean is_bigger = FALSE;
            if (partitions_int1 > partitions_int2 || (first_integer[0] != '-' && second_integer[0] == '-')) {
                is_bigger = TRUE;
            } else if (partitions_int1 == partitions_int2) {
                int part_index = find_different_MSD(big_number_one, big_number_two);
                BIG_NUMBER *num1_part = sequential_search(big_number_one, part_index);
                BIG_NUMBER *num2_part = sequential_search(big_number_two, part_index);

                if (is_bigger_part(num1_part, num2_part))
                    is_bigger = TRUE;
            }

            if (is_bigger)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        } else if (select_command(command) == menor) {

            remove_zeros(first_integer, second_integer);

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            boolean is_smaller = FALSE;
            if (partitions_int1 < partitions_int2 || (first_integer[0] == '-' && second_integer[0] != '-')) {
                is_smaller = TRUE;
            } else if (partitions_int1 == partitions_int2) {
                int part_index = find_different_MSD(big_number_one, big_number_two);
                BIG_NUMBER *num1_part = sequential_search(big_number_one, part_index);
                BIG_NUMBER *num2_part = sequential_search(big_number_two, part_index);

                if (is_smaller_part(num1_part, num2_part))
                    is_smaller = TRUE;
            }

            if (is_smaller)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        } else if (select_command(command) == igual) {

            remove_zeros(first_integer, second_integer);

            add_number_to_list(first_integer, big_number_one, &partitions_int1);
            add_number_to_list(second_integer, big_number_two, &partitions_int2);

            partition_len = partitions_int1 = partitions_int2;

            boolean is_equal = TRUE;
            if (partitions_int1 == partitions_int2) {
                for (int i = 1; i <= partition_len; i++) {
                    BIG_NUMBER *num1_part = sequential_search(big_number_one, i);
                    BIG_NUMBER *num2_part = sequential_search(big_number_two, i);
                    if (!is_equal_part(num1_part, num2_part)) {
                        is_equal = FALSE;
                        break;
                    }
                }
            } else {
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
            char answer[NumberPart + 2];
            strncpy(answer, str, NumberPart + 1);
            answer[NumberPart + 1] = '\0';
            number_part = create_number_part(answer, key, NumberPart + 1);
            max--;
            mod = NumberPart + 1;
        } else {
            char answer[mod + 1];
            strncpy(answer, str, mod);
            answer[mod] = '\0';
            number_part = create_number_part(answer, key, mod);
        }

        list_insert(big_number, number_part);
        str += mod;
    }
    while (cont < max) {
        char answer[NumberPart + 1];
        strncpy(answer, str, NumberPart);
        answer[NumberPart] = '\0';
        key++;

        number_part = create_number_part(answer, key, NumberPart);
        list_insert(big_number, number_part);
        str += NumberPart;
        cont++;
    }
    *partitions_num = key;
}

void add_zeros_to_sum(char *first_integer, char *second_integer) {
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
}

void remove_zeros(char *first_integer, char *second_integer) {
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
}

char **sum_big_number(LIST *big_number_one, LIST *big_number_two, int *partition_len) {
    char **sum = create_sum();
    int carry = 0;
    for (int j = *partition_len; j > 0; j--) {
        BIG_NUMBER *num1_part = sequential_search(big_number_one, j);
        BIG_NUMBER *num2_part = sequential_search(big_number_two, j);
        char *temp_sum = sum_two_parts(num1_part, num2_part, &carry);

        strcpy(sum[j - 1], temp_sum);
        if (j == 1) {
            char *index = temp_sum;
            while (*index++ == '0')
                strcpy(sum[0], index);
            if (carry == 1) {
                int move_right = *partition_len;
                while (move_right > 1) {
                    strcpy(sum[move_right], sum[move_right - 1]);
                    move_right--;
                }
                strcpy(sum[1], temp_sum);
                strcpy(sum[0], "1");
                (*partition_len)++;
            }
        }
        free(temp_sum);
    }
    return sum;
}

static char **create_sum() {
    char **sum = (char **)malloc(sizeof(char *) * 100);

    if (sum == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < 100; i++) {
        sum[i] = (char *)malloc(sizeof(char) * (NumberPart + 1));
        if (sum[i] == NULL)
            exit(EXIT_FAILURE);
    }
    return sum;
}

static void free_sum(char **sum) {
    for (int i = 0; i < 100; i++)
        free(sum[i]);
    free(sum);
}

void print_sum(char **sum, int partition_len) {
    printf("Resultado :: ");
    for (int i = 0; i < partition_len; i++)
        printf("%s", sum[i]);
    printf("\n");
}

int find_different_MSD(LIST *big_number_one, LIST *big_number_two) {
    int part_index = 1;
    BIG_NUMBER *num1_part = sequential_search(big_number_one, part_index);
    BIG_NUMBER *num2_part = sequential_search(big_number_two, part_index);
    while (is_equal_part(num1_part, num2_part)) {
        part_index += 1;
        num1_part = sequential_search(big_number_one, part_index);
        num2_part = sequential_search(big_number_two, part_index);
    }
    return part_index;
}
