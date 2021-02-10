#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
//=====================================
typedef struct Pessoa{
  int id;
  char nome[100];
  int idade;
}Pessoa;
//=====================================
void print_pessoa(Pessoa p){
  printf("id: %d,nome: %s,idade: %d\n", p.id, p.nome, p.idade);
}
//=====================================
//O procedimento ja recebe o id das pessoa de forma ordenada
Pessoa novaPessoa(char nome[],int idade, int *idaux)
{

    Pessoa p;
    p.id = *idaux;
    strcpy(p.nome,nome);
    p.idade = idade;
    *idaux = *idaux + 1;
    return p;
}
//=====================================
Pessoa invalida_pessoa(){
  Pessoa p;

  p.id = -1;
  sprintf(p.nome,"Pessoa: %d", p.id);
  p.idade = 0;

  return p;
}



//=====================================
#endif // PESSOA_H_INCLUDED
