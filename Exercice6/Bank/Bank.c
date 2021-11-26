#include "Bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Observação, não coloquei os typdefs aqui por questão de que a struct deve abrigar tipos de dados,
desta forma, fica claro quais são. Acredito que não envolva legibilidade aqui (Se sim, me de um feedback por favor). */
struct bank_st {
    char name[256];
    unsigned long long int cpf;
    unsigned int age;
    double balance;
};

static void pass_cpf_numbers(char *cpf_numbers, char *cpf_string);
static void pass_data_to_client(BANK *client, NAME name, CPF cpf, AGE age, BALANCE balance);

BANK *create_bank_client(CPF cpf, NAME name, AGE age, BALANCE balance) {
    if (cpf > 0) { // Verificação símbolica
        BANK *client = (BANK *)malloc(sizeof(BANK));
        pass_data_to_client(client, name, cpf, age, balance);
        return client;
    }
    printf("\nINVALID CPF\n");
    return NULL;
}

static void pass_data_to_client(BANK *client, NAME name, CPF cpf, AGE age, BALANCE balance) {
    strcpy(client->name, name);
    client->cpf = cpf;
    client->age = age;
    client->balance = balance;
}

CPF get_key(BANK *client) {
    if (client != NULL)
        return client->cpf;
    return ERROR;
}

NAME get_name(BANK *client) {
    if (client != NULL)
        return client->name;
    return NULL;
}

AGE get_age(BANK *client) {
    if (client != NULL)
        return client->age;
    return ERROR;
}

BALANCE get_balance(BANK *client) {
    if (client != NULL)
        return client->balance;
    return ERROR;
}

void print_client(BANK *client) {
    CPF cpf = get_key(client);
    char *formated_cpf = format_cpf_numbers(cpf);

    printf("Conta :: %s\n", get_name(client));
    printf("CPF :: %s\n", formated_cpf);
    printf("Idade :: %u\n", get_age(client));
    printf("Saldo atual :: R$ %.2f\n", get_balance(client));

    free(formated_cpf);
}

void print_item(BANK *client) {
    printf("%llu\n", client->cpf);
}

CPF get_cpf_numbers(char *cpf_string) {
    if (cpf_string != NULL) {
        char cpf_numbers[11];
        pass_cpf_numbers(cpf_numbers, cpf_string);
        char *remaining;
        CPF cpf = strtoull(cpf_numbers, &remaining, 10);
        return cpf;
    }
    printf("\nNULL CPF\n");
    return ERROR;
}

static void pass_cpf_numbers(char *cpf_numbers, char *cpf_string) {
    for (int i = 0, j = 0; i < 15; i++)
        if (cpf_string[i] != '-' && cpf_string[i] != '.') {
            cpf_numbers[j] = cpf_string[i];
            j++;
        }
}

char *format_cpf_numbers(CPF cpf) {
    char temp_cpf_string[11];
    sprintf(temp_cpf_string, "%llu", cpf);

    char *cpf_string = (char *)malloc(sizeof(char) * 15);
    for (int index = 0,i = 0; index < 11; i++, index++) {
        if (i == 3 || i == 7) {
            cpf_string[i] = '.';
            index--;
        } else if (i == 11) {
            cpf_string[i] = '-';
            index--;
        } else {
            cpf_string[i] = temp_cpf_string[index];
        }
    }
    cpf_string[14] = '\0';
    return cpf_string;
}

operation select_command(char *command) {

    if (!strcmp(command, "I"))
        return insercao;
    else if (!strcmp(command, "R"))
        return remocao;
    else if (!strcmp(command, "B"))
        return busca;

    return ERROR;
}