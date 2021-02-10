#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pessoas.h"
//#include "estatica.h"
//#include "Ldupla.h""
#include "dinamica.h"
int menu()
{
    setlocale(LC_ALL,"portuguese");
    int opcao = 0;
    printf("\n-------Cadastro de Pessoas-------\n");
    printf("1 - Lista de Pessoas\n");
    printf("2 - Cadastrar uma nova Pessoa\n");
    printf("3 - Editar dados de uma Pessoa\n");
    printf("4 - Apagar uma Pessoa\n");
    printf("5 - Procurar Pessoa\n");
    printf("6 - Clonar lista\n");
    printf("7 - Maior em idade \n");
    printf("8 - Inverte\n");
    printf("9 - Concatenar\n");
    printf("10 - Ordena Seleçao\n");
    printf("11 - Ordena Quick\n");
    printf("0 - Sair\n");
    printf("Digite a opcao procurada: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(void)
{
    setlocale(LC_ALL,"portuguese");
    Lista cadastro,clone,conca;
    Pessoas paux;
    int op = 0, id,idade, auxid=1,max;
    char nome[50];
    create_lista(&cadastro,10);
    //create_lista(&cadastro);
    do
    {

        op = menu();

        switch(op)
        {

        case 1:
            print_lista(&cadastro);
            break;

        case 2:
            printf("Digite o nome:\n");
            scanf(" %[^\n]s\n",nome);
            fflush(stdin);
            printf("Digite a idade:\n");
            scanf("%i",&idade);
            paux = novaPessoa(nome,idade,&auxid);
            add_lista(&cadastro, paux);
            break;

        case 3:
            printf("\nDigite o codigo do usuário: ");
            scanf("%d", &id);
            editar(&cadastro,id);
            break;

        case 4:
            printf("\nDigite o codigo do usuário: ");
            scanf("%d", &id);
            delete_lista(&cadastro, id);
            break;

        case 5:
            printf("Escreva o nome da pessoa procurada: ");
            scanf(" %[^\n]s\n",nome);
            fflush(stdin);
            printf("%i\n",print_procurada(&cadastro,&nome));
            break;

        case 6:
            create_lista(&clone,10);
            //create_lista(&clone)
            FunClone(&cadastro,&clone);
            printf("Lista Normal:\n");
            print_lista(&cadastro);
            printf("Lista Clone:\n");
            print_lista(&clone);
            break;

        case 7:
            printf("Maior idade: %i",Maior(&cadastro));
            break;
        case 8:
            create_lista(&clone,10);
            Inverte(&cadastro,&clone);
            break;
        case 9:
            create_lista(&conca,20);
            create_lista(&clone,10);
            FunClone(&cadastro,&clone);
            concatenar(&cadastro,&clone,&conca);
            break;
        case 10:
            Ordenar(&cadastro);
            break;
        case 11:
            chamaQuick(&cadastro);//Estatico
            break;
        }
    }
    while(op != 0);

    return 0;
}
