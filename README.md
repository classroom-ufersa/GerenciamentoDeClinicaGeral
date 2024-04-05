<div>
  <div id="nav-bar">
    <img align="right" width="110" height="170" src="https://assecom.ufersa.edu.br/wp-content/uploads/sites/24/2014/09/PNG-bras%C3%A3o-Ufersa.png">
    <br>
    <h1 align="center" style="font-weight: bold;">Gerenciamento De Clínica Geral</h1>
    <p align="center">
        <a href="#requirements">Requisitos do Projeto</a> •
        <a href="#tech">Tecnologia</a> •
        <a href="#about">Sobre o Projeto</a> •
        <a href="#colab">Colaboradores</a> 
    </p>
  </div>

  <h2 id="requirements" style="font-weight: bold; font-size: 2rem">Requisitos do Projeto</h2>
  <div>
    ✅A opção Sair é a única que permite sair do programa.</br>
    ✅A cada execução do seu programa, os dados devem ser armazenados em um arquivo txt e deve carregar os mesmos para o programa</br>
    ✅Cada médico ou paciente cadastrado deve ser inserido em ordem alfabética.</br>
    ✅O arquivo deve refletir o estado atual dos dados em virtude da adição ou remoção.</br>
  </div>

  <div>
    <h2 id="tech" style="font-weight: bold; font-size: 2rem">Tecnologia Utilizada</h2>
    <img width="120" height="120" alt="C" src="img/logo_C.png"/>
  </div>

  <h2 id="about" style="font-weight: bold; font-size: 2rem">Sobre o Projeto</h2>

  Este projeto tem como objetivo o desenvolvimento de um sistema de gerenciamento para clínicas gerais, elaborado como uma tarefa para a disciplina de Algoritmos e Estruturas de Dados. Focado em simplificar e organizar as operações diárias de clínicas, o sistema proporciona uma solução eficaz para o gerenciamento de dados de pacientes e médicos, facilitando a manutenção de registros precisos e atualizados. Faz uso intensivo de estruturas de dados como listas encadeadas. As listas encadeadas são empregadas para gerenciar de forma eficiente as coleções de dados dos pacientes e médicos, permitindo as operações de maneira otimizada. A escolha por listas encadeadas se deve à sua flexibilidade e eficiência na gestão de dados dinâmicos, sendo uma escolha adequada para o sistema de gerenciamento de clínica geral, que requer manipulação constante de informações.

  #### O projeto conta com as funcionalidades:

  Cadastro de Médicos e Pacientes: Permite o registro de pacientes e médicos no sistema, incluindo dados pessoais, para os médicos, especialidades e disponibilidades.

  Edição de Informações: Facilita a atualização de informações cadastrais de pacientes, garantindo que os dados se mantenham atuais e precisos.

  Remoção de Cadastros: Oferece a opção de remover cadastros do sistema, seja para pacientes que optaram por outra clínica ou médicos que não fazem mais parte do corpo clínico.

  ## Organização do Repositório

  ``` 
  📁 GerenciamentoDeClinicaGeral/
  │
  └─── img/
          │
          ├──logo_C.png
  │
  └─── include/
          │
          ├──medicos.h
          ├──pacientes.h
          ├──sistema.h
  │
  └─── src/
          │
          └─── output/
                    ├──dados.txt
          ├──main.c
          ├──medicos.c
          ├──pacientes.c
          ├──sistema.c
  │
  ├──.gitignore
  ├──README.md
  ```

  ## Como rodar na minha maquina?

  

  Clone o repositorio na sua maquina:

  ```bash
  git clone https://github.com/classroom-ufersa/GerenciamentoDeClinicaGeral.git
  ```

  Para executar, certifique-se de que você possui um compilador C instalado na sua máquina, então navegue até onde o projeto está localizado. Você pode fazer isso usando o comando cd. 
  
  No terminal use este comando:

  ```c
  gcc main.c -o main && ./main
```

  <h2 id="colab" align="center" style="font-weight: bold; font-size: 2rem">Colaboradores</h2>
  <div align="center">
    <table>
      <tr>
        <td align="center">
          <a href="#">
            <img src="https://avatars.githubusercontent.com/u/111452823?v=4" width="100px;" alt="chico moedas"/><br>
            <sub>
              <a href="https://github.com/gusjjpv"><b>João Gustavo</b></a>
            </sub>
          </a>
        </td>
        <td align="center">
          <a href="#">
            <img src="https://avatars.githubusercontent.com/u/72459288?v=4" width="100px;" alt="fotin"/><br>
            <sub>
              <a href="https://github.com/gustavo-f0ntz"><b>Gustavo Kesley</b></a>
            </sub>
          </a>
        </td>
    </table>
    Um agradecimento especial a todas as pessoas que contribuíram para este projeto.
  </div>
</div>
