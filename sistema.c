#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N_OPCOES 8

#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

void LimpaBuffer(){
    int valorLido;
    do{
        valorLido = getchar();
    }while (valorLido != '\n' && valorLido != EOF);
}

void LimpaTela(){
    system("clear");
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