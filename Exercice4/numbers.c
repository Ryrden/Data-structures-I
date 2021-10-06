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

char *sum_two_parts(const BIG_NUMBER *part1, const BIG_NUMBER *part2, int *carry) {
    *carry = 0;
    char sum[5];
    char *sum_answer = (char *)malloc(sizeof(char) * 5);
    int num1 = atoi(part1->number_part);
    int num2 = atoi(part2->number_part);

    int part_sum = num1 + num2;

    if (part_sum > 9999) {
        *carry = 1;
        part_sum %= 10000;
        snprintf(sum, sizeof(sum), "%d", part_sum);
    } else if (part_sum < 10) {
        char temp[2];
        strcat(sum, "000");
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcat(sum, temp);
    } else if (part_sum < 100) {
        char temp[3];
        strcat(sum, "00");
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcat(sum, temp);
    } else if (part_sum < 1000) {
        char temp[4];
        strcat(sum, "0");
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcat(sum, temp);
    } else if (part_sum > 1000) {
        char temp[5];
        snprintf(temp, sizeof(temp), "%d", part_sum);
        strcat(sum, temp);
    }
    strcpy(sum_answer, sum);

    return sum_answer;
}