#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct//Struct global desclarada
{
    int codigo;
    char descricao[50];
    float valor;
} produto;
void cadastrar(produto *tabela, int quantidade)
{
    setlocale(LC_ALL,"portuguese");
    (tabela+quantidade)->codigo = quantidade+1; //Cadastro automatico de codigo feito com pointeiros
    printf("Digite a descrição: \n");
    scanf("%s",(tabela+quantidade)->descricao);//Cadastro informado pelo usuario
    fflush(stdin);
    printf("Valor: \n");
    scanf("%f",&(tabela+quantidade)->valor);//Cadastro de valor
}
void editar(produto *tabela, int quantidade)
{
    setlocale(LC_ALL,"portuguese");//Biblioteca que permite o uso de acentos e linguagem portugesa
    int codigitado = 0,aux;
    printf("Porfavor coloque o codigo do produto a ser editado:\n");
    scanf("%i",&codigitado);
    for(int i = 0; i< quantidade; i++)
    {
        if(codigitado == (tabela+i)->codigo )
        {
            printf("Qual deseja mudar?\n1.Descrição\n2.Valor\n3.Ambos\n");
            scanf("%i",&aux);
            if(aux == 1)
            {
                printf("Coloque uma nova descrição: \n");
                scanf("%s",(tabela+i)->descricao);//Sobreinscrição da descrição forecida anteriormente
                fflush(stdin);
                printf("Alteração realizada\n");
            }
            else if(aux==2)
            {
                printf("Coloque um novo valor: \n");
                scanf("%f",&(tabela+i)->valor);//Sobreescriçãono valor anteriormente
                printf("Alteração realizada\n");
            }
            else if(aux == 3)
            {
                printf("Coloque uma nova descrição: \n");
                scanf("%s",(tabela+i)->descricao);
                fflush(stdin);
                printf("Coloque um novo valor: \n");
                scanf("%f",&(tabela+i)->valor);
                printf("Alteração realizada\n");
            }
            else
            {
                printf("Opção não encontrada\n");
            }
        }
        else
            printf("Codigo não encontrado\nPor favor verifique o codigo na opção do menu 4. Exibir todos os produtos cadastrados"); // codigo não encontado
    }
}
void exibir(produto *tabela, int quantidade)
{
    setlocale(LC_ALL,"portuguese");
    for(int i = 0; i < quantidade; i++)
    {
        printf("\n------------------------------------\n");
        printf("Codigo: %i\n",(tabela+i)->codigo);
        printf("Descrição: %s\n",(tabela+i)->descricao);
        printf("Valor: %0.2f\n",(tabela+i)->valor);
        printf("\n------------------------------------\n");

    }
}
void exibirtodos(int quantidade)
{
    printf("\n------------------------------------\n");
    printf("Total de produtos cadastrados: %i",quantidade);//Impressão da variavel onde fica salvo durante a execução a quantidade de produtos
    printf("\n------------------------------------\n");
}
void excluir(produto *tabela, int *quantidade)
{
    setlocale(LC_ALL,"portuguese");
    if(*quantidade == 1)
    {
        quantidade = 0;//com a mudança na quantidade o espaço onde o produto se encrotar nao e mais mostrada e tambem fica disponivel para uma sobreinscrição
        printf("O uníco produto cadastrado foi excluído");
    }
    else
    {
        int codigitado = 0;
        printf("Digite o codigo do produto a ser excluir:\n");
        scanf("%i",&codigitado);
        for(int i = 0; i< *quantidade; i++)
        {
            if(codigitado == (tabela+i)->codigo )
            {
                /*As funções dentro do "if" são semenhantes ao "swap" das funções de ordenação
                mas no codigo elas são usadas para mover o item a ser excluido para a ultima posição
                e assim fazendo ele não ser listado e podendo ser sobreescrito*/
                swapint((&(tabela+ *quantidade)->codigo),(&((tabela+i)->codigo)));
                swapChar((&((tabela+ *quantidade)->descricao)),(&((tabela+i)->descricao)));
                swapFloat((&((tabela+ *quantidade)->valor)),(&((tabela+i)->valor)));
                //superswaip(&((tabela+ *quantidade)->codigo),&((tabela+ *quantidade)->descricao),&((tabela+ *quantidade)->valor),&((tabela+i)->codigo),&((tabela+i)->descricao),&((tabela+i)->valor));
                *quantidade =  *quantidade - 1;
                printf("Item apagado\n");
            }
        }

    }
}
void swapChar(char *descultimo, char *desexcluir)
{
    char tmpchar[50];
    strcpy(tmpchar,descultimo);
    strcpy(descultimo,desexcluir);
    strcpy(desexcluir,tmpchar);
}
void swapint(int *codultimo, int *codexcluir)
{
    int temp = *codultimo;
    *codultimo = *codexcluir;
    *codexcluir = temp;
}
void swapFloat(float *valultimo, float *valexcluir)
{
    float tmpval = *valultimo;
    *valultimo = *valexcluir;
    *valexcluir = tmpval;
}
/*void superswaip(int *codigoult,char *descricaoult,float *valorult, int *codiexclur, char *desexcluir, float *valexcluir)
{
    int tmpint = *codigoult;
    char tmpchar[50];
    strcpy(tmpchar,descricaoult);
    float tmpfloat = *valorult;
    *codigoult = *codiexclur;
    strcpy(descricaoult,desexcluir);
    *valorult = *valexcluir;
    *codiexclur = tmpint;
    strcpy(desexcluir,tmpchar);
    *valexcluir = tmpfloat;
}*/
void menu(produto *tabela, int quantidade,int n)
{
    setlocale(LC_ALL,"portuguese");
    int opc=-1;
    do
    {

        printf("\n\tEsconha a operação\n\n");
        printf("1. Cadastrar um novo produto \n");
        printf("2. Editar os dados de um produto\n");
        printf("3. Excluir um produto \n");
        printf("4. Exibir todos os produtos cadastrados\n");
        printf("5. Exibir a quantidade total de produtos\n");
        printf("0. Sair\n");
        scanf("%d", &opc);
        system("cls || clear");//utilizado para limpar a tela assim que uma nova parte do codigo e ativada
        switch(opc)
        {
        case 1:
            if(quantidade == n)
            {
                printf("Lista cheia não há como cadastrar novos produtos");
            }
            else
            {
                cadastrar(tabela,quantidade);
                quantidade++;
            }
            break;
        case 2:
            editar(tabela,quantidade);
            break;
        case 3:
            excluir(tabela,&quantidade);
            break;
        case 4:
            exibir(tabela,quantidade);
            break;
        case 5:
            exibirtodos(quantidade);
            break;
        case 0:
            break;

        default:
            printf("Erro digite um valor entre os indicados \n");
        }
    }
    while(opc !=0);
}

int main()
{
    int n, quantidade = 0;
    printf("Digite a quantidade de produtos: ");
    scanf("%i", &n);
    produto *tabela = malloc(n * sizeof(produto));//Criação do vetor de forma dinamica
    menu(tabela,quantidade,n);
    free(tabela);
    return 0;
}
