/* TAD: Define um paciente*/
typedef struct paciente Paciente;

/* Funcao para adicionar paciente
   Recebe um nome, uma idade e uma doenca
 */
Paciente *addPaciente(char *nome, int idade, char *doenca);

/*  Funcao para remover paciente
    Recebe um paciente
 */
void removePaciente(Paciente *paciente);

/*  funcao que edita o cadastro do paciente
    recebe um paciente, um nome, uma idade e uma doenca
    retorna o paciente com as informacoes editadas
*/
void editPaciente(Paciente *paciente, char *nome, int idade, char *doenca);

/*  funcao que vai buscar paciente na lista
    recebe um paciente e um nome
    retorna o paciente com o nome buscado
*/
Paciente *buscarPacinete(Paciente *paciente, char *nome);
