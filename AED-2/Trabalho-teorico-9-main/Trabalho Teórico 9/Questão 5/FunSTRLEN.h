#ifndef FUNCAO_STRLEN_H_INCLUDED
#define FUNCAO_STRLEN_H_INCLUDED

int Func_STRLEN(const char *palavra)//Fun��o que desempnha o papel de descobrir o tamanho da variavel e retornala ela realizada isso com uma diferenca no espa�o de memoria de duas char's constantes
{
    const char *aux;
    for (aux = palavra; *aux; ++aux);
    return aux - palavra;
}

#endif // FUNCAO_STRLEN_H_INCLUDED
