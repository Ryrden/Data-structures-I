#ifndef BANK_H
#define BANK_H
#include "../Util/util.h"

typedef unsigned long long int integer;
typedef struct bank_st BANK;

BANK *create_bank_client(char *name, integer CPF, int age, double balance);
integer get_cpf_numbers(char *CPF);
integer get_key(BANK *client);
void print_item(BANK *client);

#endif //BANK_H