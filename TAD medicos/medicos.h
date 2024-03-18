/*TAD: Define a estrutura medico*/
typedef struct medico Medico;

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
