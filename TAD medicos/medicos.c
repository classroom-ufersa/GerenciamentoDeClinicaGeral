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

void listMedicos(Medico *medico)
{
    printf("Nome: %s\n", medico->nome);
    printf("Especialidade: %s\n", medico->especialidade);
    printf("Paciente: %s\n", medico->paciente);
    printf("Disponibilidade: %s\n", medico->disponibilidade);
}
