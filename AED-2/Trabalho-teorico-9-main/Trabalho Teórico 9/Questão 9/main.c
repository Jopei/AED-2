#include <stdio.h>
#include <stdlib.h>
#include "AletorioePosicao.h"
int main()
{
    int **mat;//matriz declarada na forma de Ponteiro de ponteiro para da suporte ao voter criado apartir da posi��o do outro
    int coluna = 5, linha = 5;
    mat = malloc(linha * sizeof(int *));//Crian��o de um vetor usando ponteiro
    for (int i = 0; i < linha; ++i)
    {
        *(mat + i) = (int *)malloc(coluna * sizeof(int));//Cria��o de vetores a partir das posi��es desclada no vetor anteiros criando assim a matriz dinamica
    }
    PreecherAleatorio(mat,coluna,linha);
    free(mat);
    return 0;
}
