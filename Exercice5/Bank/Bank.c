#include "Bank.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_st {
    char name[256];
    char CPF[11];
    unsigned int age;
    double balance;
};

static int charToInt(char c);

BANK *create_bank_client(char *name, char *CPF, int age, double balance) {
    BANK *person = (BANK *)malloc(sizeof(BANK));

    strcpy(person->name, name);
    strcpy(person->CPF, CPF);
    person->age = age;
    person->balance = balance;

    return person;
}
char *get_cpf_numbers(char *CPF_string) {
    char *cpf_numbers = (char *)malloc(sizeof(char) * 11);

    for (int i = 0, j = 0; i < 15; i++) {
        if (CPF_string[i] != '-' && CPF_string[i] != '.') {
            cpf_numbers[j] = CPF_string[i];
            j++;
        }
    }
    return cpf_numbers;
}

char *get_key(BANK *client) {
    if (client != NULL)
        return client->CPF;
    return NULL;
}
void print_item(BANK *bank) {
    return;
}

boolean compare_CPF(char *CPF_1, char *CPF_2) {

    while (*CPF_1 == *CPF_2) {
        CPF_1++;
        CPF_2++;
    }
    int MSD_1 = charToInt(CPF_1[0]);
    int MSD_2 = charToInt(CPF_2[0]);

    if (MSD_1 > MSD_2)
        return TRUE;

    return FALSE;
}

static int charToInt(char c) {
    int num = 0;
    num = c - '0';
    return num;
}