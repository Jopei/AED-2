#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void Menu()
{ //menu principal que chamar as fontes c(codigos auxiliares)
    setlocale(LC_ALL,"portuguese");
    int opc=-1;
    do
    {
        printf("\n\tEsconha a questão\n\n");
        printf("1. Questão 1(Strlen)\n");
        printf("2. Questão 2(Strcmp)\n");
        printf("3. Questão 3(Strcat)\n");
        printf("4. Questão 4(Strchr)\n");
        printf("0. Sair\n");

        scanf("%d", &opc);
        system("cls || clear");

        switch(opc)
        {
        case 1:
            LetraA();
            break;

        case 2:
            LetraB();
            break;

        case 3:
            LetraC();
            break;

        case 4:
            LetraD();
            break;
        case 0:
            break;

        default:
            printf("Digite uma opcao valida\n");
        }
    }
    while(opc !=0);
}

int main()
{
    Menu();
    return 0;
}
