#include <stdio.h>
#include <stdlib.h>
#include "estatica.h"
#include "pessoa.h"
//#include "Fdinamica.h"
#include "Mergeordena.h""
/*
FILA DE PESSOAS
PESSOA (ID, NOME, IDADE)
CRUD - criar, enfileirar, desenfileirar, tamanho, listar, destroy
*/
//Funções declarada no main tem seu funcionamento igual para Procediemntos dinamicos e estaticos
//A função abaixo e utilizado para concatenação ele utilizão a fila original e a fila cloner unindoas na pilha concatenada
Fila concatena(Fila *f, Fila *c, Fila *cc)
{
    Pessoa *aux = (Pessoa *)malloc(f->tam * sizeof(Pessoa));;
    int j = f->tam,h = c->tam,i;
    for(i = 0; i < j; i++)
    {
        aux[i] = dequeue(f);
    }
    for(; i< j+h; i++)
    {
        aux[i] = dequeue(c);
    }
    for(int y = 0; y < j+h; y++)
    {
        enqueue(cc,aux[y]);
    }
    return *cc;
}
//Processo utilizado para inverte a fila nela a fila e desfeita e sua informações são passada para uma pilha auxiliar  e retornão invetido para pilha
Fila inverte(Fila *f)
{
    Pessoa *aux = (Pessoa *)malloc(f->tam * sizeof(Pessoa));
    int i = 0, j = f->tam;
    for(int i = 0; i < j; i++)
    {
        aux[i] = dequeue(f);
    }
    for (int i = j - 1; i >= 0; i--)
    {
        enqueue(f, aux[i]);
    }
    return *f;
}
//No procedimento os valores da fila ~soa passados para uma auxiliar e são ordenados pelo metodo de seleção e retornão a fila
Fila Ordenar(Fila *f)
{
    int i = 0, j = f->tam;
    Pessoa *aux = (Pessoa *)malloc(f->tam * sizeof(Pessoa));
    for(int i = 0; i < j; i++)
    {
        aux[i] = dequeue(f);
    }
    selecao(aux,j);
    for(int i = 0; i < j; i++)
    {
        enqueue(f,aux[i]);
    }
    return *f;
}
//No procedimento abaixou e utilizado uma auxiliar prar pegar os elementos do vetor depois ele retornão e ainda são passado para uma fila clone
void clonar(Fila *f, Fila *c)
{
    Pessoa aux ;
    int i = 0, j = f->tam;
    for(int y = 0; y < j; y++)
    {
        aux = dequeue(f);
        enqueue(f,aux);
        enqueue(c,aux);
    }
}
int menu()
{

    int opcao;
    printf("\n =====> FILA DE ATENDIMENTO <===== \n");
    printf("1 - Entrar na fila\n");
    printf("2 - Verificar a fila\n");
    printf("3 - Chamar o próximo da fila\n");
    printf("4 - Inverter\n");
    printf("5 - Clonar\n");
    printf("6 - Concatenar\n");
    printf("7 - Ordenar\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);

    return opcao;
}

int main(void)
{

    int op, x, idade,auxid = 1;
    char nome[100];
    Fila fila, clone, cc;
    char buffer;
    Pessoa paux;
    create_fila(&fila);

    do
    {
        //system("clear");//system("cls");
        op = menu();

        switch(op)
        {
        case 1:
            printf("Digite o nome:\n");
            scanf(" %[^\n]s\n",nome);
            fflush(stdin);
            printf("Digite a idade:\n");
            scanf("%i",&idade);
            paux = novaPessoa(nome,idade,&auxid);
            enqueue(&fila, paux);
            break;
        case 2:
            print_fila(&fila);
            break;
        case 3:
            paux = dequeue(&fila);
            print_pessoa(paux);
            break;
        case 4:
            fila = inverte(&fila);
            print_fila(&fila);
            break;
        case 5:
            create_fila(&clone);
            clonar(&fila,&clone);
            print_fila(&clone);
            break;
        case 6 :
            create_fila(&cc);
            concatena(&fila,&clone,&cc);
            print_fila(&cc);
            break;
        case 7 :
            fila = Ordenar(&fila);
            break;
            }

    }
    while(op!=0);

    //system("PAUSE");


    return 0;
}
