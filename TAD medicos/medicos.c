#include <stdio.h>
#include <stdlib.h>
#include "medicos.h"
#include <string.h>

// Medico *addMedico(Medico *medico, ListaMedicos *lista)
// {
//     ListaMedicos *novo = (ListaMedicos *)malloc(sizeof(ListaMedicos));
//     if(novo == NULL){
//         printf("Memoria insuficiente \n");
//         exit(1);
//     }

//     novo->medico = medico;
//     novo->prox = lista;

//     return novo;
// }

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
    printf("Medico %s cadastrado com sucesso\n", medico->nome);
    escreverMedico(medico);

    return novo;
}

ListaMedicos *addMedicoArquivo(char *nome, char *especialidade, char *paciente, char *disponibilidade, ListaMedicos *lista){
    ListaMedicos *novo = (ListaMedicos *)malloc(sizeof(ListaMedicos));
    if (novo == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    novo->medico = (Medico *)malloc(sizeof(Medico));
    if (novo->medico == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    strcpy(novo->medico->nome, nome);
    strcpy(novo->medico->especialidade, especialidade);
    strcpy(novo->medico->paciente, paciente);
    strcpy(novo->medico->disponibilidade, disponibilidade);
    novo->prox = lista;
    
    return novo;
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

void removeMedico(char *nome, ListaMedicos **lista)
{
    ListaMedicos *ant = NULL;
    ListaMedicos *p = *lista;

    while (p != NULL && strcmp(p->medico->nome, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }

    if (p != NULL)
    {
        if (ant == NULL)
        {
            *lista = p->prox;
        }
        else
        {
            ant->prox = p->prox;
        }
        free(p->medico);
        free(p);
    }
    else
    {
        printf("Medico nao encontrado\n");
    }
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

void escreverMedico(Medico *medico)
{   
    FILE *arq = fopen("CadClinica.txt", "a");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fprintf(arq, "Medico\nNome do Medico: %s\n", medico->nome);
    fprintf(arq, "Especialidade: %s\n", medico->especialidade);
    fprintf(arq, "Paciente: %s\n", medico->paciente);
    fprintf(arq, "Disponibilidade: %s\n", medico->disponibilidade);
    fprintf(arq, "\n");
    fclose(arq);
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