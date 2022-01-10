#ifndef TADGENERICO_MATRIZESPARSA_H
#define TADGENERICO_MATRIZESPARSA_H

typedef struct matriz_esparsa MATRIZ_ESPARSA;

MATRIZ_ESPARSA *criar_matriz(int nr_linhas, int nr_colunas);
void apagar_matriz(MATRIZ_ESPARSA **matriz);
int set(MATRIZ_ESPARSA *matriz, int linha, int coluna, float valor);
float get(MATRIZ_ESPARSA *matriz, int linha, int coluna);
void imprimir_matriz(MATRIZ_ESPARSA *matriz);

#endif //TADGENERICO_MATRIZESPARSA_H
