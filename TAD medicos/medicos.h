#ifndef MEDICOS_H
#define MEDICOS_H
#include "../TAD pacientes/pacientes.c"

typedef struct medico Medico;

Medico *cadastroPaciente(Medico *lista);
Medico *buscaMedico(Medico *lista, char *nome);
Medico preencheMedico();
Medico *insereOrdenado(Medico *lista, Medico m);
void imprimeMedicos(Medico *lista);
Medico *removePacienteDoMedico(Medico *lista);
Medico *editarPacientePorMedico(Medico *lista, char *nomeMedico, char *nomePaciente);
Medico *removeMedico(Medico *lista, char *nome);
void buscaPacientePorMedico(Medico *lista, char *nomeMedico, char *nomePaciente);

#endif // MEDICOS_H