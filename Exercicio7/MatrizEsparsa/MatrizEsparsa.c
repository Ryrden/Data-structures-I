#include "MatrizEsparsa.h"
#include <malloc.h>

typedef struct cell_st CELL;

struct cell_st {
    int row;
    int column;
    float value;
    CELL *next;
    CELL *below;
};

struct sparte_matrix_st {
    CELL **rows;
    CELL **columns;
    int nr_rows;
    int nr_columns;
};

SPARSE_MATRIX *create_matrix(int nr_rows, int nr_columns) {
    SPARSE_MATRIX *matrix = (SPARSE_MATRIX*) malloc(sizeof(SPARSE_MATRIX*));
    if (matrix != NULL) {
        matrix->nr_columns = nr_columns;
        matrix->nr_rows = nr_rows;
        matrix->columns = (CELL **)malloc(sizeof(CELL *) * nr_columns);
        matrix->rows = (CELL **)malloc(sizeof(CELL *) * nr_rows);
        if (matrix->columns != NULL && matrix->rows != NULL) {
            for (int i = 0; i < nr_columns; i++) {
                matrix->columns[i] = NULL;
            }
            for (int i = 0; i < nr_rows; i++) {
                matrix->rows[i] = NULL;
            }
        }
    }
    return matrix;
}

void erase_matrix_cells(SPARSE_MATRIX **matrix) {
    for (int i = 0; i < (*matrix)->nr_rows; i++) {
        if ((*matrix)->rows[i] != NULL) {
            CELL *cell = (*matrix)->rows[i]->next;
            while (cell != NULL) {
                CELL *previous_cell = cell;
                cell = cell->next;
                free(previous_cell);
                previous_cell = NULL;
            }
        }
        free((*matrix)->rows[i]);
        (*matrix)->rows[i] = NULL;
    }
    free((*matrix)->rows);
    (*matrix)->rows = NULL;
    free((*matrix)->columns);
    (*matrix)->columns = NULL;
    free((*matrix));
    *matrix = NULL;
}

int set(SPARSE_MATRIX *matrix, int row, int column, float value) {
    CELL *actual_cell;
    CELL *column_cell;
    CELL *previous_column_cell;
    if ((row > matrix->nr_rows) || (column > matrix->nr_columns)) {
        return 0;
    }
    actual_cell = (CELL *)malloc(sizeof(CELL));
    if (actual_cell == NULL)
        return 0;
    actual_cell->row = row;
    actual_cell->column = column;
    actual_cell->value = value;
    // inserir na lista da column column
    column_cell = matrix->columns[column];
    previous_column_cell = NULL;
    int inserted = 0;
    while (column_cell != NULL && !inserted) {
        if (column_cell->row < row) {
            previous_column_cell = column_cell;
            column_cell = column_cell->below;
        } else {
            // achou rows maior
            if (previous_column_cell == NULL)
                matrix->columns[column] = actual_cell;
            else
                previous_column_cell->below = actual_cell;
            actual_cell->below = column_cell;
            inserted = 1;
        }
    }
    // inserir como último da lista columns
    if (column_cell == NULL) {
        if (previous_column_cell == NULL) {
            matrix->columns[column] = actual_cell;
        } else {
            previous_column_cell->below = actual_cell;
        }
    }
    // TODO algoritmo simetrico para as rows
    return 1;
}

float get(SPARSE_MATRIX *matrix, int row, int column) {
    if (matrix->nr_rows < row || matrix->nr_columns < column)
        return 0;

    CELL *actual_cell = matrix->rows[row];

    if (actual_cell == NULL)
        return 0;

    while (actual_cell->next != NULL && column > actual_cell->next->column)
        actual_cell = actual_cell->next;
    if (actual_cell->column == column)
        return (actual_cell->value);
    return 0;
}
