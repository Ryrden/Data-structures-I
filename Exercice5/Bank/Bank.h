#ifndef BANK_H
#define BANK_H
#include "../Util/util.h"

typedef struct bank_st BANK;

BANK create_bank_item(char *name, int CPF, int age, int balance);
int get_cpf_numbers(char *CPF);
int get_key(BANK *bank);
void print_item(BANK *bank);
boolean compare_CPF(int CPF_1, int CPF_2);

#endif //BANK_H