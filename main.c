#include <stdio.h>
#include "ler_entrada.h"
#include "escrever_e_imprimir.h"
#include "calculo_cenarios.h"

// gcc main.c ler_entrada.c calculo_cenarios.c escrever_e_imprimir.c -o z.exe & ./z
// gcc main.c ler_entrada.c calculo_cenarios.c escrever_e_imprimir.c -o z.exe ; ./z.exe
int main() {
    // Cenário 0:
    Dados_entrada *dados_entrada00 = ler_arquivo("arquivos/entrada00.txt");
    vetor_de_parametros *vp00 = create(dados_entrada00);
    calcular_mec_sir(vp00, dados_entrada00);
    escrever_csv(vp00, "arquivos/saida00.csv");
    imprimir_terminal(vp00);

    // Cenário 1: Distanciamento/uso de máscaras
    Dados_entrada *dados_entrada01 = ler_arquivo("arquivos/entrada01.txt");
    vetor_de_parametros *vp01 = create(dados_entrada01);
    calcular_mec_sir(vp01, dados_entrada01);
    escrever_csv(vp01, "arquivos/saida01.csv");

    // Cenário 2: Melhoria nos protocolos de atendimento
    // menor valor de T_k
    Dados_entrada *dados_entrada02 = ler_arquivo("arquivos/entrada02.txt");
    vetor_de_parametros *vp02 = create(dados_entrada02);
    calcular_mec_sir(vp02, dados_entrada02);
    escrever_csv(vp02, "arquivos/saida02.csv");
    imprimir_terminal(vp02);

    // Cenário 1: Distanciamento/uso de máscaras
    // Dados_entrada *dados_entrada01 = ler_arquivo("arquivos/entrada01.txt");
    // vetor_de_parametros *vp01 = create(dados_entrada01);
    // calcular_mec_sir(vp01, dados_entrada01);
    // escrever_csv(vp01, "arquivos/saida01.csv");
    // imprimir_terminal(vp01);

    

    return 0;
}
