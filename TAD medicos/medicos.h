#ifndef MEDICOS_H
#define MEDICOS_H
/* Estrutura de dados para armazenar os dados de um médico 
*/
typedef struct medico
{
    char nome[50];
    char especialidade[50];
    char paciente[50];
    char disponibilidade[50];
} Medico;

/* Estrutura de dados para armazenar uma lista encadeada de médicos 
*/
typedef struct listaMedicos ListaMedicos;

struct listaMedicos
{
    Medico *medico;
    ListaMedicos *prox;
};

/*  Função para remover um médico da lista 
    Recebe um ponteiro para a lista de médicos
    nao retorna nada
*/
void removeMedico(ListaMedicos **lista);

/*  Função para listar os médicos 
    Recebe a lista de médicos
    nao retorna nada
*/
void listMedico(ListaMedicos *lista);

/*  Função para criar uma lista de médicos 
    nao recebe parametros
    Retorna a lista de médicos
*/
ListaMedicos *criaListaMedicos(void);

/*  Função para adicionar um médico à lista 
    Recebe um médico e um ponteiro para a lista de médicos
    Retorna a lista de médicos com o médico adicionado
*/
ListaMedicos *inserirOrdenadoMedico(ListaMedicos **lista, Medico *novoMedico);


ListaMedicos *addMedicoArquivo(char *nome, char *especialidade, char *paciente, char *disponibilidade, ListaMedicos **lista);

/* Função para preencher os dados de um médico */
Medico *preencheMedico(void);

/* Função para verificar se a lista de médicos está vazia */
int lst_vaziaMedicos(ListaMedicos *l);

//void escreverMedico(Medico *medico);
void reescreverArquivoMedicos(ListaMedicos *lista);

void lstLiberaMedicos(ListaMedicos *l);

#endif /* MEDICOS_H */