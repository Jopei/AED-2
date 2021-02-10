#ifndef FUNSTRCAT_H_INCLUDED
#define FUNSTRCAT_H_INCLUDED

int Func_STRCAT(char *palavra, char *palavra2)//Função que copia o segundo vetor para o primeiro, isto e ralizado ao saber o final do primerio vetor
{
    int i=0;
    for( i = 0; palavra[i] != '\0'; i++);
    for(int j = 0;palavra2[j] != '\0';j++)
    {
        palavra[i] = palavra2[j];
        i++;
    }
    palavra[i] = '\0';
    return *palavra;
}

#endif // FUNSTRCAT_H_INCLUDED
