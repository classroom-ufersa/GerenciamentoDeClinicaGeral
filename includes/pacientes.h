#ifndef PACIENTES_H
#define PACIENTES_H

#include "../src/sistema.c"

typedef struct paciente Paciente;

/**
 * Função para preencher os dados de um paciente.
 * 
 * Esta função solicita ao usuário que insira o nome, a idade e a doença do paciente.
 * Após a entrada do usuário, a função limpa o buffer de entrada para evitar erros de entrada.
 * A função então retorna uma estrutura Paciente preenchida com os dados inseridos pelo usuário.
 * 
 * @return Paciente - retorna uma estrutura Paciente preenchida com os dados inseridos pelo usuário.
 */
Paciente preenchePaciente();

/**
 * Função para inserir um paciente em uma lista de pacientes de forma ordenada.
 * 
 * Esta função cria um novo nó de paciente e copia os dados do paciente fornecido para o novo nó.
 * Em seguida, insere o novo nó na posição correta na lista para manter a lista ordenada por nome.
 * 
 * @param p - Um ponteiro para o primeiro nó da lista de pacientes.
 * @param pnovo - A estrutura do paciente a ser inserida na lista.
 * 
 * @return Paciente* - Retorna um ponteiro para o primeiro nó da lista de pacientes atualizada.
 */
Paciente *inserePacienteOrdenado(Paciente *p, Paciente pnovo);

/**
 * Função para imprimir os dados de todos os pacientes em uma lista de pacientes.
 * 
 * Esta função percorre a lista de pacientes fornecida e imprime os dados de cada paciente.
 * 
 * @param p - Um ponteiro para o primeiro nó da lista de pacientes.
 */
void imprimePacientes(Paciente *p);

/**
 * Função para remover um paciente de uma lista de pacientes.
 * 
 * Esta função percorre a lista de pacientes fornecida e remove o paciente com o nome fornecido.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de pacientes.
 * @param nome - O nome do paciente a ser removido.
 * 
 * @return Paciente* - Retorna um ponteiro para o primeiro nó da lista de pacientes atualizada.
 */
Paciente *removePaciente(Paciente *lista, char *nome);

/**
 * Função para editar os dados de um paciente em uma lista de pacientes.
 * 
 * Esta função percorre a lista de pacientes fornecida e edita os dados do paciente com o nome fornecido.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de pacientes.
 * @param nome - O nome do paciente a ser editado.
 * 
 * @return Paciente* - Retorna um ponteiro para o primeiro nó da lista de pacientes atualizada.
 */
Paciente *editarPaciente(Paciente *lista, char *nome);

/**
 * Função para buscar um paciente em uma lista de pacientes.
 * 
 * Esta função percorre a lista de pacientes fornecida e retorna o paciente com o nome fornecido.
 * 
 * @param lista - Um ponteiro para o primeiro nó da lista de pacientes.
 * @param nome - O nome do paciente a ser buscado.
 * 
 * @return Paciente* - Retorna um ponteiro para o paciente com o nome fornecido.
 */
Paciente *buscaPaciente(Paciente *lista, char *nome);

#endif // PACIENTES_H