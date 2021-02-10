#ifndef PESSOAS_H_INCLUDED
#define PESSOAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//====================================
typedef struct Pessoas
{
    int id;
    char nome[50];
    int idade;
} Pessoas;
//====================================
void print_pessoas(Pessoas p)
{
    printf("--------------\nid: %d\nnome: %s\nidade: %i\n--------------\n",p.id,p.nome, p.idade);
}
Pessoas novaPessoa(char nome[],int idade, int *idaux)
{

    Pessoas p;
    p.id = *idaux;
    strcpy(p.nome,nome);
    p.idade = idade;
    *idaux = *idaux + 1;
    return p;
}
#endif // PESSOAS_H_INCLUDED
