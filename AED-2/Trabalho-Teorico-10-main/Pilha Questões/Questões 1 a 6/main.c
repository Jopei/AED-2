#include <stdio.h>
#include "estatica.h"
//#include "dinamica.h"
//===========================================
//Procedimentos e funções escritas na no main c tem seu funcionamento de igual maneira para a Pilha dinamica e estatica
void RetiraImpares(Pilha *original){

  Pilha pilha_aux;
  create_pilha(&pilha_aux);

  while(!is_empty(original)){
    int d = pop(original);
    if(d%2 == 0)
      push(&pilha_aux, d);
  }

  while(!is_empty(&pilha_aux)){
    int d = pop(&pilha_aux);
    push(original, d);
  }
}


//===========================================
Pilha inverter(Pilha *p)
{
    //Procedimento que copia o conteudo do ultimo pop da pilha para uma variavel auxiliar que nesta copia o recebe invertido
   char aux;
    Pilha recebe;
    create_pilha(&recebe);
    aux = pop(p);
    while(aux != -1)
    {
        push(&recebe,aux);
        aux = pop(p);
    }
    return recebe;
}
void clonar(Pilha *p,Pilha *c)
{  //O procedimento cria uma pilha auxiliar que recebe o valor invetido do conteudo original da pilha depois o devolve na pilha original e em sua clone
    char aux;
    Pilha recebe;
    create_pilha(&recebe);
    aux = pop(p);
    while(aux != -1)
    {
        push(&recebe,aux);
        aux = pop(p);
    }
    aux = pop(&recebe);
    while(aux != -1)
    {
        push(c,aux);
        push(p,aux);
        aux = pop(&recebe);
    }
}
Pilha concatenar(Pilha *p,Pilha *c)
{
    /*Funcao que recebe como entrada
    A pilha original e sua copia e por meio de variaveis auxiliares
    concatena ambas em uma nova pilha
    */
    char aux;
    Pilha recebe, cc;
    create_pilha(&recebe);
    create_pilha(&cc);
    clonar(p,&cc);
    aux = pop(c);
    while(aux != -1)
    {
        push(&recebe,aux);
        aux = pop(c);
    }
    aux = pop(&recebe);
    while(aux != -1)
    {
        push(&cc,aux);
        push(&c,aux);
        aux = pop(&recebe);
    }

    return cc;
}
int menu()
{

    int opcao = -1;
    printf("\n====> ESTOQUE DE PRODUTOS <=====\n");
    printf("1 - Listar\n");
    printf("2 - Adicionar \n");
    printf("3 - Clonar\n");
    printf("4 - Concatenar\n");
    printf("5 - Inverte\n");
    printf("6 - Ordenar\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}

int main(void)
{
    int op = -1;
    //criando as pilhas utilizadas no exercicios
    Pilha p, c, cc;
    int aux;
    char letra;
    create_pilha(&p);
    fflush(stdin);
    do
    {

        op = menu();

        switch(op)
        {
        //chamada de função escolida pelo usuario
        case 1:
            print_pilha(&p);
            break;

        case 2:
            printf("Digite a Letra: ");
            fflush(stdin);
            scanf("%c",&letra);
            push(&p,letra);
            break;

        case 3:
            create_pilha(&c);
            clonar(&p,&c);
            printf("Pilha clone: ");
            print_pilha(&c);
            break;

        case 4:
            //clonar(&p,&c);
            create_pilha(&cc);
            printf("Pilha concatenada");
            cc = concatenar(&p,&c);
            print_pilha(&cc);
            break;
        case 5:
            p = inverter(&p);
            print_pilha(&p);
            break;
        case 6:
            BolhaPilha(&p);
            break;
        }
    }
    while(op != 0);
    return 0;
}
