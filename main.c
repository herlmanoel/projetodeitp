#include <stdio.h>
#include "ler_entrada.h"
#include "escrever_e_imprimir.h"
#include "calculo_cenarios.h"

int main() {
    Dados_entrada *dados_entrada = ler_arquivo("arquivos/entrada.txt");
    vetor_de_parametros *vp = create(dados_entrada);
    calcular_mec_sir(vp, dados_entrada);
    escrever_csv(vp, "arquivos/saida.csv");
    
    return 0;
}
