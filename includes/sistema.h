/**
 * Função para limpar o buffer de entrada.
 * 
 * Esta função lê e descarta caracteres do buffer de entrada até que um caractere de nova linha ('\n') 
 * ou o fim do arquivo (EOF) seja encontrado. Isso é útil para garantir que qualquer entrada 
 * não consumida pelo último comando de leitura não interfira com futuras leituras.
 */
void LimpaBuffer();

/**
 * Função para limpar a tela.
 * 
 * Esta função limpa a tela do terminal. Ela é útil para garantir que a tela esteja limpa antes de 
 * exibir informações importantes para o usuário.
 */
void LimpaTela();

/**
 * Função para limpar a tela com delay.
 * 
 * Esta função limpa a tela do terminal e aguarda um tempo antes de continuar a execução do programa. 
 * Ela é útil para garantir que o usuário tenha tempo suficiente para ler as informações exibidas na 
 * tela antes que elas sejam substituídas por novas informações.
 */
void LimpaTelaDelay();

/**
 * Função para exibir o menu principal.
 * 
 * Esta função exibe o menu principal do sistema. O menu exibe as opções disponíveis para o usuário 
 * e solicita que ele escolha uma opção.
 */
void menu();

/**
 * Função para ler a opção escolhida pelo usuário.
 * 
 * Esta função lê a opção escolhida pelo usuário no menu principal. Ela valida a entrada do usuário 
 * e garante que a opção escolhida seja um número inteiro válido.
 * 
 * @return A opção escolhida pelo usuário.
 */
int leropcao();

/**
 * Função para verificar se uma string é válida.
 * 
 * @param entrada - A string a ser verificada.
 * 
 * @return 1 se a string for válida, 0 caso contrário.
 */
int isStringValida(const char *entrada);

/**
 * Função para verificar se um número é válido.
 * 
 * @param entrada - O número a ser verificado.
 * 
 * @return 1 se o número for válido, 0 caso contrário.
 */
int isNumeroValido(const char *entrada);

/**
 * Função para verificar se a disponibilidade de um médico é válida.
 * 
 * @param disponibilidade - A disponibilidade a ser verificada.
 * 
 * @return 1 se a disponibilidade for válida, 0 caso contrário.
 */
int isDisponibilidadeMedicoValida(const char *disponibilidade);

/**
 * Função para ler a idade de um paciente.
 * 
 * @return A idade do paciente.
 */
int lerIdadePaciente();

/**
 * Função para tratar o nome de um médico e de um paciente para edição.
 * 
 * @param nomeMedico - O nome do médico a ser tratado.
 * @param nomePaciente - O nome do paciente a ser tratado.
 */
void tratarNomeEditar(char *nomeMedico, char *nomePaciente);

/**
 * Função para tratar o nome de um médico e de um paciente para busca.
 * 
 * @param nomeMedico - O nome do médico a ser tratado.
 * @param nomePaciente - O nome do paciente a ser tratado.
 */
void tratarNomeBuscar(char *nomeMedico, char *nomePaciente);

/**
 * Função para tratar o nome de um médico para remoção.
 * 
 * @param nomeMedico - O nome do médico a ser tratado.
 */
void tratarNomeRemover(char *nomeMedico);