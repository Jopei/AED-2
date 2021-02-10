#ifndef POLONESA_H_INCLUDED
#define POLONESA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 10

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
bool push(Pilha *p, int dado)
{

    if(p->topo == MAX)
    {
        return false;
    }

    p->dados[p->topo] = dado;
    p->topo++;
    return true;
}
void Polonesa()
{
    //Utilizado o comando que permite a utilização de progamas em portugues do brasil
    setlocale(LC_ALL,"portuguese");
    Pilha p,cpy;
    int x = 0,y = 0,i=0;
    create_pilha(&p);
    create_pilha(&cpy);
    char aux[50];
    printf("Digite a expressão\n");
    scanf("%[^\n]s\n",&aux);
    fflush(stdin);
    /*A notação polonesa e separada em numeros e expressoes matematica sendo que todas as vezes que aparecem as expressoes
    as variaveis anteriores realizam a operação que aparece dentre as quatro, caso não apareco a pilha recebe um push*/
    while (aux[i] != '\n')
    {
        if(aux[i] == '+')
        {
            x = pop(&p);
            y = pop(&p);
            push(&p, y + x);
            printf("%i\n", (y + x)*(-1));
            break;
        }
        else if(aux[i] == '-')
        {
            x = pop(&p);
            y = pop(&p);
            push(&p, y - x);
            printf("%i\n", (y - x)*(-1));
            break;
        }
        else if(aux[i] == '*')
        {
            x = pop(&p);
            y = pop(&p);
            push(&p, y * x);
            printf("%i\n", (y * x)*(-1));
            break;
        }
        else if(aux[i] == '/')
        {
            x = pop(&p);
            y = pop(&p);
            push(&p, y / x);
            printf("%i\n",(y / x)*(-1));
            break;
        }
        else
        {
            push(&p,aux[i] - '0');
        }
        i++;
    }
}
//==================================================
int pop(Pilha *p)
{

    if(p->topo == 0)
    {
        printf("\nPilha Vazia!\n");
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
//==================================================

#endif // POLONESA_H_INCLUDED
