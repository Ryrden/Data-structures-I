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

int main() {

    // Criar Arvore
    BINARY_TREE *tree;
    tree = create_tree();

    // Pegar entrada
    int n;
    scanf("%d", &n);

    char line[256];
    int CPF_root;
    for (int i = 0; i < n; i++) {
        // Pegar Linha
        fgets(line, 256, stdin);
        line[strlen(line) - 1] = '\0';

        // Pegar CPF
        char *CPF_string = strtok(line, ";");
        // tratar entrada - retirar "." e "-"
        int CPF = get_cpf_numbers(CPF_string);

        // define raiz
        if (i == 0)
            CPF_root = CPF;

        // Pegar Nome
        char *name = strtok(NULL, ";");
        name[strlen(line) - 1] = '\0';

        // Pegar Idade
        int age = atoi(strtok(NULL, ";"));

        // Pegar Saldo
        int balance = atoi(strtok(NULL, "\n"));

        // Criar cadastro no banco
        printf("%d %s %d %d", CPF, name, age, balance);
        // Comparar CPF
        if (compare_CPF(CPF, CPF_root)) {
            // Se maior -> Direita
            // Inserir na Arvore
            
        } else {
            // Se menor -> Esquerda
            // Inserir na Arvore
            
        }
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
