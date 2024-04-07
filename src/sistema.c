#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void LimpaBuffer(){
    int valorLido;
    do{
        valorLido = getchar();
    }while (valorLido != '\n' && valorLido != EOF);
}

void LimpaTela(){
    system("cls");
}

void LimpaTelaDelay(){
    Sleep(2000);
    system("cls");
}

void menu(){
    printf("====Bem vindo a Clinica G&G====\n");
        printf("[1] - Cadastrar Medico\n");
        printf("[2] - Remover Medico\n");
        printf("[3] - Cadastrar Paciente\n");
        printf("[4] - Remover Paciente\n");
        printf("[5] - Imprimir Medicos e\nseus respectivos pacientes\n");
        printf("[6] - editar paciente\n");
        printf("[7] - Buscar paciente\n");
        printf("[8] - Sair\n");
}

int leropcao() {
    char opcao[10];
    printf("Digite a opcao desejada: ");
    scanf("%s", opcao);

    for (int i = 0; opcao[i] != '\0'; i++) {
        if (!isdigit(opcao[i])) {
            printf("Opcao invalida. Digite um numero correspondente com as opcoes do menu.\n");
            return -1;
        }
    }

    int escolha = atoi(opcao);
    return escolha;
}

int isStringValida(const char *entrada) {
    int i;
    for (i = 0; entrada[i] != '\0'; i++) {
        if (!isalpha(entrada[i]) && entrada[i] != ' ') {
            return 0; 
        }
    }
    return 1; 
}

int isNumeroValido(const char *entrada) {
    int i;
    for (i = 0; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i])) {
            return 0; 
        }
    }
    return 1; 
}

int isDisponibilidadeMedicoValida(const char *disponibilidade) {
    int hora_inicio, hora_fim;
    char lixo;

    if (sscanf(disponibilidade, "%dh as %dh%c", &hora_inicio, &hora_fim, &lixo) != 2)
        return 0; 

    if (hora_inicio < 0 || hora_inicio > 24 || hora_fim < 0 || hora_fim > 24)
        return 0; 

    if (hora_inicio >= hora_fim)
        return 0; 

    return 1; 
}

int lerIdadePaciente() {
    int idade;
    char entrada[20]; 

    do {
        printf("Digite a idade do paciente: ");
        scanf("%19s", entrada); 
        LimpaBuffer(); 

        if (!isNumeroValido(entrada)) {
            printf("Idade invalida. Por favor, insira apenas numeros.\n");
        } else {
            idade = atoi(entrada); 
            if (idade < 0) {
                printf("Idade invalida. Por favor, insira uma idade nao negativa.\n");
            }
        }
    } while (!isNumeroValido(entrada) || idade < 0); 

    return idade;
}

void tratarNomeEditar(char *nomeMedico, char *nomePaciente) {
    do {
        printf("Qual o medico do paciente que deseja editar: ");
        scanf(" %[^\n]", nomeMedico);
        getchar(); 

        if (!isStringValida(nomeMedico)) {
            printf("Nome do medico invalido. Por favor, insira apenas letras e espacos.\n");
        }
    } while (!isStringValida(nomeMedico));

    do {
        printf("Qual o nome do paciente que deseja editar: ");
        scanf(" %[^\n]", nomePaciente);
        getchar(); 

        if (!isStringValida(nomePaciente)) {
            printf("Nome do paciente invalido. Por favor, insira apenas letras e espacos.\n");
        }
    } while (!isStringValida(nomePaciente));
    LimpaTela();
}

void tratarNomeBuscar(char *nomeMedico, char *nomePaciente) {
    do {
        printf("Qual o medico do paciente que deseja buscar: ");
        scanf(" %[^\n]", nomeMedico);
        getchar(); 

        if (!isStringValida(nomeMedico)) {
            printf("Nome do medico invalido. Por favor, insira apenas letras e espacos.\n");
        }
    } while (!isStringValida(nomeMedico));

    do {
        printf("Qual o nome do paciente que deseja buscar: ");
        scanf(" %[^\n]", nomePaciente);
        getchar(); 

        if (!isStringValida(nomePaciente)) {
            printf("Nome do paciente invalido. Por favor, insira apenas letras e espacos.\n");
        }
    } while (!isStringValida(nomePaciente));
}

void tratarNomeRemover(char *nomeMedico) {
    do {
        printf("Qual o medico que deseja remover: ");
        scanf(" %[^\n]", nomeMedico);
        getchar(); 

        if (!isStringValida(nomeMedico)) {
            printf("Nome do medico invalido. Por favor, insira apenas letras e espacos.\n");
        }
    } while (!isStringValida(nomeMedico));
}