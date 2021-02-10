#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[]={1,2,3}, *ptr = vetor;
    printf("Vetor Antes: ");
    for(int i = 0; i < 3; i++)
    {
        printf(" %i",vetor[i]);
    }
    printf("\nValor do ptr Antes: %d",*ptr);
    *ptr++;
    (*ptr)++;
    printf("\nVetor depois:");
    for(int i = 0; i < 3; i++)
    {
        printf(" %i",vetor[i]);
    }
    printf("\nValor do ptr Depois: %d",*ptr);

    return 0;
}
