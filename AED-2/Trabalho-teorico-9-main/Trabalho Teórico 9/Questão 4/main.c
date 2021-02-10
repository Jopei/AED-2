#include<stdio.h>
#include<time.h>
#include "PreecherAletoriosoma.h"
int main (void )
{
    int **mat;//Declara��o de matriz como ponteiro de ponteiro para da suporte a cria��o dos vetores dinamicos
    int coluna = 5, linha = 5;
    mat = malloc(linha * sizeof(int *));//declara��o de vetores de forma dinamica
    for (int i = 0; i < linha; ++i)
    {
        *(mat + i) = (int *)malloc(coluna * sizeof(int));// declara��o de vetores dentro de espa�os ja declardos
    }
    PreecherAletoriosoma(mat,coluna,linha);
    free(mat);
    return 0;

}
