#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
//======================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Processo.h"
//======================================
typedef struct Celula
{
    Processo dado;
    struct Celula *prox;
} Celula;
//======================================
typedef struct Fila
{
    Celula *inicio;
    Celula *fim;
    int tam;
} Fila;
//======================================
void create_fila(Fila *f)
{

    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->prox = NULL;

    f->inicio = nova;
    f->fim = nova;
    f->tam = 0;
}
//======================================

/*bool enqueue_prioridade(Fila *f, Processo dado)
{

    Celula *nova = (Celula*)malloc(sizeof(Celula));
    if(nova == NULL)
        return false;
    nova->prox = NULL;
    nova->dado = dado;

    Celula *ant = f->inicio;

    while(ant->prox != NULL && ant->prox->dado.idade >= 65)
        ant = ant->prox;

    //while(ant->prox != NULL && dado.idade >= ant->prox->dado.idade)
    //  ant = ant->prox;

    nova->prox = ant->prox;
    ant->prox = nova;

    if(nova->prox == NULL)
        f->fim = nova;

    f->tam++;

    return true;
}
*/
// Queue
bool enqueue(Fila *f, Processo dado)
{

    //if(dado.idade >= 65)
      //  return enqueue_prioridade(f, dado);

    Celula *nova = (Celula*)malloc(sizeof(Celula));
    if(nova == NULL)
        return false;
    nova->prox = NULL;
    nova->dado = dado;

    f->fim->prox = nova;
    f->fim = nova;
    f->tam++;

    return true;
}
//======================================
void print_fila(Fila *f)
{

    Celula *tmp = f->inicio->prox;

    printf("\nTamanho: %d\n", f->tam);
    while(tmp != NULL)
    {
        print_processo(tmp->dado);
        tmp = tmp->prox;
    }

}
//======================================
Processo dequeue(Fila *f)
{

    if(f->tam == 0)
    {
        return tirar_processo();
    }

    Celula *tmp = f->inicio;
    f->inicio = f->inicio->prox;
    free(tmp);

    f->tam--;
    return f->inicio->dado;
}
//======================================
#endif // FILA_H_INCLUDED


#endif // FILADINAMICA_H_INCLUDED
