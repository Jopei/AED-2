#ifndef PREECHERALETORIOSOMA_H_INCLUDED
#define PREECHERALETORIOSOMA_H_INCLUDED

void PreecherAletoriosoma(int **mat,int *col, int *lin)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*(mat+ i) + j) = rand() % 100;//preenchimento da matriz de forma aleatoria de 1 a 99

        }
    }
    for(int i=0; i<lin; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
    int soma= Somar(mat,col,lin);
    printf("Total soma: %i",soma);
}
int Somar(int **mat,int *col, int *lin)
{
    int soma=0;
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            soma += *(*(mat+ i) + j);//laço utilizado para fazer a soma

        }
    }
    return soma;
}
#endif // PREECHERALETORIOSOMA_H_INCLUDED
