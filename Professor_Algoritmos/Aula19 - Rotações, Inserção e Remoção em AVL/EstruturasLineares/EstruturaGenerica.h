#ifndef TADGENERICO_ESTRUTURAGENERICA_H
#define TADGENERICO_ESTRUTURAGENERICA_H

#define TAM_MAX 100 /*estimativa do tamanho máximo da valores*/
#define INICIO 0
#define ERRO (-32000)

#define TRUE 1
#define FALSE 0
typedef int boolean;

void boolean_print(boolean bool);

char *readLine();

typedef struct estrutura_generica ESTRUTURA_GENERICA;

#endif //TADGENERICO_ESTRUTURAGENERICA_H
