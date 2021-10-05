#include "numbers.h"
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

    int n;
    char command[6];
    int first_integer;
    int second_integer;

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        scanf("%d", &first_integer);
        scanf("%d", &second_integer);
        
        if (select_command(command) == soma) {
            
        } else if (select_command(command) == maior) {

        } else if (select_command(command) == menor) {

        } else if (select_command(command) == igual) {

        } else {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
