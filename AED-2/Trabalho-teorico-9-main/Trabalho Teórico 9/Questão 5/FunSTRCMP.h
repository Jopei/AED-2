#ifndef FUNSTRCMP_H_INCLUDED
#define FUNSTRCMP_H_INCLUDED

int FunSTRCMP(char *palavra,char *palavra2)
{//Função que verifica a diferenca entre o tamanho de dois vetores de caracteres
  //  caso sejam iguais seu retorno sera zero, cso a primeira seja menor que a segunda seu retorno e negativo, e seu terceiro caso seu retorno e positivo
    int a = Func_STRLEN(palavra);
    int b = Func_STRLEN(palavra2);
    if(a == b)
    {
        return 0;
    }else if(a > b)
    {
        return -1;
    }
    else

        return 1;

}

#endif // FUNSTRCMP_H_INCLUDED
