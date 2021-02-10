#ifndef ESTATICA_H_INCLUDED
#define ESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
//==================================================
typedef struct Pilha{
  char dados[MAX];
  int topo;
}Pilha;
//==================================================
void create_pilha(Pilha *p){
  p->topo = 0;
}
//==================================================
bool push(Pilha *p, char dado){

  if(p->topo == MAX){
    //printf("\nPilha Cheia!\n");
    return false;
  }

  p->dados[p->topo] = dado;
  p->topo++;
  return true;
}

//==================================================
char pop(Pilha *p){

  if(p->topo == 0){
    return -1;
  }

  p->topo--;
  return p->dados[p->topo];
}
//==================================================
void print_pilha(Pilha *p){

  printf("\nTamanho: %i\n", p->topo);
  for(int i=p->topo-1; i>=0; i--)
    printf("%c\n", p->dados[i]);

}
//==================================================
bool is_empty(Pilha *p){
  return p->topo == 0;
}
void BolhaPilha(Pilha *p)
{
    for(int i=0; i<p->topo-1;i++){
    int tmp = p->topo;
    for(int j=0; j<p->topo-i-1;j++){
      if(p->dados[tmp] > p->dados[j]){
        char aux = p->dados[j];
        p->dados[j] = p->dados[tmp];
        p->dados[tmp] = aux;
      }
      tmp--;
    }
  }
}
/*void swap(int *i, int *j) {
   int temp = *i;
   *i = *j;
   *j = temp;
}
void ordenaBolha(Pilha *p)
{
    int i, j;
    for (i = 0; i < p->topo; i++) {
      for (j = 0; j < p->topo - i; j++) {
         if (array[j] > array[j + 1]) {
            swap(&array[j], &array[j + 1]);
}*/
//==================================================
#endif // ESTATICA_H_INCLUDED
