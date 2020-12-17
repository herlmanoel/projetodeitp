# Simulação Epidemiológica
Projeto proposto pela disciplina de Introdução às Técnicas de Programação para compor a última nota da unidade, desenvolvido por Herlmanoel Fernandes Barbosa com a orientação do professor Júlio Cesar Paulino de Melo. O trabalho tem como objetivo utilizar o Modelo Epidemiológico Computacional (MEC) Suscetível-Infectado-Removido (SIR) utilizado para observar a interação entre essas populações dos indivíduos Suscetíveis, Infectados e Removidos e, a partir delas, propor políticas públicas para combate e prevenção de doenças infeciosas.
### Checkpoint 1
- [x] Implementação do MEC com entrada via .txt, saída via .csv e no terminal;
- [x] Arquivo de configuração (entrada.txt) e a leitura dele;
- [x] Criação do arquivo (saida.csv) com base nos dados calculados.

### Checkpoint 2
- [x] Implementação dos cenários de simulação 1 e 2:
    - [x] Formato de dados do arquivo txt de configuração;
    - [x] Leitura do arquivo de configuração;
- [x] Arquivo de configuração (entrada.txt) e a leitura dele;
- [x] Criação do arquivo (saida.csv) com base nos dados calculados;
- [x] Modificações solicitadas no Checkpoint 1.
 - [x] . io.h e io.c
 	- Modularização das funcionalidades leitura e escrita de dados em arquivos.
- [x] Separar funcionalidades de simulação da parte de escrita no arquivo
 - O programa deve simular primeiro e escrever depois
3. Simulação longa
 - Simular uma quantidade qualquer de horas (por exemplo 365 dias)

### Escrevendo um arquivo de configuração de entrada
Para isso, na pasta arquivos crie um arquivo "entrada.txt". Em seguida, dentro do arquivo adicione os parâmetros separados por vírgula como exemplificado abaixo:
- 68,2,0,0.1,12,24,50,10,6,22,24,21,3,0,12
Em que: 
- S(0): 68, I(0): 2, R(0): 0, h: 0.1, N_b: 12, T_b: 24, S_b0: 50, I_b0: 10, m_k: 6, n_k: 22, T_k: 24, dias: 21, percepção: 3, T_b2: 0, T_k2: 12

### Compilar e executar o programa
- Para compilar no terminal usamos o comando gcc - GNU Compiler Collection que é um conjunto de compiladores de linguagens de programação, dentre elas, a linguagem C - e, após o gcc, escreva o nome dos arquivos .c. Além disso, se você já preferir executar o código, adicione um “;” e, em seguida, o nome do executável gerado: "./z.exe". 
Exemplificando: 
```sh
$ gcc main.c ler_entrada.c calculo_cenarios.c escrever_e_imprimir.c -o z.exe ; ./z.exe
```
### Plotar gráficos
- Para plotar os gráficos vamos utilizar o Google Colaboratory que é um ambiente de notebooks Jupyter (Python) que não requer configuração e é executado na nuvem, e o Matplotlib que é uma biblioteca para criação de gráficos.
- Inicialmente, vamos realizar o upload do arquivo de saída o "saida.csv".
- Logo após, vamos importar a biblioteca o Matplotlib:
```py
import matplotlib.pyplot as plot
```
- Em seguida, criaremos a função add que receberá o objeto plot - importado acima -, o local do arquivo de entrada (com a saída do código em .c, ou seja, a saida.csv) e uma variável para cada cor das linhas do gráfico.
```py
def add(plot_, path_arquivo, corS, corI, corR, corM):
	content = [line.split(',')  for line in open(path_arquivo, "r").readlines()]

	t = [float(line.pop()[:-1])  for line in content]
	s = [float(line[0])  for line in content]
	i = [float(line[1])  for line in content]
	r = [float(line[2])  for line in content]
	m = [float(line[3])  for line in content]

	plot_.plot(s, corS, label="S")
	plot_.plot(i, corI, label="I")
	plot_.plot(r, corR, label="R")
	plot_.plot(m, corM, label="M")
```
- Com isso, o código acima separará os dados por coluna - a cada vírgula - e, posteriormente, será adicionando cor as linhas.
```py
add(plot, "saida.csv", 'g', 'r', 'b')
plot.legend()
plot.show()
```
- [Link do Google Colab com o código para plotar os gráficos](https://colab.research.google.com/drive/12JS-tvidnfjzjZcJqpgQYUIFAZ9V76DU?usp=sharing)

