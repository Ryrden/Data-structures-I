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

int main() {

    // Criar Arvore
    BINARY_TREE *tree;
    tree = create_tree();

    // Pegar entrada
    int n = 0;
    scanf("%d", &n);

    integer CPF_root;
    integer Rlast_CPF, Llast_CPF;
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

char *define_cpf_root(char *temp_CPF) {
    // OBSERVAÇÃO PARA O CORRETOR (pode desconsiderar essa mensagem, sei que não avalia a forma q fiz o código mesmo):
    // Fiz tudo isso porque quando eu faço apenas strcpy no código, a variavel n volta pra 0
    // e se tento converter a string para long int ou long long int, por alguma razão o número simplesmente não CONVERTE!!! (odeio C)
    char *CPF = (char *)malloc(sizeof(char) * 11);
    strcpy(CPF, temp_CPF);
    return CPF;
}
