#include <stdio.h>
#include <stdlib.h>
#include "medicos.h"
#include <string.h>

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

ListaMedicos *inserirOrdenadoMedico(ListaMedicos **lista, Medico *novoMedico)
{
    ListaMedicos *novo = (ListaMedicos *)malloc(sizeof(ListaMedicos));
    if (novo == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }

    novo->medico = novoMedico;

    if (*lista == NULL || strcmp((*lista)->medico->nome, novoMedico->nome) > 0)
    {
        novo->prox = *lista;
        *lista = novo;
        return *lista;
    }

    ListaMedicos *ant = *lista;
    ListaMedicos *p = (*lista)->prox;

    while (p != NULL && strcmp(p->medico->nome, novoMedico->nome) < 0)
    {
        ant = p;
        p = p->prox;
    }

    novo->prox = p;
    ant->prox = novo;

    return *lista;
}

ListaMedicos *addMedicoArquivo(char *nome, char *especialidade, char *paciente, char *disponibilidade, ListaMedicos **lista)
{   
    Medico *novoMedico = (Medico *)malloc(sizeof(Medico));
    if (novoMedico == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }

    strcpy(novoMedico->nome, nome);
    strcpy(novoMedico->especialidade, especialidade);
    strcpy(novoMedico->paciente, paciente);
    strcpy(novoMedico->disponibilidade, disponibilidade);

    inserirOrdenadoMedico(lista, novoMedico);

    return *lista;
}

void listMedico(ListaMedicos *lista)
{

    ListaMedicos *p = lista;

    while (p != NULL)
    {
        printf("Nome: %s\n", p->medico->nome);
        printf("Especialidade: %s\n", p->medico->especialidade);
        printf("Paciente: %s\n", p->medico->paciente);
        printf("Disponibilidade: %s\n", p->medico->disponibilidade);
        printf("\n");
        p = p->prox;
    }
}

void removeMedico(ListaMedicos **lista)
{
    if(lst_vaziaMedicos(*lista) == 1)
    {
        printf("Lista vazia\n");
        return;
    }

    char nome[50];

    printf("Digite o nome do medico que deseja remover: ");
    scanf(" %[^\n]", nome);

    ListaMedicos *ant = NULL;
    ListaMedicos *p = *lista;

    while (p != NULL && strcmp(p->medico->nome, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }
    if(p == NULL)
    {
        printf("Medico nao encontrado\n");
        return;
    }
    if (ant == NULL)
    {
        *lista = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    free(p);
    printf("Medico %s removido com sucesso\n", nome);

    reescreverArquivoMedicos(*lista);

}

int lst_vaziaMedicos(ListaMedicos *l)
{
    if (l == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void listMedicos(ListaMedicos *lista)
{

    if (lst_vaziaMedicos(lista) == 1)
    {
        printf("Lista vazia\n");
        return;
    }

    ListaMedicos *p = lista;

    while (p != NULL)
    {
        printf("Nome: %s\n", p->medico->nome);
        printf("Especialidade: %s\n", p->medico->especialidade);
        printf("Paciente: %s\n", p->medico->paciente);
        printf("Disponibilidade: %s\n", p->medico->disponibilidade);
        printf("\n");
        p = p->prox;
    }
}

void reescreverArquivoMedicos(ListaMedicos *lista)
{
    FILE *arquivo = fopen("CadClinica.txt", "a+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para reescrita\n");
        return;
    }

    while (lista != NULL)
    {
        fprintf(arquivo, "Medico\nNome do Medico: %s\n", lista->medico->nome);
        fprintf(arquivo, "Especialidade: %s\n", lista->medico->especialidade);
        fprintf(arquivo, "Paciente: %s\n", lista->medico->paciente);
        fprintf(arquivo, "Disponibilidade: %s\n\n", lista->medico->disponibilidade);
        lista = lista->prox;
    }

    fclose(arquivo);
}

void lstLiberaMedicos(ListaMedicos *l)
{
    ListaMedicos *p = l;
    ListaMedicos *t;

    while (p != NULL)
    {
        t = p->prox;
        free(p->medico);
        free(p);
        p = t;
    }
}