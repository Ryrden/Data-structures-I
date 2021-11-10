#include <stdlib.h>
#include "Bank.h"

struct bank_st {
    char name[256];
    unsigned int CPF;
    unsigned int age;
    long long int balance;
};
