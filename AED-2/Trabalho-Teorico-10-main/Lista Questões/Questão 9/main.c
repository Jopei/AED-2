#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "paginas.h"
#include "FilaWeb.h"
//#include "estatica.h"
//#include "dinamica.h"
int menu()
{
    setlocale(LC_ALL,"portuguese");
    int opcao = 0;
    printf("\n-------Cadastro de Pessoas-------\n");
    printf("1 - Lista de Pessoas\n");
    printf("2 - Cadastrar uma nova Pessoa\n");
    printf("3 - Procurar site pelo nome\n");
    printf("Digite a opcao procurada: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(void)
{
    setlocale(LC_ALL,"portuguese");
    Lista cadastro;
    Pagina paux;
    int op = 0,auxid=1;
    char nome[50], link[50];
    create_lista(&cadastro);

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
            printf("Digite o link/url:\n");
            scanf(" %[^\n]s\n",link);
            fflush(stdin);
            paux = novaPagina(nome,link,&auxid);
            add_lista(&cadastro, paux);
            break;

        case 3:
            printf("Digite o nome do site procurado/n");
            scanf(" %[^\n]s\n",nome);
            Siteprocurado(&cadastro, nome);
            break;
        }
    }
    while(op != 0);

    return 0;
}



