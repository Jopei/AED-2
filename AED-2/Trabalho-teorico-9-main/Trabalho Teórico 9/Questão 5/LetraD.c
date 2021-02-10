#include "FunSTRCHR.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int LetraD()//codigo auxilar onde se encontrar a questra de Letra D
{
    setlocale(LC_ALL,"portuguese");
    const char  *palavra,letra;
    palavra = (const char *)(malloc(1000 * sizeof(const char)));
    scanf(" %[^\n]s\n",palavra);
    fflush(stdin);
    printf("Escreva a letra procurada\n");
    scanf("%c",&letra);
    char *aux = Func_STRCHR(palavra,letra);
    printf("s = \"%s\"\n",aux);
    free(palavra);

    return 0;
}
