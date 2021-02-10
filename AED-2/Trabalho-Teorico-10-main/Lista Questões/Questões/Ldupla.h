#ifndef LDUPLA_H_INCLUDED
#define LDUPLA_H_INCLUDED
//===============================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pessoas.h"
//===============================================
typedef struct Celula{
  Pessoas dado;
  struct Celula *prox;
  struct Celula *ant;
}Celula;
//===============================================
typedef struct Lista{
  Celula *inicio;
  Celula *fim;
  int qtd;
}Lista;
//===============================================
void create_lista(Lista *l){

  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->prox = NULL;
  tmp->ant = NULL;

  l->inicio = tmp;
  l->fim = tmp;
  l->qtd = 0;
}

//===============================================

bool add_lista(Lista *l, Pessoas p){

  Celula *nova = (Celula*)malloc(sizeof(Celula));

  if(nova == NULL){
    printf("\nLista Cheia!\n");
    return false;
  }

  nova->dado = p;
  nova->prox = NULL;

  l->fim->prox = nova;
  nova->ant = l->fim;
  l->fim = nova;
  l->qtd++;

  return true;
}

void print_lista(Lista *l){

  Celula *tmp = l->inicio->prox;

  while(tmp != NULL){
    print_pessoas(tmp->dado);
    tmp = tmp->prox;
  }

}

void print_lista_invertida(Lista *l){

  Celula *tmp = l->fim;

  while(tmp->ant != NULL){
    print_pessoas(tmp->dado);
    tmp = tmp->ant;
  }

}

//===============================================

bool update_lista(Lista *l, Pessoas p){

  bool achou = false;

  for(Celula *tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox){

    if(tmp->dado.id == p.id){
      tmp->dado = p;
      achou = true;
      break;
    }

  }

  if(achou)
    return true;
  else{
    printf("\nPessoas nao encontrado na lista!\n");
    return false;
  }


}
//===============================================
bool delete_lista(Lista *l, int id){

  bool achou = false;
  Celula *ant, *tmp;

  for(ant = l->inicio,tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox, ant=ant->prox){

    if(tmp->dado.id == id){

      ant->prox = tmp->prox;

      if(tmp->prox == NULL)
        l->fim = ant;
      else
        tmp->prox->ant = ant;

      free(tmp);
      l->qtd--;
      achou = true;
      break;

    }

  }

  if(achou)
    return true;
  else{
    printf("\nPessoa nao encontrado na lista!\n");
    return false;
  }



}
void editar(Lista *l,int n)//Procedimento que subscreve os dados ja cadastrados
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
//===============================================



#endif // LDUPLA_H_INCLUDED
