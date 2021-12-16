#ifndef UTIL_H
#define UTIL_H

#define TRUE 1
#define FALSE 0
#define ERROR -32000

typedef int boolean;

void boolean_print(boolean bool);

char *readStringUntilReach(char caractere);

char *readLine();

#endif //UTIL_H
