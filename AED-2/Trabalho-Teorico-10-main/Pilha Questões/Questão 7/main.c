#include <stdio.h>
#include <stdlib.h>
#include "Verifica.h""
#include <stdbool.h>
#include <locale.h>
int main()
{
    int n;
    scanf("%i",&n);
    setlocale(LC_ALL,"portuguese");
    char expressao[50];
    printf("Escreva a expressao\n");
    scanf("%c", &expressao);
    int v2 = verifiParetese2(expressao);
    if(verifiParetese2(expressao) == 1)
    {
         printf("corret\n");

    }
    else if(v2 != 0)
    {
        printf("incorret\n");

    }
    return 0;
}
