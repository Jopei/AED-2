#ifndef ALETORIOEPOSIÁ„O_H_INCLUDED
#define ALETORIOEPOSIÁ„O_H_INCLUDED
#include <time.h>
#include <locale.h>
void PreecherAleatorio(int **mat,int *col, int *lin)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*(mat+ i) + j) = rand() % 100;//Peenchimente de todass as posiÁıes da matriz utilizado a biblioteca time.h e sua funÁ„o rand

        }
    }
    for(int i=0; i<lin; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ", *(*(mat + i) + j));//Printando a matriz com os valores gerados
        }
        printf("\n");
    }
    MaiorEmenor(mat,col,lin);
}
int MaiorEmenor(int **mat,int col, int lin)
{
    setlocale(LC_ALL,"portuguese");
    int maior = 0, menor =0;
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            /*A partir da matriz o proximo passo e realizado e descobrir qual seu menor e maior valor, para isso
            e utilizado um laÁo de repiÁ„o e codiÁıes*/
            if(*(*(mat+ i) + j) >  maior)
            {
                  maior =*(*(mat+ i) + j);

            }
            if(*(*(mat+ i) + j) <  menor)
            {
                  menor = *(*(mat+ i) + j);

            }

        }
    }
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(*(*(mat+ i) + j) ==  maior)
            {
                  printf("Maior: %i PosiÁ„o: [%i][%i]\n",maior,i,j);

            }
            if(*(*(mat+ i) + j) ==  menor)
            {
                  printf("Menor: %i PosiÁ„o: [%i][%i]\n",menor,i,j);

            }

        }
    }
    return 0;
}

#endif // ALETORIOEPOSIÁ„O_H_INCLUDED
