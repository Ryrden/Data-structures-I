#include "Bank/Bank.h"
#include "Tree/Tree.h"
#include <stdio.h>
#include <stdlib.h>

/*INFORMAÇÕES:
    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Estrutura de Dados I
    Professor: Leonardo Tórtoro Pereira
*/

void output(BINARY_TREE *tree);
CPF read_CPF();
NAME read_name();
AGE read_age();
BALANCE read_balance();

int main() {

    BINARY_TREE *tree;
    tree = create_tree();

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        getchar();
        CPF cpf = read_CPF();
        NAME name = read_name();
        AGE age = read_age();
        getchar();
        BALANCE balance = read_balance();

        BANK *client = create_bank_client(name, cpf, age, balance);
        insert_tree(tree, client);
        free(name);
    }
    char command[10];
    scanf("%s", command);

    if (select_command(command) == insercao) {
        // Inserção
        
    } else if (select_command(command) == remocao) {
        // Remocação

    } else if (select_command(command) == busca) {
        // Busca

    } else {
        printf("\n\nCommand not found");
    }

    return erase_tree(&tree)
               ? EXIT_SUCCESS
               : EXIT_FAILURE;
}

CPF read_CPF() {
    char *cpf_string = readStringUntilReach(';');
    // entrada tratada- retirar "." e "-"
    CPF cpf = get_cpf_numbers(cpf_string);
    free(cpf_string);
    return cpf;
}

NAME read_name() {
    return readStringUntilReach(';');
}

AGE read_age() {
    AGE age;
    scanf("%d", &age);
    return age;
}

BALANCE read_balance() {
    BALANCE balance;
    scanf("%lf", &balance);
    return balance;
}
