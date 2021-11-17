#include "Bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_st {
    char name[256];
    integer CPF;
    unsigned int age;
    double balance;
};

static void pass_cpf_numbers(char *CPF_numbers, char *CPF_string);

BANK *create_bank_client(char *name, integer CPF, int age, double balance) {
    if (CPF > 0) {
        BANK *client = (BANK *)malloc(sizeof(BANK));

        strcpy(client->name, name);
        client->CPF = CPF;
        client->age = age;
        client->balance = balance;
        return client;
    }
    printf("\nCPF already registered\n");
    return NULL;
}

integer get_key(BANK *client) {
    if (client != NULL)
        return client->CPF;
    return ERROR;
}

void print_item(BANK *client) {
    printf("%llu\n", client->CPF);
}

integer get_cpf_numbers(char *CPF_string) {
    if (CPF_string != NULL) {
        char CPF_numbers[11];
        pass_cpf_numbers(CPF_numbers,CPF_string);
        char *remaining;
        integer CPF = strtoull(CPF_numbers, &remaining, 10);
        return CPF;
    }
    printf("\nNULL CPF\n");
    return ERROR;
}

static void pass_cpf_numbers(char *CPF_numbers, char *CPF_string) {
    for (int i = 0, j = 0; i < 15; i++) 
        if (CPF_string[i] != '-' && CPF_string[i] != '.') {
            CPF_numbers[j] = CPF_string[i];
            j++;
        } 
}