#include "Bank.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_st {
    char name[256];
    integer CPF;
    unsigned int age;
    double balance;
};

BANK *create_bank_client(char *name, integer CPF, int age, double balance) {
    BANK *person = (BANK *)malloc(sizeof(BANK));

    strcpy(person->name, name);
    person->CPF = CPF;
    person->age = age;
    person->balance = balance;

    return person;
}
integer get_cpf_numbers(char *CPF_string) {
    char *cpf_numbers = (char *)malloc(sizeof(char) * 11);
    for (int i = 0, j = 0; i < 15; i++) {
        if (CPF_string[i] != '-' && CPF_string[i] != '.') {
            cpf_numbers[j] = CPF_string[i];
            j++;
        }
    }
    char *remaining;
    integer CPF = strtoull(cpf_numbers,&remaining,10);
    return CPF;
}

integer get_key(BANK *client) {
    if (client != NULL)
        return client->CPF;
}
void print_item(BANK *client) {
    return;
}

boolean compare_CPF(integer CPF_1, integer CPF_2) {
    if (CPF_1 > CPF_2)
        return TRUE;

    return FALSE;
}