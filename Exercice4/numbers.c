#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct big_numbers_st {
    int key;
    char number_part[5];
};

operation select_command(char *command) {

    if (!strcmp(command, "soma"))
        return soma;
    else if (!strcmp(command, "maior"))
        return maior;
    else if (!strcmp(command, "menor"))
        return menor;
    else if (!strcmp(command, "igual"))
        return igual;

    return ERRO;
}

BIG_NUMBER *create_number_part(char *number_part, int key, int tam) {
    BIG_NUMBER *number;

    number = (BIG_NUMBER *)malloc(sizeof(BIG_NUMBER) * tam);

    if (number_part == NULL)
        exit(EXIT_FAILURE);

    number->key = key;
    strcpy(number->number_part, number_part);

    return number;
}

int get_key(const BIG_NUMBER *part) {
    if (part != NULL)
        return part->key;

    return ERRO;
}

void print_number_part(const BIG_NUMBER *part) {
    if (part != NULL) {
        printf("\n ->chave: %d", part->key);
        printf("\n ->part: %s", part->number_part);
    }
}

char *sum_two_parts(const BIG_NUMBER *num1_part, const BIG_NUMBER *num2_part, int *carry) {
    char sum[5];
    char *sum_answer = (char *)malloc(sizeof(char) * 5);
    int num1 = atoi(num1_part->number_part);
    int num2 = atoi(num2_part->number_part);

    int part_sum = num1 + num2;

    if (*carry == 1)
        part_sum++;

    if (part_sum > 9999) {
        char temp[6];
        *carry = 1;
        snprintf(temp, sizeof(temp), "%d", part_sum);
        char *mv_one_digit = temp;
        mv_one_digit++;
        strcpy(sum, mv_one_digit);
    } else if (part_sum < 10) {
        *carry = 0;
        char temp[2];
        strcpy(sum, "000");
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcat(sum, temp);
    } else if (part_sum < 100) {
        *carry = 0;
        char temp[3];
        strcpy(sum, "00");
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcat(sum, temp);
    } else if (part_sum < 1000) {
        *carry = 0;
        char temp[4];
        strcpy(sum, "0");
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcat(sum, temp);
    } else if (part_sum > 1000) {
        *carry = 0;
        char temp[5];
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcpy(sum, temp);
    }
    strcpy(sum_answer, sum);

    return sum_answer;
}

int is_bigger_part(BIG_NUMBER *big_number_one, BIG_NUMBER *big_number_two) {

    int num1 = atoi(big_number_one->number_part);
    int num2 = atoi(big_number_two->number_part);

    return num1 > num2;
}

int is_smaller(char *first_integer, char *second_integer) {
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

    if (first_integer[0] != '-' && second_integer[0] != '-') {
        if (strlen(first_integer) < strlen(second_integer)) {
            is_smaller = TRUE;
        } else if (strlen(first_integer) == strlen(second_integer)) {
            int len = strlen(first_integer);
            int index = 0;
            while (len > 0) {
                if (first_integer[index] < second_integer[index]) {
                    is_smaller = TRUE;
                    break;
                }
                len--;
                index++;
            }
        }
    } else {
        if (first_integer[0] == '-' && second_integer[0] != '-') {
            is_smaller = TRUE;
        } else if (first_integer[0] == '-' && second_integer[0] == '-') {
            str1++;
            str2++;
            if (strlen(str1) > strlen(str2)) {
                is_smaller = TRUE;
            } else if (strlen(str1) == strlen(str2)) {
                int len = strlen(str1);
                int index = 0;
                while (len > 0) {
                    if (str1[index] > str2[index]) {
                        is_smaller = TRUE;
                        break;
                    }
                    len--;
                    index++;
                }
            }
        }
    }

    return is_smaller;
}