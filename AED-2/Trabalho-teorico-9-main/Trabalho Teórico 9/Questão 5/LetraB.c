#include "FunSTRCMP.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int LetraB()//codigo auxilar onde se encontrar a questra de Letra B
{
    setlocale(LC_ALL,"portuguese");
    char *palavra, *palavra2;
    int Aux = 0;
    printf("Escreva as duas frases:\n");
    palavra = (char *)(malloc(1000 * sizeof(char)));//declarações de char de forma dinamica
    palavra2 = (char *)(malloc(1000 * sizeof(char)));
    scanf(" %[^\n]s\n",palavra);
    fflush(stdin);
    scanf(" %[^\n]s\n",palavra2);
    fflush(stdin);
    Aux = FunSTRCMP(palavra,palavra2);
    printf("%d",Aux);
    free(palavra);
    return 0;
}
