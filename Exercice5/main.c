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

int main() {

    BINARY_TREE *tree;
    tree = create_tree();

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        getchar();
        char *CPF_string = readStringUntilReach(';');
        // entrada tratada- retirar "." e "-"
        integer CPF = get_cpf_numbers(CPF_string);
        free(CPF_string);

        char *name = readStringUntilReach(';');

        int age;
        scanf("%d", &age);

        getchar();
        double balance;
        scanf("%lf", &balance);

        BANK *client = create_bank_client(name, CPF, age, balance);

        insert_tree(tree, client);

        free(name);
    }

    output(tree);
    if (erase_tree(&tree))
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

void output(BINARY_TREE *tree) {
    printf("Inorder\n");
    in_order_tree(tree);

    printf("\nPreorder\n");
    pre_order_tree(tree);

    printf("\nPostorder\n");
    pos_order_tree(tree);
    printf("\n"); //RunCodes pediu
}