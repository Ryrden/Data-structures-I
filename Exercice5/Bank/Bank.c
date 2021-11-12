#include "Bank.h"
#include <stdlib.h>

struct bank_st {
    char name[256];
    unsigned int CPF;
    unsigned int age;
    long long int balance;
};

BANK create_bank_item(char *name, int CPF, int age, int balance) {
    BANK bank;
    bank.age = 15;

    return bank;
}
int get_cpf_numbers(char *CPF) {
    return 1;
}
int get_key(BANK *bank) {
    return 1;
}
void print_item(BANK *bank) {
    return;
}
boolean compare_CPF(int CPF_1, int CPF_2) {
    return TRUE;
}
