#include "MatrizEsparsa/MatrizEsparsa.h"
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
boolean way_exists(SPARSE_MATRIX *matrix, int origem, int destino, int n, int c);

int main() {

    int n; // estações ferroviárias
    int c; // quantidade de conexões existentes

    scanf("%d %d", &n, &c);

    SPARSE_MATRIX *matrix;
    matrix = create_matrix(n, c);

    int origem;
    int destino;
    int distancia;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &origem, &destino, &distancia);
        set(matrix, origem, destino, distancia);
    }

    scanf("%d %d", &origem, &destino);

    if (way_exists(matrix, origem, destino, n, c))
        printf("Existe caminho\n");
    else
        printf("Não existe caminho\n");

    return EXIT_SUCCESS;
}

boolean way_exists(SPARSE_MATRIX *matrix, int origem, int destino, int n, int c) {
    int connection = 0;
    while (connection < c) {
        float exist = get(matrix, origem, 0);

        if (exist)
            way_exists(matrix, connection, destino, n, c);

        connection++;

        if (get(matrix, origem, destino))
            return TRUE;
    }
    return FALSE;
}