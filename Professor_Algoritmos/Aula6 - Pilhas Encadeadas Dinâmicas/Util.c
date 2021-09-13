#include <stdio.h>
#include "Util.h"

void boolean_print(boolean bool)
{
    if(bool == TRUE)
    {
        printf("TRUE\n");
    }
    else if(bool == FALSE)
    {
        printf("FALSE\n");
    }
    else
    {
        printf("ERRO\n");
    }
}
