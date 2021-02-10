#ifndef ESTATICA_H_INCLUDED
#define ESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pessoas.h"
//=================================================
typedef struct Lista
{
    Pessoas *dados;
    int MAX;
    int qtd;
} Lista;
//=================================================
void create_lista(Lista *l, int n)
{
    l->MAX = n;
    l->dados = (Pessoas*)malloc(n*sizeof(Pessoas));
    l->qtd = 0;
}
//=================================================
bool add_lista(Lista *l, Pessoas p)
{

    if(l->qtd == l->MAX)
    {
        printf("\nLista cheia!\n");
        return false;
    }

    l->dados[l->qtd++] = p;

    return true;
}
//=================================================
void print_lista(Lista *l)
{

    for(int i=0; i<l->qtd; i++)
        print_pessoas(l->dados[i]);

}
int Maior(Lista *l)
{
    int Max = 0,n;
    for(int i = 0; i < l->qtd; i++)
    {
        if(Max < l->dados[i].idade)
        {
            Max = l->dados[i].idade;
        }
    }

    for(int i = 0; i <l->qtd; i++)
    {
        if(Max == l->dados[i].idade)
        {
            return l->dados[i].nome;
        }
    }

}
int MaiorNome(Lista *l)
{
    int Max = 0,n;
    for(int i = 0; i < l->qtd; i++)
    {
        if(Max < l->dados[i].idade)
        {
            Max = l->dados[i].idade;
        }
    }

    for(int i = 0; i <l->qtd; i++)
    {
        if(Max == l->dados[i].idade)
        {
            return l->dados[i].idade;
        }
    }

}
//=================================================
bool update_lista(Lista *l, Pessoas p)
{

    if(p.id <= 0 || p.id > l->qtd)
    {
        printf("Pessoa não encontrada na lista");
        return false;
    }

    l->dados[p.id-1] = p;
    return true;
}
//=================================================
bool delete_lista(Lista *l, int id)
{

    if(id <= 0)
    {
        printf("Pessoa não encontrada na lista");
        return false;
    }

    for(int i=id; i < l->qtd; i++)
    {
        l->dados[i-1] = l->dados[i];
        l->dados[i-1].id--;
    }

    l->qtd--;
    return true;
}
int print_procurada(Lista *l, char *n)
{
    for(int i=0; i < l->qtd; i++)
    {
        if(strlen(n) == strlen(l->dados[i].nome))
        {
            return l->dados[i].id;
        }
        else
            return -1;
    }
}
void editar(Lista *l, int n)
{
    char nome[50];
    int idade;
    for(int i=0; i < l->qtd; i++)
    {
        if(l->dados[i].id == n)
        {
            printf("Redigite o nome:\n");
            scanf(" %[^\n]s\n",nome);
            fflush(stdin);
            strcpy(l->dados[i].nome,nome);
            printf("Redigite a idade:\n");
            scanf("%i",&idade);
            l->dados[i].idade = idade;
        }
        else
            printf("Usuário não encontrado\n");
    }
}
void FunClone(Lista *l, Lista *c)
{
    c->qtd = l->qtd;
    c->MAX = l->MAX;
    for(int i = 0; i < l->qtd; i++)
    {
        c->dados[i].id = l->dados[i].id;
        strcpy(c->dados[i].nome,l->dados[i].nome);
        c->dados[i].idade = l->dados[i].idade;
    }
    printf("Lista copiada\n");
}

void Inverte(Lista *l, Lista *c) //Procediemnto que utiliza c como lista auxiliar passado os dados de l para c apos retornado os dados inverso
{
    int Registro = 1;
    for(int i = 0; i < l->qtd; i++)
    {
        c->dados[i] = l->dados[i];
    }
    for(int i = 0; i < l->qtd; i++)
    {
        l->dados[i] = c->dados[l->qtd - i - 1];
        l->dados[i].id = Registro;
        Registro++;

    }
    printf("Procedimento realizado!\n");
}
void concatenar(Lista *l,Lista *c,Lista *cc)//Procedimento que faz a passagem de dados de l para cc e apos os dados de c para cc
{
    int i,registro=1;
    for(i = 0; i < l->qtd; i++)
    {
        cc->dados[i].id = l->dados[i].id;
        strcpy(cc->dados[i].nome,l->dados[i].nome);
        cc->dados[i].idade = l->dados[i].idade;
    }
    for(int j = 0;j < c ->qtd; j++)
    {
        cc->dados[i].id = c->dados[j].id;
        strcpy(cc->dados[i].nome,c->dados[j].nome);
        cc->dados[i].idade = c->dados[j].idade;
        i++;
        cc->dados[i].id = registro;
        registro++;
    }
    for(int j = 0;j < i; j++)
    {
        printf("--------------\nid: %d\nnome: %s\nidade: %i\n--------------\n",cc->dados[j].id,cc->dados[j].nome, cc->dados[j].idade);
    }
}
void selecao(Pessoas *array, int n)//Procedimento de ordenação adaptado para struct
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
void swap(Pessoas *i, Pessoas *j) {
   Pessoas temp = *i;
   *i = *j;
   *j = temp;
}
Lista Ordenar(Lista *f)//Procedimento utilizado para ordena a partir do metodo de seleção
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
void quicksortRec(Pessoas *array, int esq, int dir) {//Procedimento utilizado para ordena a lista atraves de seu id
    int i = esq, j = dir;
    int pivo = array[(dir+esq)/2].id;
    while (i <= j) {
        while (array[i].id < pivo) i++;
        while (array[j].id > pivo) j--;
        if (i <= j) {
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j);
    if (i < dir)  quicksortRec(array, i, dir);
}
//=============================================================================
void quicksort(Pessoas *array, int n) {
    quicksortRec(array, 0, n-1);
}
void chamaQuick(Lista *l)
{
    quicksort(l->dados,l->qtd);
}
#endif // ESTATICA_H_INCLUDED
