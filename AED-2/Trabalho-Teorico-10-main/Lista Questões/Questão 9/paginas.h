#ifndef PAGINAS_H_INCLUDED
#define PAGINAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//====================================
typedef struct Pagina
{
    int id;
    char nome[50];
    char link;
} Pagina;
//====================================
void print_pessoas(Pagina p)
{
    printf("--------------\nnome: %s\nidade: %i\n--------------\n",p.nome, p.link);
}
Pagina novaPagina(char nome[],char link[], int *idaux)
{

    Pagina p;
    p.id = *idaux;
    strcpy(p.nome,nome);
    strcpy(p.link,link);
    *idaux = *idaux + 1;
    return p;
}

#endif // PAGINAS_H_INCLUDED
