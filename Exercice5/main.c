#include "Bank/Bank.h"
#include "Tree/Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*INFORMAÇÕES:
    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Estrutura de Dados I
    Professor: Leonardo Tórtoro Pereira
*/
char *readString();
char *define_cpf_root(char *temp_CPF);
void output(BINARY_TREE *tree);

int main() {

    // Criar Arvore
    BINARY_TREE *tree;
    tree = create_tree();

    // Pegar entrada
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        // Pegar CPF
        getchar();
        char *CPF_string = readString();
        // entrada tratada- retirar "." e "-"
        integer CPF = get_cpf_numbers(CPF_string);
        free(CPF_string);

        // Pegar Nome
        char *name = readString();

        // Pegar Idade
        int age;
        scanf("%d", &age);

        // Pegar Saldo
        getchar();
        double balance;
        scanf("%lf", &balance);

        // Criar cadastro no banco
        BANK *client = create_bank_client(name, CPF, age, balance);

        // insere na arvore
        insert_tree(tree, client);
        
        free(name);
    }
    output(tree);
    // Deletar Arvore
    erase_tree(&tree);

    return EXIT_SUCCESS;
}

char *readString() {
    char c;
    char *string = (char *)malloc(sizeof(char) * 256);
    int index = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == ';') {
            string[index] = '\0';
            break;
        }
        string[index] = c;
        index++;
    }
    return string;
}

void output(BINARY_TREE *tree) {
    // Imprimir In-Order
    printf("Inorder\n");
    in_order_tree(tree);

    // Imprimir Pre-Order
    printf("\nPreorder\n");
    pre_order_tree(tree);

    // Imprimir Post-Order
    printf("\nPostorder\n");
    pos_order_tree(tree);
}