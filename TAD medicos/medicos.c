#include <stdio.h>
#include <stdlib.h>
#include "medicos.h"
#include <string.h>

struct medico
{
    char nome[50];
    char especialidade[50];
    char paciente[50];
    char disponibilidade[50];
};

struct listaMedicos
{
    Medico *medico;
    ListaMedicos *prox;
};

Medico *addMedico(char *nome, char *especialidade, char *paciente, char *disponibilidade)
{
    Medico *medico = (Medico *)malloc(sizeof(Medico));
    if (medico == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    strcpy(medico->nome, nome);
    strcpy(medico->especialidade, especialidade);
    strcpy(medico->paciente, paciente);
    strcpy(medico->disponibilidade, disponibilidade);
    return medico;
}


Medico *preencheMedico(void)
{
    Medico *medico = (Medico *)malloc(sizeof(Medico));
    if (medico == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    printf("Digite o nome do medico: ");
    scanf(" %[^\n]", medico->nome);
    printf("Digite a especialidade do medico: ");
    scanf(" %[^\n]", medico->especialidade);
    printf("Digite o paciente do medico: ");
    scanf(" %[^\n]", medico->paciente);
    printf("Digite a disponibilidade do medico: ");
    scanf(" %[^\n]", medico->disponibilidade);
    return medico;
}

ListaMedicos *criaListaMedicos(void)
{
    return NULL;
}

ListaMedicos *addMedicoLista(Medico *medico, ListaMedicos *lista)
{
    ListaMedicos *novo = (ListaMedicos *)malloc(sizeof(ListaMedicos));
    if (novo == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    novo->medico = medico;
    novo->prox = lista;
    return novo;
}

void removeMedico(char *nome, ListaMedicos **lista) {
    ListaMedicos *ant = NULL;
    ListaMedicos *p = *lista;

    while (p != NULL && strcmp(p->medico->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }

    if (p != NULL) {
        if (ant == NULL) {
            *lista = p->prox;
        } else {
            ant->prox = p->prox;
        }
        free(p->medico); 
        free(p); 
    } else {
        printf("Medico nao encontrado\n");
    }
}


void listMedicos(ListaMedicos *lista) {
    ListaMedicos *p = lista;

    while (p != NULL) {
        printf("Nome: %s\n", p->medico->nome);
        printf("Especialidade: %s\n", p->medico->especialidade);
        printf("Paciente: %s\n", p->medico->paciente);
        printf("Disponibilidade: %s\n", p->medico->disponibilidade);
        printf("\n"); 
        p = p->prox;
    }
}












