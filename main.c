#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD medicos/medicos.c"
#include "TAD pacientes/pacientes.c"

int main(void)
{
    Lista *lista = criaLista();
    Paciente *paciente1 = preenchePaciente();
    Paciente *paciente2 = preenchePaciente();
    Paciente *paciente3 = preenchePaciente();
    lista = addPaciente(paciente1, lista);
    lista = addPaciente(paciente2, lista);
    lista = addPaciente(paciente3, lista);
    listPacientes(lista);
    removePaciente(&lista);
    listPacientes(lista);
    editPaciente(lista);
    listPacientes(lista);
    buscaPaciente(lista);

    return 0;
}