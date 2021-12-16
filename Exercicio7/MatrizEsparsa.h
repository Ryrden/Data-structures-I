#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "../Util/util.h"

typedef struct sparse_matrix_st SPARSE_MATRIX;

SPARSE_MATRIX *create_matrix(int nr_rows, int nr_columns);
void erase_matrix(SPARSE_MATRIX **matrix);
int set(SPARSE_MATRIX *matrix, int row, int column, float valor);
float get(SPARSE_MATRIX *matrix, int row, int column);
void print_matrix(SPARSE_MATRIX *matrix);

#endif // MATRIZESPARSA_H
