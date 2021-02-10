#include <stdio.h>
#include <stdlib.h>
#include "PeencherESomarVetor.h"
int main()
{
    int tamanho = 0;
    int somat;
    scanf("%i",&tamanho);
    int *vet = (int *)(malloc(tamanho * sizeof(int)));//Declaração de um vetor dinamico
    Preencher(vet,tamanho);
    somat = somarVet(vet,tamanho);//Chamada da função
    printf("\nSoma: %i",somat);
    free(vet);
    return 0;
}
