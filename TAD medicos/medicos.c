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

ListaMedicos *addMedicoLista(Medico *medico, ListaMedicos *lista) {
    ListaMedicos *novo = (ListaMedicos *)malloc(sizeof(ListaMedicos));
    if (novo == NULL) {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    novo->medico = medico;
    novo->prox = lista;

    // Abrir o arquivo para escrita (append mode)
    FILE *arquivo = fopen("CadClinica.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo CadClinica.txt\n");
        exit(1);
    }

    // Escrever os detalhes do médico no arquivo
    fprintf(arquivo, "Medico: %s - Especialidade: %s - Disponibilidade: %s\n", medico->nome, medico->especialidade, medico->disponibilidade);
    // Se desejar, você pode adicionar mais detalhes do médico aqui

    // Escrever os detalhes do paciente associado ao médico no arquivo
    fprintf(arquivo, "Paciente: %s\n", medico->paciente);
    // Se desejar, você pode adicionar mais detalhes do paciente aqui

    // Fechar o arquivo
    fclose(arquivo);

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

        removerMedicoDoArquivo(p->medico->nome);
        
        free(p->medico); 
        free(p); 
    } else {
        printf("Medico nao encontrado\n");
    }
}

void removerMedicoDoArquivo(char *nome) {
    FILE *arquivoTemporario = fopen("temporario.txt", "w");
    if (arquivoTemporario == NULL) {
        printf("Erro ao abrir o arquivo temporario.txt\n");
        exit(1);
    }

    FILE *arquivo = fopen("CadClinica.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo CadClinica.txt\n");
        exit(1);
    }
        
    char linha[1000];
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (!strstr(linha, nome)) {
            fputs(linha, arquivoTemporario);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemporario);

    if (remove("CadClinica.txt") != 0) {
        printf("Erro ao remover o arquivo CadClinica.txt\n");
        exit(1);
    }

    if (rename("temporario.txt", "CadClinica.txt") != 0) {
        printf("Erro ao renomear o arquivo temporario.txt\n");
        exit(1);
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

