#include "../includes/pacientes.h"

struct paciente{
    char nome[100];
    int idade;
    char doenca[100];
    Paciente *prox;
};

Paciente preenchePaciente() {
    Paciente p;

    do {
        printf("Digite o nome do paciente: ");
        scanf(" %[^\n]", p.nome);
        if (!isStringValida(p.nome)) {
            printf("Nome invalido. Por favor, insira apenas letras e espacos.\n");
        }
    } while (!isStringValida(p.nome));

    p.idade = lerIdadePaciente();

    do {
        printf("Digite a doenca do paciente: ");
        scanf(" %[^\n]", p.doenca);
        if (!isStringValida(p.doenca)) {
            printf("Doenca invalida. Por favor, insira apenas letras e espacos.\n");
        }
    } while (!isStringValida(p.doenca));

    p.prox = NULL;
    return p;
}

Paciente *inserePacienteOrdenado(Paciente *p, Paciente pnovo){   

    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (novo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    strcpy(novo->nome, pnovo.nome);
    novo->idade = pnovo.idade;
    strcpy(novo->doenca, pnovo.doenca);
    novo->prox = NULL;

    if (p == NULL || strcmp(p->nome, novo->nome) > 0){
        novo->prox = p;
        printf("Paciente %s cadastrado com sucesso!\n", novo->nome);
        return novo;
    }

    Paciente *ant = NULL;
    Paciente *atual = p;

    while (atual != NULL && strcmp(atual->nome, pnovo.nome) < 0){
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;
    
    printf("Paciente %s cadastrado com sucesso!\n", novo->nome);
    return p;
}

void imprimePacientes(Paciente *p){
    if (p == NULL){
        printf("Lista vazia\n");
        return;
    }

    Paciente *aux = p;
    while (aux != NULL){
        printf("Paciente: %s, idade: %d, doenca: %s\n", aux->nome, aux->idade, aux->doenca);
        aux = aux->prox;
    }
}

Paciente *removePaciente(Paciente *lista, char *nome){
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
}

Paciente *editarPaciente(Paciente *lista, char *nome){   
    Paciente *p;
    int opc = 1;
    for (p = lista; p != NULL; p = p->prox){
        if (strcmp(p->nome, nome) == 0){   
            printf("Nome: %s, idade: %d, doenca: %s\n", p->nome, p->idade, p->doenca);
            do{
                printf("[1] - Editar nome\n[2] - Editar idade\n[3] - Editar doenca\n[0] - Sair\nDigite a opcao desejada:");
                scanf("%d", &opc);
                if (opc == 0){
                    break;
                }
                switch (opc){
                case 1:
                    printf("Digite o novo nome do paciente: ");
                    scanf(" %[^\n]", p->nome);
                    LimpaBuffer();
                    LimpaTela();
                    break;
                case 2:
                    printf("Digite a nova idade do paciente: ");
                    scanf("%d", &p->idade);
                    LimpaTela();
                    break;
                case 3:
                    printf("Digite a nova doenca do paciente: ");
                    scanf(" %[^\n]", p->doenca);
                    LimpaBuffer();
                    LimpaTela();
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
            } while (opc != 0);
            printf("Paciente editado com sucesso\n");
            return lista;
        }
    }
    printf("Paciente nao encontrado\n");
    return lista;
}

Paciente *buscaPaciente(Paciente *lista, char *nome){
    Paciente *p;
    for (p = lista; p != NULL; p = p->prox){
        if (strcmp(p->nome, nome) == 0){
            return p;
        }
    }
    return NULL;
}