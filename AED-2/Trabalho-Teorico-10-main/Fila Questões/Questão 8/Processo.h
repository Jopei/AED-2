#ifndef PROCESSO_H_INCLUDED
#define PROCESSO_H_INCLUDED

typedef struct Processo
{
    int id;
    char nome[100];
    int tempo;
} Processo;

void print_processo(Processo p)
{
    printf("id: %d,Nome do Processo: %s,Tempo de espera %d horas\n", p.id, p.nome, p.tempo);
}
Processo novo_processo(int *idaux)
{
    Processo p;
    p.id = *idaux;
    printf("Digite o nome do processo: ");
    scanf("%s", p.nome);
    fflush(stdin);
    printf("Digite o tempo de espera do processo: ");
    scanf("%i", &p.tempo);
    return p;
}
Processo tirar_processo()
{
    Processo p;
    p.id = -1;
    sprintf(p.nome, "Pessoa: %d", p.id);
    p.tempo = 0;

    return p;
}

#endif // PROCESSO_H_INCLUDED
