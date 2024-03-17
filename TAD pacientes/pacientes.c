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



void removePaciente(Paciente *paciente){

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
