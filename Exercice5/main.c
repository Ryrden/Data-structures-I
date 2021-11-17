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

int main() {

    // Criar Arvore
    BINARY_TREE *tree;
    tree = create_tree();

    // Pegar entrada
    int n;
    scanf("%d", &n);

    char CPF_root[11];
    for (int i = 0; i < n; i++) {
        // Pegar CPF

        getchar();
        char *CPF_string = readString();
        // tratar entrada - retirar "." e "-"
        char *CPF = get_cpf_numbers(CPF_string);
        free(CPF_string);

        // define raiz
        if (i == 0)
            strcpy(CPF_root, CPF);

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
        printf("\n%s %s %d %.2f\n", CPF, name, age, balance);
        // Comparar CPF
        if (compare_CPF(CPF, CPF_root)) {
            // Se maior -> Direita
            // Inserir na Arvore

        } else {
            // Se menor -> Esquerda
            // Inserir na Arvore
        }
        free(CPF);
        free(name);
    }

    // Imprimir In-Order
    in_order_tree(tree);

    // Imprimir Pre-Order
    pre_order_tree(tree);

    // Imprimir Post-Order
    pos_order_tree(tree);

    // Deletar Arvore
    erase_tree(tree);

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
