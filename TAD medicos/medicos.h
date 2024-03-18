#include "TAD pacientes/pacientes.c"


/* TAD: Define um medico*/
typedef struct medico Medico;

/* TAD: Define uma lista de medicos*/
typedef struct lista Lista;

/* Funcao para criar uma lista 
    de medicos*/
Lista *criaListaMedicos(void);

/* Funcao para verificar se a lista de medicos esta vazia
    Recebe uma lista de medicos
    Retorna 1 se a lista estiver vazia e 0 caso contrario
*/
int lst_vazia(Lista *l);


/* Funcao para adicionar medico
   Recebe um nome, especialidade, paciente e disponibilidade de horario
 */

Medico *addMedico(char *nome, char *especialidade, char *paciente, char *disponibilidade);

/*  Funcao para remover medico
    Recebe um medico
 */
void removeMedico(Medico *medico);

/*  funcao que lista medicos e seus respectivos clientes
    recebe um medico
    retorna a lista de medicos e seus respectivos clientes
*/
void listMedicos(Medico *medico);
