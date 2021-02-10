#ifndef FILAWEB_H_INCLUDED
#define FILAWEB_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "paginas.h"
//===============================================
typedef struct Celula{
  Pagina dado;
  struct Celula *prox;
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

  l->inicio = tmp;
  l->fim = tmp;
  l->qtd = 0;
}

//===============================================

bool add_lista(Lista *l, Pagina p){

  Celula *nova = (Celula*)malloc(sizeof(Celula));

  if(nova == NULL){
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

void print_lista(Lista *l){

  Celula *tmp = l->inicio->prox;

  while(tmp != NULL){
    print_pessoas(tmp->dado);
    tmp = tmp->prox;
  }

}

//===============================================

bool update_lista(Lista *l, Pagina p){

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
    printf("\nProduto nao encontrado na lista!\n");
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

      free(tmp);
      l->qtd--;
      achou = true;
      break;

    }

  }

  if(achou)
    return true;
  else{
    printf("\nProduto nao encontrado na lista!\n");
    return false;
  }
void Siteprocurado(Lista *l,char nome[])
{

}
#endif // FILAWEB_H_INCLUDED
