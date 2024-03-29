#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

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
    
    printf("Paciente %s cadastrado com sucesso\n", paciente->nome);
    escreverPaciente(paciente);
    
    return novo;
}

void removePaciente(Lista **lista)
{
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

void reescreverArquivo(Lista *lista) {
    FILE *arquivo = fopen("CadClinica.txt", "w"); // Abrir o arquivo em modo de escrita, isso vai limpar o arquivo atual
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para reescrita\n");
        return;
    }

    while (lista != NULL) {
        fprintf(arquivo, "Nome do Paciente: %s\n", lista->paciente->nome);
        fprintf(arquivo, "Idade: %d\n", lista->paciente->idade);
        fprintf(arquivo, "Doenca: %s\n\n", lista->paciente->doenca);
        lista = lista->prox;
    }

    fclose(arquivo);
}

void removerPacienteDoArquivo(char *nome) {
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
        if (strstr(linha, nome)) {
            fgets(linha, sizeof(linha), arquivo); 
            fgets(linha, sizeof(linha), arquivo); 
        } else {
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
        switch(opc)
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

void escreverPaciente(Paciente *paciente)
{
    // abrir arquivo para escrita

    FILE *arquivo;
    arquivo = fopen("CadClinica.txt", "a");

    fprintf(arquivo, "Nome do Paciente: %s\nIdade: %d\nDoenca: %s\n \n", paciente->nome, paciente->idade, paciente->doenca);
    fclose(arquivo);
}

Lista *addPacienteArquivo(char *nome, char *doenca, int idade, Lista *lista)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }

    // Aloca memória para o paciente
    novo->paciente = (Paciente *)malloc(sizeof(Paciente));
    if (novo->paciente == NULL)
    {
        printf("Memoria insuficiente\n");
        free(novo);
        exit(1);
    }

    // Agora, copiamos os valores para o novo paciente diretamente
    strcpy(novo->paciente->nome, nome);
    strcpy(novo->paciente->doenca, doenca);
    novo->paciente->idade = idade;
    novo->prox = lista; // Faz o novo nó apontar para a cabeça atual da lista

    return novo; // Retorna a nova cabeça da lista
}

void lerArquivo(FILE *arquivo_client, Lista **listaPacientes)
{   
    char nome[50], doenca[50];
    int idade;

    while (fscanf(arquivo_client, " Nome do Paciente: %49[^\n]\nIdade: %d\nDoenca: %49[^\n]\n", nome, &idade, doenca) != EOF)
    {
        *listaPacientes = addPacienteArquivo(nome, doenca, idade, *listaPacientes);
        fscanf(arquivo_client, "\n");
    }
}
