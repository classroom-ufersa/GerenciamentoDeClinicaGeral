#ifndef MEDICOS_H
#define MEDICOS_H

#include "../src/pacientes.c"

typedef struct medico Medico;

/**
 * Função para cadastrar um paciente em um médico.
 * 
 * Esta função solicita ao usuário que insira o nome do médico.
 * Em seguida, a função busca o médico na lista de médicos.
 * Se o médico não for encontrado, a função solicita ao usuário que insira os dados do médico e o insere na lista de médicos.
 * Após o cadastro do médico, a função solicita ao usuário que insira os dados do paciente e o insere na lista de pacientes do médico.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
 * 
 * @return Medico* - Retorna um ponteiro para o primeiro nó da lista de médicos atualizada.
*/
Medico *cadastroPaciente(Medico *lista);

/**
 * Função para buscar um médico em uma lista de médicos.
 * 
 * Esta função percorre a lista de médicos fornecida e retorna o médico com o nome fornecido.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
 * @param nome - O nome do médico a ser buscado.
 * 
 * @return Medico* - Retorna um ponteiro para o médico com o nome fornecido.
*/
Medico *buscaMedico(Medico *lista, char *nome);

/**
 * Função para preencher os dados de um médico.
 * 
 * Esta função solicita ao usuário que insira o nome, a especialidade e a disponibilidade do médico.
 * Após a entrada do usuário, a função limpa o buffer de entrada para evitar erros de entrada.
 * A função então retorna uma estrutura Medico preenchida com os dados inseridos pelo usuário.
 * 
 * @return Medico - Retorna uma estrutura Medico preenchida com os dados inseridos pelo usuário.
*/
Medico preencheMedico();

/**
 * Função para inserir um médico em uma lista de médicos de forma ordenada.
 * 
 * Esta função cria um novo nó de médico e copia os dados do médico fornecido para o novo nó.
 * Em seguida, insere o novo nó na posição correta na lista para manter a lista ordenada por nome.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
 * @param m - A estrutura do médico a ser inserida na lista.
 * 
 * @return Medico* - Retorna um ponteiro para o primeiro nó da lista de médicos atualizada.
*/
Medico *insereOrdenado(Medico *lista, Medico m);

/**
 * Função para imprimir os dados de todos os médicos em uma lista de médicos.
 * 
 * Esta função percorre a lista de médicos fornecida e imprime os dados de cada médico.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
*/
void imprimeMedicos(Medico *lista);

/**
 * Função para remover um paciente de uma lista de pacientes de um médico.
 * 
 * Esta função solicita ao usuário que insira o nome do médico.
 * Em seguida, a função busca o médico na lista de médicos.
 * Se o médico for encontrado, a função solicita ao usuário que insira o nome do paciente a ser removido.
 * A função então remove o paciente da lista de pacientes do médico.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
 * 
 * @return Medico* - Retorna um ponteiro para o primeiro nó da lista de médicos atualizada.
*/
Medico *removePacienteDoMedico(Medico *lista);

/**
 * Função para editar os dados de um paciente em uma lista de pacientes de um médico.
 * 
 * Esta função solicita ao usuário que insira o nome do médico.
 * Em seguida, a função busca o médico na lista de médicos.
 * Se o médico for encontrado, a função solicita ao usuário que insira o nome do paciente a ser editado.
 * A função então edita os dados do paciente na lista de pacientes do médico.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
 * 
 * @return Medico* - Retorna um ponteiro para o primeiro nó da lista de médicos atualizada.
*/
Medico *editarPacientePorMedico(Medico *lista, char *nomeMedico, char *nomePaciente);

/**
 * Função para remover um médico de uma lista de médicos.
 * 
 * Esta função percorre a lista de médicos fornecida e remove o médico com o nome fornecido.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
 * @param nome - O nome do médico a ser removido.
 * 
 * @return Medico* - Retorna um ponteiro para o primeiro nó da lista de médicos atualizada.
*/
Medico *removeMedico(Medico *lista, char *nome);

/**
 * Função para buscar um paciente em uma lista de pacientes de um médico.
 * 
 * Esta função solicita ao usuário que insira o nome do médico.
 * Em seguida, a função busca o médico na lista de médicos.
 * Se o médico for encontrado, a função solicita ao usuário que insira o nome do paciente a ser buscado.
 * A função então busca o paciente na lista de pacientes do médico e imprime os dados do paciente.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de médicos.
*/
void buscaPacientePorMedico(Medico *lista, char *nomeMedico, char *nomePaciente);

#endif // MEDICOS_H