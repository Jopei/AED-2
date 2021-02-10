#ifndef CAUCULADORABASICA_H_INCLUDED
#define CAUCULADORABASICA_H_INCLUDED
#include <locale.h>
void menu(int *a,int *b)
{
    setlocale(LC_ALL,"portuguese");
    int opc=-1, resposta;
    do
    {

        printf("\n\tEsconha a operação\n\n");
        printf("1. Soma\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("0. Sair\n");
        scanf("%d", &opc);
        system("cls || clear");
        switch(opc)
        {
        case 1:
            resposta = (int *)malloc(1);//desclaração de forma dinamica a cada operação do que o usuario solicitar
            resposta = (*a)+(*b);
            printf("Resultado da soma: %i\n",resposta);
            break;

        case 2:
            resposta = (int *)malloc(1);
            resposta = (*a)-(*b);
            printf("Resultado da subtração: %i\n",resposta);
            break;

        case 3:
            resposta = (int *)malloc(1);
            resposta = (*a)*(*b);
            printf("Resultado da multiplicação:%i\n",resposta);
            break;

        case 4:
            resposta = (int *)malloc(1);
            resposta = (*a)/(*b);
            printf("Resultado da divisão: %i\n",resposta);
            break;
        case 0:
            break;

        default:
            printf("Erro digite um valor entre os indicados \n");
        }
    }
    while(opc !=0);
    free(resposta);
}

#endif // CAUCULADORABASICA_H_INCLUDED
