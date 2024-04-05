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