#ifndef FUNSTRCHR_H_INCLUDED
#define FUNSTRCHR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
char *Func_STRCHR(const char *palavra, int n)//função que encontra e retorna a primeira ocorrencia da lentra solicitada
{
    while (*palavra != (char) n) {
        if (!*palavra++) {
            return NULL;
        }
    }
    return (char *)palavra;
}

#endif // FUNSTRCHR_H_INCLUDED
