#ifndef MEDICOS_H
#define MEDICOS_H

/* Definição da estrutura medico */
typedef struct medico Medico;

/* Definição da estrutura listaMedicos */
typedef struct listaMedicos ListaMedicos;

/* Função para adicionar um médico */
Medico *addMedico(char *nome, char *especialidade, char *paciente, char *disponibilidade);

/* Função para remover um médico da lista */
void removeMedico(char *nome, ListaMedicos **lista);

/* Função para listar os médicos */
void listMedicos(ListaMedicos *lista);

/* Função para criar uma lista de médicos */
ListaMedicos *criaListaMedicos(void);

/* Função para adicionar um médico à lista */
ListaMedicos *addMedicoLista(Medico *medico, ListaMedicos *lista);

/* Função para preencher os dados de um médico */
Medico *preencheMedico(void);

#endif /* MEDICOS_H */