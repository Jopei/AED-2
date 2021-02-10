#ifndef DINAMICA_H_INCLUDED
#define DINAMICA_H_INCLUDED

//===============================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pessoas.h"
//===============================================
typedef struct Celula
{
    Pessoas dado;
    struct Celula *prox;
} Celula;
//===============================================
typedef struct Lista
{
    Celula *inicio;
    Celula *fim;
    int qtd;
} Lista;
//===============================================
void create_lista(Lista *l)
{

    Celula *tmp = (Celula*)malloc(sizeof(Celula));
    tmp->prox = NULL;

    l->inicio = tmp;
    l->fim = tmp;
    l->qtd = 0;
}

//===============================================

bool add_lista(Lista *l, Pessoas p)
{

    Celula *nova = (Celula*)malloc(sizeof(Celula));

    if(nova == NULL)
    {
        printf("\nLista Cheia!\n");
        return false;
    }

    nova->dado = p;
    nova->prox = NULL;

    l->fim->prox = nova;
    l->fim = nova;
    l->qtd++;

    return true;
}

void print_lista(Lista *l)
{

    Celula *tmp = l->inicio->prox;

    while(tmp != NULL)
    {
        print_pessoas(tmp->dado);
        tmp = tmp->prox;
    }

}
Lista Ordenar(Lista *f)
{
    int i = 0, j = f->qtd;
    Pessoas *aux = (Pessoas *)malloc(f->qtd * sizeof(Pessoas));
    for(int i = 0; i < j; i++)
    {
        aux[i] = f->dados[i];
    }
    selecao(aux,j);
    for(int i = 0; i < j; i++)
    {
        f->dados[i] = aux[i];
    }
    return *f;
}
//===============================================

bool update_lista(Lista *l, Pessoas p)
{

    bool achou = false;

    for(Celula *tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {

        if(tmp->dado.id == p.id)
        {
            tmp->dado = p;
            achou = true;
            break;
        }

    }

    if(achou)
        return true;
    else
    {
        printf("\nProduto nao encontrado na lista!\n");
        return false;
    }



}
//===============================================
bool delete_lista(Lista *l, int id)
{

    bool achou = false;
    Celula *ant, *tmp;

    for(ant = l->inicio,tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox, ant=ant->prox)
    {

        if(tmp->dado.id == id)
        {

            ant->prox = tmp->prox;

            if(tmp->prox == NULL)
                l->fim = ant;

            free(tmp);
            l->qtd--;
            achou = true;
            break;

        }

    }

    if(achou)
        return true;
    else
    {
        printf("\nProduto nao encontrado na lista!\n");
        return false;
    }



}
//===============================================
void editar(Lista *l,int n)
{
    char nome[50];
    Celula *tmp;
    for(tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {

        if(tmp->dado.id == n)
        {
            printf("%s\n",tmp->dado.nome);
            printf("Redigite o nome:\n");
            scanf(" %[^\n]s\n",tmp->dado.nome);
            fflush(stdin);
            printf("Redigite a idade:\n");
            scanf("%i",&tmp->dado.idade);
            printf("%s\n",tmp->dado.nome);


        }

    }
}
int print_procurada(Lista *l, int n)
{
    Celula *tmp;
    for(tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {

        if(tmp->dado.id == n)
        {
            printf("\n-------------------\n");
            printf("id: %d\n",tmp->dado.id);
            printf("nome: %s\n",tmp->dado.nome);
            printf("idade: %d",tmp->dado.idade);
            printf("\n-------------------\n");
        }
    }
}
void FunClone(Lista *l, Lista *c)//Procedimento que usa de ponteiros para fazer  uma copia da lista l para a lista c
{
    Celula *tmp = l->inicio->prox;
    Pessoas p;
    while(tmp != NULL)
    {
        p = tmp->dado;
        add_lista(&c,p);
        tmp = tmp->prox;
    }
    printf("Lista copiada\n");
}
int Maior(Lista *l)
{
    int Max = 0;
    Celula *tmp;
    for(tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if(Max < tmp->dado.idade)
        {
            Max = tmp->dado.id;
        }
    }
    return Max;
}

/*void concatenar(Lista *l,Lista *c,Lista *cc)
{
    int registro=1;
    Celula *tmp;
    Celula *tmpc;
    Celula *conc = cc->inicio->prox;
    for(tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        conc->dados.id = tmp->dado.id;
        conc = conc->prox;
    }
    for(tmpc = c->inicio->prox; tmpc != NULL; tmpc = tmpc->prox)
    {
        conc->dados = tmpc->dado;
        conc = conc->prox;
        cc->dado.id = registro;
        registro++;
    }
    for(conc = cc->inicio->prox; conc != NULL; conc = conc->prox)
    {
        printf("--------------\nid: %d\nnome: %s\nidade: %i\n--------------\n",cc->dado.id,cc->dado.nome, cc->dado.idade);
    }
}*/
/*void Inverte(Lista *l, Lista *c)
{
    int Registro = 1;
    Celula *tmp;
    Celula *cpy = c->inicio->prox;
    for(tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        cpy->dados = tmp->dado;
        cpy = cpy->prox;
    }
    for(tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        l->dados[i] = c->dados[l->qtd - i - 1];
        l->dados[i].id = Registro;
        Registro++;

    }
    printf("Procedimento realizado!\n");
}*/
#endif // DINAMICA_H_INCLUDED
