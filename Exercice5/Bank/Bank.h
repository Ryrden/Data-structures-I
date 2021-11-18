#ifndef BANK_H
#define BANK_H
#include "../Util/util.h"

typedef unsigned long long int CPF;
typedef unsigned int AGE;
typedef double BALANCE;
typedef char* NAME;
typedef struct bank_st BANK;

BANK *create_bank_client(NAME name, CPF cpf, AGE age, BALANCE balance);
CPF get_cpf_numbers(char *CPF);
CPF get_key(BANK *client);
void print_item(BANK *client);

#endif // BANK_H