#include <stdio.h>
#include <stdlib.h>
#include "CauculadoraBasica.h"
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");
    int *a = (int *)malloc(1);//Declaração de ponteiros de forma dinamica
    int *b = (int *)malloc(1);
    printf("Coloque os dois valores em sequência\n");
    scanf("%i",a);
    fflush(stdin);
    scanf("%i",b);
    fflush(stdin);//chamada da função
    menu(a,b);
    free(a);
    free(b);
    return 0;
}
