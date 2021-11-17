#include "Bank.h"
#include <errno.h>
#include <stdio.h>
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
int get_key(BANK *bank) {
    return 1;
}
void print_item(BANK *bank) {
    return;
}

static int charToInt(char c){
	int num = 0;
	num = c - '0';
	return num;
}

boolean compare_CPF(char *CPF_1, char *CPF_2) {

    while (*CPF_1 == *CPF_2){
        CPF_1++;
        CPF_2++;
    }
    int MSD_1 = charToInt(CPF_1[0]);
    int MSD_2 = charToInt(CPF_2[0]);
    
    if (MSD_1 > MSD_2)
        return TRUE;

    return FALSE;
}
