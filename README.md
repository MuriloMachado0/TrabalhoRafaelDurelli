Conversor de Bases Numéricas - Trabalho Prático

Trabalho prático desenvolvido para a disciplina de Introdução à Computação, focado na construção de um programa completo de conversão entre as bases numéricas **Binária (2), Octal (8), Decimal (10) e Hexadecimal (16)**. O sistema contempla suporte a números inteiros e fracionários, exibição detalhada dos cálculos (modo passo a passo), execução em lote e um modo quiz avaliativo.

Integrantes da Dupla
Nome: Fauly Oliveira Martins da Silveira   Matrícula: 202610127
Nome: Murilo Machado Silveira              Matrícula: 202610118

--Linguagem Escolhida e Justificativa
* O projeto foi desenvolvido inteiramente na linguagem C++, utilizando de forma estrita e exclusiva a sua biblioteca padrão. O sistema não possui qualquer dependência externa.
* A linguagem C++ foi escolhida por ser a linguagem que os participantes da dupla mais conhecem.

--Modularização: O código-fonte está dividido de forma clara em módulos distintos para separar as responsabilidades do sistema:
* Parser de Entrada e Validação: `main.cpp`, `quiz.cpp` e `batch.cpp` (tratamento de fluxos, menus e filtros de caracteres).
* Núcleo de Conversão: `conversoes.cpp` (algoritmos matemáticos de somatório posicional, divisões sucessivas e agrupamento direto de bits).
* Formatador de Saída: `saida.cpp` (responsável pelo modo *trace*/passo a passo e estilização de dados no terminal).

--Link do Vídeo de Demonstração
https://youtu.be/P_awm9lIZBk

--Instruções de Compilação e Execução

**Caso Linux:**

Para compilar e executar o código:
g++ main.cpp conversoes.cpp saida.cpp batch.cpp quiz.cpp -o conversor && ./conversor

Para compilar e executar suíte de testes:
g++ conversoes.cpp testes.cpp -o suite_testes && ./suite_testes

**Caso Windows CMD**

Para compilar e executar o código:
g++ main.cpp conversoes.cpp saida.cpp batch.cpp quiz.cpp -o conversor && conversor.exe

Para compilar e executar suíte de testes:
g++ conversoes.cpp testes.cpp -o suite_testes && suite_testes.exe

--Instruções de uso do prgrama

Ao executar o código, o usuário deve ler o menu de interação no terminal e escolher a opção que gostaria de utilizar.
*Opção 1 seleciona a conversão de valores, o usuário deve digitar o valor a ser convertido, a base de origem e a base de destino. Logo após, deverá selecionar se quer acompanhar ou não o passo a passo da conversão.
*Opção 2 seleciona o modo batch, modo em que o usuário digita o nome do arquivo que será lido e o nome do arquivo que será criado com os resultados.
*Opção 3 seleciona o modo quiz, modo em que o usuário será desafiado com 5 questões de conversão de valores, do nível 1 ao 5 com dificuldade crescente (Questão 1 vale 10 pontos, questão 2 vale 20 pontos, questão 3 vale 30 pontos e assim por diante).
*Opção 4 seleciona o modo calculadora de máximos, modo em que o usuário digita a quantidade de bits e o programa retorna o maior número que pode ser escrito com essa quantidae de bits representado nas quatro bases trabalhadas.
*Opção 0 encerra o programa.

--Limitações do código

Falta de um menu interativo visual com botões e sensível ao clique.
Máximo valor restringido ao 'long long'.
