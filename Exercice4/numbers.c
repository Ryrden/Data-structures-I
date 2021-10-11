#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct big_numbers_st {
    int key;
    char number_part[6];
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

boolean is_bigger_part(BIG_NUMBER *big_number_one, BIG_NUMBER *big_number_two) {
    char *ptr_num1 = big_number_one->number_part;
    char *ptr_num2 = big_number_two->number_part;

    while (*ptr_num1 == *ptr_num2) {
        ptr_num1++;
        ptr_num2++;
    }
    int num1 = ptr_num1[0] - '0';
    int num2 = ptr_num2[0] - '0';

    if (big_number_one->number_part[0] != '-' && big_number_two->number_part[0] == '-')
        return TRUE;
    else if (big_number_one->number_part[0] == '-' && big_number_two->number_part[0] != '-')
        return FALSE;
    else if (strlen(big_number_one->number_part) > strlen(big_number_two->number_part))
        return TRUE;
    else if (strlen(big_number_one->number_part) < strlen(big_number_two->number_part))
        return FALSE;

    return num1 > num2;
}

boolean is_smaller_part(BIG_NUMBER *big_number_one, BIG_NUMBER *big_number_two) {
    char *ptr_num1 = big_number_one->number_part;
    char *ptr_num2 = big_number_two->number_part;

    while (*ptr_num1 == *ptr_num2) {
        ptr_num1++;
        ptr_num2++;
        if (!(*ptr_num1) && !(*ptr_num2)){
            return FALSE;
        }
    }
    int num1 = ptr_num1[0] - '0';
    int num2 = ptr_num2[0] - '0';

    if (big_number_one->number_part[0] == '-' && big_number_two->number_part[0] != '-')
        return TRUE;
    else if (big_number_one->number_part[0] != '-' && big_number_two->number_part[0] == '-')
        return FALSE;
    else if (strlen(big_number_one->number_part) < strlen(big_number_two->number_part))
        return TRUE;
    else if (strlen(big_number_one->number_part) > strlen(big_number_two->number_part))
        return FALSE;

    return num1 < num2;
}

boolean is_equal_part(BIG_NUMBER *big_number_one, BIG_NUMBER *big_number_two) {
    char *ptr_num1 = big_number_one->number_part;
    char *ptr_num2 = big_number_two->number_part;

    return !strcmp(ptr_num1,ptr_num2);
}
