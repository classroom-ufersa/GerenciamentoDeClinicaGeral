#ifndef MEDICOS_H
#define MEDICOS_H

typedef struct medico
{
    char nome[50];
    char especialidade[50];
    char paciente[50];
    char disponibilidade[50];
}Medico;

typedef struct listaMedicos ListaMedicos;
struct listaMedicos
{
    Medico *medico;
    ListaMedicos *prox;
};

/* Função para remover um médico da lista */
void removeMedico(char *nome, ListaMedicos **lista);

/* Função para listar os médicos */
void listMedico(ListaMedicos *lista);

/* Função para criar uma lista de médicos */
ListaMedicos *criaListaMedicos(void);

/* Função para adicionar um médico à lista */
ListaMedicos *addMedicoLista(Medico *medico, ListaMedicos *lista);

/* Função para preencher os dados de um médico */
Medico *preencheMedico(void);

/* Função para verificar se a lista de médicos está vazia */
int lst_vaziaMedicos(ListaMedicos *l);

void escreverMedico(Medico *medico);

ListaMedicos *addMedicoArquivo(char *nome, char *especialidade, char *paciente, char *disponibilidade, ListaMedicos *lista);

#endif /* MEDICOS_H */