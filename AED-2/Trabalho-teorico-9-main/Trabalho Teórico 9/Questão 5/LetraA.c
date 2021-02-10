#include "FunSTRLEN.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int LetraA()//codigo auxilar onde se encontrar a questra de Letra A
{
    setlocale(LC_ALL,"portuguese");
    char *palavra;
    int Aux = 0;
    printf("Escreva a frase qual deseja descobrir o tamanho\n");
    palavra = (char *)(malloc(1000 * sizeof(char)));//declaração de um char de forma dinamica
    scanf(" %[^\n]s\n",palavra);
    Aux = Func_STRLEN(palavra);
    printf("Tamanho : %d",Aux);
    free(palavra);
    return 0;
}
