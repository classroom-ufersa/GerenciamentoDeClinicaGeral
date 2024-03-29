#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD medicos/medicos.c"
#include "TAD pacientes/pacientes.c"

int main(void)
{
    int opcao;
    Lista *listaPacientes = criaLista();
    ListaMedicos *listaMedicos = criaListaMedicos();
    char nomeMedico[50];
<<<<<<< Updated upstream

    FILE *arq = fopen("CadClinica.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    lerArquivo(arq, &listaPacientes);

    do
    {
=======
    char nomePaciente[50];
    
    do {
>>>>>>> Stashed changes
        printf("\t\nBem vindo a Clinica\n\n");
        printf("Escolha uma opcao: \n");
        printf("1 - Cadastro medico\n");
        printf("2 - Remover medico\n");
        printf("3 - Cadastro paciente\n");
        printf("4 - Remover paciente\n");
        printf("5 - Editar cadastro de paciente\n");
        printf("6 - Buscar por paciente\n");
        printf("7 - Listar medicos e seus pacientes\n");
        printf("8 - listar pacientes\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf(" %d", &opcao);
        switch (opcao)
        {
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
            removePaciente(&listaPacientes);
            break;
        case 5:
            editPaciente(listaPacientes);
            break;
        case 6:
            buscaPaciente(listaPacientes);
            break;
        case 7:
            
            break;
        case 8:
            listPacientes(listaPacientes);
            break;
        case 9:

<<<<<<< Updated upstream
            break;
        case 10:
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
            break;
=======
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
>>>>>>> Stashed changes
        }
    } while (opcao != 0);
    return 0;
}