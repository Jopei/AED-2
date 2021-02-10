#include <stdio.h>
#include <stdlib.h>
#include "Processo.h"
//#include "Filaestatica.h"
#include "Filadinamica.h"
//procedimento utilizado tanto na fila dinamica quanto estatico para descobrir o maior atraves de uma struct auxiliar
//que é comparada com uma variavel para decobrir o maior depois o printa
Fila Maiortempo(Fila *f)
{
    int maior = 0;
    Processo *aux = (Processo *)malloc(f->tam * sizeof(Processo));;
    int j = f->tam,i;
    for(i = 0; i < j; i++)
    {
        aux[i] = dequeue(f);
        if(aux[i].tempo > maior)
        {
            maior = aux[i].tempo;
        }
    }
    for(i = 0; i < j; i++)
    {
        if(aux[i].tempo == maior)
        {
           printf("Foi chamado o Processo\nid: %i\nnome: %s \nTempo de espera: %i horas\n",aux[i].id,aux[i].nome,aux[i].tempo);
        }
    }
    for(i = 0; i < j; i++)
    {
        if(aux[i].tempo != maior)
        {
            enqueue(f,aux[i]);
        }
    }
    return *f;
}
int menu()
{

    int opcao;
    printf("\n =====> FILA DE ATENDIMENTO <===== \n");
    printf("1 - Entrar na fila\n");
    printf("2 - Verificar a fila\n");
    printf("3 - Chamar o Maior tempo\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);

    return opcao;
}

int main(void)
{

    int op, x, aux = 1;
    Fila fila;
    char buffer;
    Processo paux;
    create_fila(&fila);

    do
    {
        //system("clear");//system("cls");
        op = menu();

        switch(op)
        {
        case 1:
            paux =novo_processo(&aux);
            enqueue(&fila, paux);
            aux++;
            break;
        case 2:
            print_fila(&fila);
            break;
        case 3:
            fila = Maiortempo(&fila);
            break;
        }

    }
    while(op!=0);

    //system("PAUSE");


    return 0;
}
