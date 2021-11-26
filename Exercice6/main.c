#include "Bank/Bank.h"
#include "Tree/Tree.h"
#include <stdio.h>
#include <stdlib.h>
#define NOT_ONLY_CPF FALSE
#define ONLY_CPF TRUE

/*INFORMAÇÕES:
    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Estrutura de Dados I
    Professor: Leonardo Tórtoro Pereira
*/

CPF read_CPF(boolean only_cpf);
NAME read_name();
AGE read_age();
BALANCE read_balance();
BANK *get_client_data();
void insertion_option(BINARY_TREE *tree);
void remove_option(BINARY_TREE *tree);
void search_option(BINARY_TREE *tree);

int main() {

    BINARY_TREE *tree;
    tree = create_tree();

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        BANK *client = get_client_data();
        insert_tree(tree, client);
    }

    char command[2];
    scanf("%s", command);

    if (select_command(command) == insercao)
        insertion_option(tree);
    else if (select_command(command) == remocao)
        remove_option(tree);
    else if (select_command(command) == busca)
        search_option(tree);
    else
        printf("\n\nCommand not found");

    printf("\n"); // RunCodes Pediu
    return erase_tree(&tree)
               ? EXIT_SUCCESS
               : EXIT_FAILURE;
}

void insertion_option(BINARY_TREE *tree) {
    BANK *client = get_client_data();
    insert_tree(tree, client);
    printf("Preorder\n");
    pre_order_tree(tree);
}

void remove_option(BINARY_TREE *tree) {
    CPF cpf = read_CPF(ONLY_CPF);
    BANK *client = search_tree(tree, cpf);
    if (remove_tree(tree, cpf)) {
        print_client(client);
        printf("Preorder\n");
        pre_order_tree(tree);
    } else {
        printf("Error to remove client");
    }
}

void search_option(BINARY_TREE *tree) {
    CPF cpf = read_CPF(ONLY_CPF);
    BANK *client = search_tree(tree, cpf);
    if (client != NULL)
        print_client(client);
    else
        printf("Pessoa nao encontrada.\n"); //404
}

BANK *get_client_data() {
    getchar();
    CPF cpf = read_CPF(NOT_ONLY_CPF);
    NAME name = read_name();
    AGE age = read_age();
    getchar();
    BALANCE balance = read_balance();
    BANK *client = create_bank_client(cpf, name, age, balance);
    free(name);
    return client;
}

CPF read_CPF(boolean only_cpf) {
    CPF cpf;
    if (only_cpf == ONLY_CPF) {
        char cpf_string[15];
        scanf("%s", cpf_string);
        cpf = get_cpf_numbers(cpf_string);
    } else if (only_cpf == NOT_ONLY_CPF) {
        char *cpf_string;
        cpf_string = readStringUntilReach(';');
        cpf = get_cpf_numbers(cpf_string);
        free(cpf_string);
    }
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