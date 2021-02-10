#ifndef PEENCHERESOMARVETOR_H_INCLUDED
#define PEENCHERESOMARVETOR_H_INCLUDED
#include <time.h>
void Preencher(int *vetor,int n)
{
    srand(time(NULL));
    for(int i=0;i < n; i++)
    {
        vetor[i] = rand() %100;//preenchimento do vetor de forma aleatoia
    }
    for(int i=0; i < n; i++)
    {
        printf("%i ",vetor[i]);
    }
}
int somarVet(int *vetor, int n)
{
    int soma=0;
    for(int i=0; i < n; i++)
    {
        soma = soma + vetor[i]; //laço utilizado para somar todas as variavies do vetor
    }
    return soma;
}
#endif // PEENCHERESOMARVETOR_H_INCLUDED
