#ifndef BANK_H
#define BANK_H
#include "../Util/util.h"

typedef unsigned long long int CPF;
typedef unsigned int AGE;
typedef double BALANCE;
typedef char *NAME;
typedef struct bank_st BANK;

typedef enum {
    insercao = 1,
    remocao,
    busca,
    ERRO = -1
} operation;

operation select_command(char *command);
BANK *create_bank_client(NAME name, CPF cpf, AGE age, BALANCE balance);
CPF get_cpf_numbers(char *CPF);
CPF get_key(BANK *client);
NAME get_name(BANK *client);
AGE get_age(BANK *client);
BALANCE get_balance(BANK *client);
void print_item(BANK *client);
void print_client(BANK *client);

#endif // BANK_H