#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"
#include "../TAD medicos/medicos.h"

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
    if (l == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void lstLiberaPacientes(Lista *l)
{
    Lista *p = l;
    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

Lista *inserirLista(Lista **lista, Paciente *paciente)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    novo->paciente = paciente;
    novo->prox = NULL;

    Lista *ant = NULL;
    Lista *p = *lista;
    while (p != NULL && strcmp(p->paciente->nome, paciente->nome) < 0)
    {
        ant = p;
        p = p->prox;
    }
    if (ant == NULL)
    {
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return *lista;
}

void removePaciente(Lista **lista)
{   
    if (lst_vazia(*lista) == 1)
    {
        printf("Lista vazia\n");
        return;
    }

    char nomePaciente[50];

    printf("\nInforme o nome do paciente que deseja remover: ");
    scanf(" %[^\n]", nomePaciente);

    Lista *ant = NULL;
    Lista *p = *lista;
    while (p != NULL && strcmp(p->paciente->nome, nomePaciente) != 0)
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
        *lista = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    free(p);
    printf("Paciente %s removido com sucesso\n", nomePaciente);

    reescreverArquivo(*lista);
}

void reescreverArquivo(Lista *lista)
{
    FILE *arquivo = fopen("CadClinica.txt", "a+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para reescrita\n");
        return;
    }

    while (lista != NULL)
    {
        fprintf(arquivo, "Paciente\nNome do Paciente: %s\n", lista->paciente->nome);
        fprintf(arquivo, "Idade: %d\n", lista->paciente->idade);
        fprintf(arquivo, "Doenca: %s\n\n", lista->paciente->doenca);
        lista = lista->prox;
    }

    fclose(arquivo);
}

void escreverPaciente(Paciente *paciente)
{
    FILE *arquivo;
    arquivo = fopen("CadClinica.txt", "a");

    fprintf(arquivo, "Paciente\nNome do Paciente: %s\nIdade: %d\nDoenca: %s\n \n", paciente->nome, paciente->idade, paciente->doenca);
    fclose(arquivo);
}

void editPaciente(Lista *lista)
{
    if (lst_vazia(lista) == 1)
    {
        printf("Lista vazia\n");
        return;
    }
    char nome[50];
    int opc;
    printf("\nInforme o nome do paciente que deseja editar: ");
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
    printf("Paciente encontrado: \n");
    printf("Nome: %s\n", p->paciente->nome);
    printf("Idade: %d\n", p->paciente->idade);
    printf("Doenca: %s\n", p->paciente->doenca);
    do
    {
        printf("Escolha uma opcao: \n");
        printf("1 - Editar nome\n");
        printf("2 - Editar idade\n");
        printf("3 - Editar doenca\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf(" %d", &opc);
        switch (opc)
        {
        case 1:
            printf("Digite o novo nome do paciente: ");
            scanf(" %[^\n]", p->paciente->nome);
            printf("Nome alterado com sucesso\n");
            break;
        case 2:
            printf("Digite a nova idade do paciente: ");
            scanf(" %d", &p->paciente->idade);
            printf("Idade alterada com sucesso\n");
            break;
        case 3:
            printf("Digite a nova doenca do paciente: ");
            scanf(" %[^\n]", p->paciente->doenca);
            printf("Doenca alterada com sucesso\n");
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opc != 0);
    printf("Paciente editado com sucesso\n");
    printf("Nome: %s\n", p->paciente->nome);
    printf("Idade: %d\n", p->paciente->idade);
    printf("Doenca: %s\n", p->paciente->doenca);

    reescreverArquivo(lista);
}

void buscaPaciente(Lista *lista)
{
    Lista *p;
    char nome[50];

    if (lst_vazia(lista) == 1)
    {
        printf("Lista vazia\n");
        return;
    }

    printf("Buscando paciente\n");
    printf("Informe o nome do paciente: ");
    scanf(" %[^\n]", nome);

    for (p = lista; p != NULL; p = p->prox)
    {
        if (strcmp(p->paciente->nome, nome) == 0)
        {
            printf("Paciente encontrado: \n");
            printf("Nome: %s\n", p->paciente->nome);
            printf("Idade: %d\n", p->paciente->idade);
            printf("Doenca: %s\n", p->paciente->doenca);
            return;
        }
    }
    printf("Paciente nao encontrado \n");
}

void listPacientes(Lista *lista)
{
    if (lst_vazia(lista) == 1)
    {
        printf("Lista vazia\n");
        return;
    }

    Lista *p;
    for (p = lista; p != NULL; p = p->prox)
    {
        printf("Nome: %s\n", p->paciente->nome);
        printf("Idade: %d\n", p->paciente->idade);
        printf("Doenca: %s\n", p->paciente->doenca);
    }
}

Lista *addPacienteArquivo(char *nome, char *doenca, int idade, Lista **lista)
{   
    Paciente *novoPaciente = (Paciente *)malloc(sizeof(Paciente));
    if (novoPaciente == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }

    strcpy(novoPaciente->nome, nome);
    strcpy(novoPaciente->doenca, doenca);
    novoPaciente->idade = idade;

    inserirLista(lista, novoPaciente);

    return *lista;
}

void lerDados(FILE *arquivo, Lista **listaPacientes, ListaMedicos **listaMedicos)
{
    char buffer[256];

    char nome[50], doenca[50], especialidade[50], paciente[50], disponibilidade[50];
    int idade;

    while (fscanf(arquivo, "%s\n", buffer) != EOF)
    {
        if (strcmp(buffer, "Paciente") == 0)
        {
            fscanf(arquivo, "Nome do Paciente: %[^\n]\n", nome);
            fscanf(arquivo, "Idade: %d\n", &idade);
            fscanf(arquivo, "Doenca: %[^\n]\n\n", doenca);
            *listaPacientes = addPacienteArquivo(nome, doenca, idade, listaPacientes);
        }
        else if (strcmp(buffer, "Medico") == 0)
        {
            fscanf(arquivo, "Nome do Medico: %[^\n]\n", nome);
            fscanf(arquivo, "Especialidade: %[^\n]\n", especialidade);
            fscanf(arquivo, "Paciente: %[^\n]\n\n", paciente);
            fscanf(arquivo, "Disponibilidade: %[^\n]\n\n", disponibilidade);
            *listaMedicos = addMedicoArquivo(nome, especialidade, paciente, disponibilidade, listaMedicos);
        }
    }
}
