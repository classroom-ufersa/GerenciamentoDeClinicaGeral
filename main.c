#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TAD medicos/medicos.c"
#include "TAD pacientes/pacientes.c"

int lerOpcao() {
    char opcao[10];
    printf("Digite a opcao desejada: ");
    scanf("%9s", opcao);

    for (int i = 0; opcao[i] != '\0'; i++) {
        if (!isdigit(opcao[i])) {
            printf("Opcao invalida. Por favor, digite um numero correspondente a uma das opcoes do menu.\n");
            return -1;
        }
    }

    int escolha = atoi(opcao);
    return escolha;
}

int main(void) {
    int opcao;
    Lista *listaPacientes = criaLista();
    ListaMedicos *listaMedicos = criaListaMedicos();
    char nomeMedico[50];
    char nomePaciente[50];
    
    do {
        printf("\t\nBem vindo a Clinica\n\n");
        printf("Escolha uma opcao: \n");
        printf("1 - Cadastro medico\n");
        printf("2 - Remover medico\n");
        printf("3 - Cadastro paciente\n");
        printf("4 - Remover paciente\n");
        printf("5 - Editar cadastro de paciente\n");
        printf("6 - Buscar por paciente\n");
        printf("7 - Listar medicos e seus pacientes\n");
        printf("8 - Listar pacientes\n");
        printf("0 - Sair\n");

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                listaMedicos = addMedicoLista(preencheMedico(), listaMedicos);
                break;
            case 2:
                printf("Digite o nome do medico que deseja remover: ");
                scanf(" %[^\n]", nomeMedico);
                removeMedico(nomeMedico, &listaMedicos);
                break;
            case 3:
                listaPacientes = addPaciente(preenchePaciente(), listaPacientes);
                break;
            case 4:
                printf("Digite o nome do paciente que deseja remover: ");
                scanf(" %[^\n]", nomePaciente);
                removePaciente(&listaPacientes);
                removerPacienteDoArquivo(nomePaciente);
                break;
            case 5:
                editPaciente(listaPacientes);
                break;
            case 6:
                buscaPaciente(listaPacientes);
                break;
            case 7:
                // Adicione aqui a opção para listar médicos e seus pacientes
                break;
            case 8:
                listPacientes(listaPacientes);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma das opcoes do menu.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
