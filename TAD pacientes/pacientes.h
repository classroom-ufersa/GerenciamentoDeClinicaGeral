/* TAD: Define um paciente*/
typedef struct paciente
{
   char nome[50];
   int idade;
   char doenca[50];
} Paciente;

typedef struct lista Lista;

typedef struct lista
{
   Paciente *paciente;
   Lista *prox;
} Lista;

/* Funcao preenche os dados do paciente
   nao recebe parametros
   Retorna um paciente
*/
Paciente *preenchePaciente(void);

/* Funcao que cria uma lista encadeada de pacientes
   Retorna a lista
*/
Lista *criaLista(void);

/* Funcao que insere um paciente na lista e ordena
   Recebe um paciente e um ponteiro para lista
   Retorna a lista com o paciente inserido e ja ordenado
*/
Lista *inserirLista(Lista **lista, Paciente *paciente);

/*  Funcao para remover paciente
    Recebe uma lista encadeada de pacientes
 */
void removePaciente(Lista **lista);

/*  funcao que edita o cadastro do paciente
    recebe uma lista encadeada de pacientes
    retorna o paciente com as informacoes editadas
*/
void editPaciente(Lista *lista);

/*  funcao que vai buscar paciente na lista
    recebe o nome do paciente e a lista
    retorna o paciente com o nome buscado
*/
void buscaPaciente(Lista *lista);

/* Funcao que verifica se a lista esta vazia
   Recebe a lista
   Retorna 1 se a lista estiver vazia e 0 se nao estiver
*/
int lst_vazia(Lista *l);

/* Funcao que imprime a lista encadeda de pacientes
   Recebe a lista
*/
void listPacientes(Lista *lista);

/* Funcao que le um arquivo
   Recebe a lista encadeada de pacientes
   ler o arquivo e insere na lista
*/
void lerDados(FILE *arquivo, Lista **listaPacientes, ListaMedicos **listaMedicos);

/* função recebe a lista encadeada de pacientes e reescreve no arquivo
   com as informações atualizadas
*/
void reescreverArquivo(Lista *lista);

/* funcao que libera o espaco de memoria alocado para a lista de pacientes
   recebe a lista encadeada de pacientes
*/
void lstLiberaPacientes(Lista *l);