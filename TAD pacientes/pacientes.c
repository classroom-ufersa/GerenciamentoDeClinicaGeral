#include "pacientes.h"

struct paciente
{
    char nome[100];
    int idade;
    char doenca[100];
    Paciente *prox;
};

Paciente preenchePaciente()
{
    Paciente p;
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]s", p.nome);
    LimpaBuffer();
    printf("Digite a idade do paciente: ");
    scanf("%d", &p.idade);
    LimpaBuffer();
    printf("Digite a doenca do paciente: ");
    scanf(" %[^\n]s", p.doenca);
    LimpaBuffer();
    p.prox = NULL;
    return p;
}
//colocar no .h
// Paciente *insereNoFinalPaciente(Paciente *p, Paciente pnovo){
//     Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
//     strcpy(novo->nome, pnovo.nome);
//     novo->idade = pnovo.idade;
//     strcpy(novo->doenca, pnovo.doenca);
//     novo->prox = NULL;
//     if(p == NULL){
//         return novo;
//     }
//     Paciente *atual = p;
//     Paciente *ant = p;
//     while(atual != NULL){
//         ant = atual;
//         atual = atual->prox;
//     }
//     ant->prox = novo;
//     return p;
// }

Paciente *inserePacienteOrdenado(Paciente *p, Paciente pnovo)
{
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    strcpy(novo->nome, pnovo.nome);
    novo->idade = pnovo.idade;
    strcpy(novo->doenca, pnovo.doenca);
    novo->prox = NULL;

    if (p == NULL || strcmp(p->nome, novo->nome) > 0)
    {
        novo->prox = p;
        return novo;
    }

    Paciente *ant = NULL;
    Paciente *atual = p;

    while (atual != NULL && strcmp(atual->nome, pnovo.nome) < 0)
    {
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;

    return p;
}

//revisei
void imprimePacientes(Paciente *p)
{
    if (p == NULL)
    {
        printf("Lista vazia\n");
        return;
    }

    Paciente *aux = p;
    while (aux != NULL)
    {
        printf("Paciente: %s, idade: %d, doenca: %s\n", aux->nome, aux->idade, aux->doenca);
        aux = aux->prox;
    }
}
//revisada
Paciente *removePaciente(Paciente *lista, char *nome)
{
    Paciente *ant = NULL;
    Paciente *p = lista;

    while(strcmp(p->nome, nome) != 0){
        if(p == NULL){
            return lista;
        }
        ant = p;
        p = p->prox;
    }
    if(ant == NULL){
        lista = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return lista;

    // while (p != NULL && strcmp(p->nome, nome) != 0)
    // {
    //     if (p == NULL)
    //     {
    //         return lista;
    //     }
    //     ant = p;
    //     p = p->prox;
    // }
    // if (ant == NULL)
    // {
    //     lista = p->prox;
    // }
    // else
    // {
    //     ant->prox = p->prox;
    // }
    // free(p);
    // return lista;
}
//revisada
Paciente *editarPaciente(Paciente *lista, char *nome)
{
    Paciente *p;
    int opc = 1;
    for (p = lista; p != NULL; p = p->prox)
    {
        if (strcmp(p->nome, nome) == 0)
        {   
            printf("Nome: %s, idade: %d, doenca: %s\n", p->nome, p->idade, p->doenca);
            do
            {
                printf("[1] - Editar nome\n[2] - Editar idade\n[3] - Editar doenca\n[0] - Sair\n");
                scanf("%d", &opc);
                if (opc == 0)
                {
                    break;
                }
                switch (opc)
                {
                case 1:
                    printf("Digite o novo nome do paciente: ");
                    scanf(" %[^\n]", p->nome);
                    break;
                case 2:
                    printf("Digite a nova idade do paciente: ");
                    scanf("%d", &p->idade);
                    break;
                case 3:
                    printf("Digite a nova doenca do paciente: ");
                    scanf(" %[^\n]", p->doenca);
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
            } while (opc != 0);

            return lista;
        }
    }
    printf("Paciente nao encontrado\n");
    return lista;
}
//revisada
Paciente *buscaPaciente(Paciente *lista, char *nome){
    Paciente *p;
    for (p = lista; p != NULL; p = p->prox)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            return p;
        }
    }
    return NULL;
}