#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD medicos/medicos.c"
#include "TAD pacientes/pacientes.c"

int main(void)
{
    Medico *medico1 = addMedico("Dr. Joao", "Cardiologista", "Maria", "Segunda-feira");
    Medico *medico2 = addMedico("Dr. Pedro", "Ortopedista", "Jose", "Terca-feira");
    listMedicos(medico1);
    listMedicos(medico2);

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
    return 0;
}