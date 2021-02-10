#ifndef VERIFICA_H_INCLUDED
#define VERIFICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
//==================================================
typedef struct Pilha
{
    int dados[MAX];
    int topo;
} Pilha;
//==================================================
void create_pilha(Pilha *p)
{
    p->topo = 0;
}
//==================================================
bool push(Pilha *p, int dado)
{

    if(p->topo == MAX)
    {
        printf("\nPilha Cheia!\n");
        return false;
    }

    p->dados[p->topo] = dado;
    p->topo++;
    return true;
}

//==================================================
int pop(Pilha *p)
{

    if(p->topo == 0)
    {
        return -1;
    }

    p->topo--;
    return p->dados[p->topo];
}
//==================================================
void print_pilha(Pilha *p)
{

    printf("\nTamanho: %d\n", p->topo);
    for(int i=p->topo-1; i>=0; i--)
        printf("%d\n", p->dados[i]);

}
//==================================================
bool is_empty(Pilha *p)
{
    return p->topo == 0;
}
int verifiParetese2(char expressao[])
{
    /*Função que faz a verificação antraves de um for que passa por toda string e contabiliza o numero de parenteses
    contidos sendo que na pilha e adcionado um valor cada vez que aparece o parentese de abertura '(', e caso aparece
    o parentese de fechamento e retirado um valor da pilha*/
    Pilha p;
    create_pilha(&p);
     for (int i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] == '(')
        {
            push(&p,1);
        }
        else if (expressao[i] == ')')
        {
            int aux = pop(&p);
            if(aux == -1)
            {
                return 0;
            }
        }
    }
    if(is_empty(&p))
    {
        return 1;
    }
    else
        return 0;

}

#endif // VERIFICA_H_INCLUDED
