#ifndef PACIENTES_H
#define PACIENTES_H

#include "../sistema.c"

typedef struct paciente Paciente;

/* 
*/
Paciente preenchePaciente();
Paciente *insereNoFinalPaciente(Paciente *p, Paciente pnovo);
//Paciente *inserePacienteOrdenado(Paciente *p, Paciente pnovo);

void imprimePacientes(Paciente *p);

Paciente *removePaciente(Paciente *lista, char *nome);

Paciente *editarPaciente(Paciente *lista, char *nome);

Paciente *buscaPaciente(Paciente *lista, char *nome);

#endif // PACIENTES_H