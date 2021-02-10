#ifndef ETPILHAESTATICA_H_INCLUDED
#define ETPILHAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000
//==================================================
typedef struct Pilha
{
    char dados[MAX];
    int topo;
} Pilha;
//==================================================
void create_pilha(Pilha *p)
{
    p->topo = 0;
}
//==================================================
bool push(Pilha *p, char dado)
{

    if(p->topo == MAX)
    {
        //printf("\nPilha Cheia!\n");
        return false;
    }

    p->dados[p->topo] = dado;
    p->topo++;
    return true;
}

//==================================================
char pop(Pilha *p)
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

    printf("\nTamanho: %i\n", p->topo);
    for(int i=p->topo-1; i>=0; i--)
        printf("%c\n", p->dados[i]);

}
//==================================================
bool is_empty(Pilha *p)
{
    return p->topo == 0;
}
void et()
{
    int tam=0,txt;
    char text[1000];
    Pilha p, aux;
    create_pilha(&p);
    create_pilha(&aux);
    printf("Adcione o texto\n");
    scanf("%s",text);
    fflush(stdin);
    txt = strlen(text);
    for(int i = 0; i < txt; i++)
    {
        push(&p,text[i]);
    }
    //print_pilha(&p);
    for(int i =0; i < txt; i++)
    {
        if(tam == 70)
        {
            print_pilha(&p);
            create_pilha(&p);
            tam = 0;
        }
        else if(text[i] == '#')
        {
            pop(&p);
        }
        else if(text[i]== '/')
        {
            create_pilha(&p);
        }
        else if(text[i]== '@')
        {
            print_pilha(&p);
            create_pilha(&p);
        }
        tam++;
    }
}
#endif // ETPILHAESTATICA_H_INCLUDED
