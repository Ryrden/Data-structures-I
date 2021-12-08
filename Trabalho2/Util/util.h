#ifndef UTIL_H
#define UTIL_H

#define TRUE 1
#define FALSE 0
#define ERROR -32000
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

typedef int boolean;

void boolean_print(boolean bool);

char *readStringUntilReach(char caractere);

char *readLine();

#endif // UTIL_H
