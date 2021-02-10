#ifndef MERGEORDENA_H_INCLUDED
#define MERGEORDENA_H_INCLUDED
#include "pessoa.h"
//Metodo utilizado na ordenação da fila
void selecao(Pessoa *array, int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        int menor = i;
        for (int j = (i + 1); j < n; j++)
        {
            if (array[menor].idade > array[j].idade)
            {
                menor = j;
            }
        }
        swap(&array[menor], &array[i]);
    }
}
void swap(Pessoa *i, Pessoa *j) {
   Pessoa temp = *i;
   *i = *j;
   *j = temp;
}
#endif // MERGEORDENA_H_INCLUDED
