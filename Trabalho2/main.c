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

int main() {

    BINARY_TREE *tree;
    tree = create_tree();


    return erase_tree(&tree)
               ? EXIT_SUCCESS
               : EXIT_FAILURE;
}