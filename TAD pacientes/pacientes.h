/* TAD: Define um paciente*/
typedef struct paciente Paciente;

typedef struct lista Lista;

/* Funcao preenche os dados do paciente
   nao recebe parametros
   Retorna um paciente
*/
Paciente *preenchePaciente(void);

/* Funcao que cria uma lista encadeada de pacientes
   Retorna a lista
*/
Lista *criaLista(void);

/* Funcao que insere um paciente na lista
   Recebe um paciente e uma lista
   Retorna a lista com o paciente inserido
*/
Lista *addPaciente(Paciente *paciente, Lista *lista);

/*  Funcao para remover paciente
    Recebe uma lista encadeada de pacientes
 */
void removePaciente(Lista *lista);

/*  funcao que edita o cadastro do paciente
    recebe uma lista encadeada de pacientes
    retorna o paciente com as informacoes editadas
*/
void editPaciente(Lista *lista);

/*  funcao que vai buscar paciente na lista
    recebe o nome do paciente e a lista
    retorna o paciente com o nome buscado
*/
Lista *lst_busca(char nome, Lista *l);

/* Funcao que verifica se a lista esta vazia
   Recebe a lista
   Retorna 1 se a lista estiver vazia e 0 se nao estiver
*/
int lst_vazia(Lista *l);

/* Funcao que imprime a lista encadeda de pacientes
   Recebe a lista
*/
void listPacientes(Lista *lista);