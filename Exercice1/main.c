#include <stdio.h>
#include <stdlib.h>
#include "analitica.h"

/*INFORMAÇÕES:
    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Estrutura de Dados I
    Professor: Leonardo Tórtoro Pereira
*/

int main() {
    int number_of_pairs = 0;

    scanf("%d", &number_of_pairs);

    point *pair = create_pairs(number_of_pairs);

    for (int i = 0; i < number_of_pairs; i++) {
        read_pairs(&pair[i]);
    }

    unity_type distance = total_distance(pair, number_of_pairs);

    printf("%.2f \n", distance);

    free(pair);
    return EXIT_SUCCESS;
}
