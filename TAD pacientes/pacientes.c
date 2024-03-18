#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

struct paciente
{
    char nome[50];
    int idade;
    char doenca[50];
};


struct lista
{
    Paciente *paciente;
    Lista *prox;
};


Paciente *preenchePaciente(void)
{
    Paciente *paciente = (Paciente *)malloc(sizeof(Paciente));
    if (paciente == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", paciente->nome);
    printf("Digite a idade do paciente: ");
    scanf(" %d", &paciente->idade);
    printf("Digite a doenca do paciente: ");
    scanf(" %[^\n]", paciente->doenca);
    return paciente;
}


Lista *criaLista(void)
{
    return NULL;
}


int lst_vazia(Lista *l)
{
    return (l == NULL);
}


Lista *addPaciente(Paciente *paciente, Lista *lista)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    novo->paciente = paciente;
    novo->prox = lista;
    return novo;
}


void removePaciente(Lista *lista)
{   if(!lst_vazia(lista)){

    char nome[50];

    printf("\n Informe o nome do paciente que deseja remover: ");
    scanf(" %[^\n]", nome);

    if(lista->prox->paciente->nome == nome){
        lista->prox = lista->prox->prox;
    }

    Lista *ant = NULL;
    Lista *p = lista;
    while (p != NULL && strcmp(p->paciente->nome, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Paciente nao encontrado \n");
        return;
    }
    if (ant == NULL)
    {
        lista = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    free(p);
}
else{
    printf("Lista vazia\n");
}
}

void editPaciente(Lista *lista){
    char nome[50];
    int idade;
    char doenca[50];

    printf("\n Informe o nome do paciente que deseja editar: ");
    scanf(" %[^\n]", nome);

    Lista *ant = NULL;
    Lista *p = lista;
    while (p != NULL && strcmp(p->paciente->nome, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Paciente nao encontrado \n");
        return;
    }
    printf("Digite o novo nome do paciente: ");
    scanf(" %[^\n]", p->paciente->nome);
    printf("Digite a nova idade do paciente: ");
    scanf(" %d", &p->paciente->idade);
    printf("Digite a nova doenca do paciente: ");
    scanf(" %[^\n]", p->paciente->doenca);
}

void listPacientes(Lista *lista)
{
    Lista *p;
    for (p = lista; p != NULL; p = p->prox)
    {
        printf("Nome: %s\n", p->paciente->nome);
        printf("Idade: %d\n", p->paciente->idade);
        printf("Doenca: %s\n", p->paciente->doenca);
    }
}
