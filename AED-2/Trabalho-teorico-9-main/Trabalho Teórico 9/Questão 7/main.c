#include <stdio.h>
#include <stdlib.h>
#include "CauculadoraBasica.h"
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");
    int *a = (int *)malloc(1);//Declara��o de ponteiros de forma dinamica
    int *b = (int *)malloc(1);
    printf("Coloque os dois valores em sequ�ncia\n");
    scanf("%i",a);
    fflush(stdin);
    scanf("%i",b);
    fflush(stdin);//chamada da fun��o
    menu(a,b);
    free(a);
    free(b);
    return 0;
}
