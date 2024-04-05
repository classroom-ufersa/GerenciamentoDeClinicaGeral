#include "../src/medicos.c"

int main(void)
{   
    int opc;
    Paciente p;
    char nomeMedico[50];
    char localDoArquivo[50];
    strcpy(localDoArquivo, "dados.txt");
    Medico *listaMedicos = NULL;
    listaMedicos = lerArquivo(localDoArquivo, listaMedicos);
    Medico m;
    do{
        menu();
        opc = leropcao();

        switch(opc){
            case 1:
                m = preencheMedico();
                listaMedicos = insereOrdenado(listaMedicos, m);
                escreveArquivo(listaMedicos, localDoArquivo);
                break;
            case 2:
                printf("Digite o nome do medico que deseja remover: ");
                scanf(" %[^\n]", nomeMedico);
                listaMedicos = removeMedico(listaMedicos, nomeMedico);
                escreveArquivo(listaMedicos, localDoArquivo);
                break;
            case 3:
                listaMedicos = cadastroPaciente(listaMedicos);
                escreveArquivo(listaMedicos, localDoArquivo);
                break;
            case 4:
                removePacienteDoMedico(listaMedicos);
                escreveArquivo(listaMedicos, localDoArquivo);
                break;
            case 5:
                imprimeMedicos(listaMedicos);
                break;
            case 6:
                printf("Qual e o medico do paciente que deseja editar: ");
                scanf(" %[^\n]", nomeMedico);
                printf("qual e o nome do paciente que deseja editar: ");
                scanf(" %[^\n]", p.nome);
                listaMedicos = editarPacientePorMedico(listaMedicos, nomeMedico, p.nome);
                escreveArquivo(listaMedicos, localDoArquivo);
                break;
            case 7:
                printf("Qual o e o Medico do paciente:");
                scanf(" %[^\n]", nomeMedico);
                printf("Qual e o nome do paciente que deseja buscar: ");
                scanf(" %[^\n]", p.nome);
                buscaPacientePorMedico(listaMedicos, nomeMedico, p.nome);
                break;
            case 8:
                printf("Saindo...\n");
                break;
        }
    }while(opc != 8); 



    return 0;
}
