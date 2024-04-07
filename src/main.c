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
    LimpaTela();
    Medico m;
    do{
        menu();
        opc = leropcao();

        switch(opc){
            case 1:
                m = preencheMedico();
                listaMedicos = insereOrdenado(listaMedicos, m);
                escreveArquivo(listaMedicos, localDoArquivo);
                LimpaTelaDelay();
                break;
            case 2:
                tratarNomeRemover(nomeMedico);
                listaMedicos = removeMedico(listaMedicos, nomeMedico);
                escreveArquivo(listaMedicos, localDoArquivo);
                LimpaTelaDelay();
                break;
            case 3:
                listaMedicos = cadastroPaciente(listaMedicos);
                escreveArquivo(listaMedicos, localDoArquivo);
                LimpaTelaDelay();
                break;
            case 4:
                removePacienteDoMedico(listaMedicos);
                escreveArquivo(listaMedicos, localDoArquivo);
                LimpaTelaDelay();
                break;
            case 5:
                LimpaTela();
                imprimeMedicos(listaMedicos);
                break;
            case 6:
                LimpaTela();
                tratarNomeEditar(nomeMedico, p.nome);
                listaMedicos = editarPacientePorMedico(listaMedicos, nomeMedico, p.nome);
                escreveArquivo(listaMedicos, localDoArquivo);
                LimpaTelaDelay();
                break;
            case 7:
                LimpaTela();
                tratarNomeBuscar(nomeMedico, p.nome);
                buscaPacientePorMedico(listaMedicos, nomeMedico, p.nome);
                break;
            case 8:
                printf("Saindo...\n");
                break;
        }
    }while(opc != 8); 

    liberaLista(listaMedicos);
    return 0;
}
