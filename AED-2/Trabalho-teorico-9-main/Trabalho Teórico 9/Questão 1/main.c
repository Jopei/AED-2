#include <stdio.h>
#include <stdlib.h>
int main()
{
    int e = 20;
    int *p ,*q;
    int i;
    //p = &i;//Funciona
    //p = *&i;//Funciona mas retorna em Hexadecimal
    //p = &*i;//Não funciona
    //i = *&*p;//Funciona como ponteiro do ponteiro
    //i = *&p;//Funciona apontando para p
    //i = &*p;//Funciona e aponta o valor dentro de P
    //p = &*&i;//Funciona apontando o enderenço de memoria de i
    //q = *&*p;//Funciona apontando para p
    //q = **&p;//Não imprime
    //q = *&p;//Imprime em hexadecimal o valor de  p
    //q = &*p;//Imprime em hexadecimal o valor de  p
    printf("%p",p);
    //printf("%p",q);
    //printf("%d",i);
    return 0;
}
