#include<stdio.h>
#include<time.h>
#include "PreecherAletoriosoma.h"
int main (void )
{
    int **mat;//Declaração de matriz como ponteiro de ponteiro para da suporte a criação dos vetores dinamicos
    int coluna = 5, linha = 5;
    mat = malloc(linha * sizeof(int *));//declaração de vetores de forma dinamica
    for (int i = 0; i < linha; ++i)
    {
        *(mat + i) = (int *)malloc(coluna * sizeof(int));// declaração de vetores dentro de espaços ja declardos
    }
    PreecherAletoriosoma(mat,coluna,linha);
    free(mat);
    return 0;

}
