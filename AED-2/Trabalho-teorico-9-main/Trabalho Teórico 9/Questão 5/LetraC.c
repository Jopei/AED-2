#include "FunSTRCAT.h"
#include <stdio.h>
#include <stdlib.h>
int LetraC()//codigo auxilar onde se encontrar a questra de Letra C
{

    char *palavra, *palavra2;
    int Aux = 0;
    palavra = (char *)(malloc(1000 * sizeof(char)));
    palavra2 = (char *)(malloc(1000 * sizeof(char)));
    scanf(" %[^\n]s\n",palavra);
    fflush(stdin);
    scanf(" %[^\n]s\n",palavra2);
    fflush(stdin);
    Func_STRCAT(palavra,palavra2);
    printf("%s",palavra);
    free(palavra);
    return 0;
}
