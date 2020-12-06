#include <stdio.h>
#include <stdlib.h>
#include "ler_entrada.h"

Dados_entrada* ler_arquivo(char arquivo[]) {
    
    Dados_entrada* dados_entrada = (Dados_entrada*) calloc(1, sizeof(Dados_entrada));

    /* 
        Abre um arquivo texto para leitura. O arquivo deve existir antes de ser aberto. 
        entrada = fopen("arquivos/entrada01.txt", "r"); 
    */
    entrada = fopen(arquivo, "r");

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo.");
        return NULL;
    }

    // 68,2,0,0.1,12,24,50,10,6,22,24,21
    fscanf(entrada, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", 
        &dados_entrada->S0, 
        &dados_entrada->I0, 
        &dados_entrada->R0, 
        &dados_entrada->h,
        &dados_entrada->N_b, 
        &dados_entrada->T_b, 
        &dados_entrada->S_b0, 
        &dados_entrada->I_b0, 
        &dados_entrada->m_k, 
        &dados_entrada->n_k, 
        &dados_entrada->T_k, 
        &dados_entrada->dias, 
        &dados_entrada->percepcao,
        &dados_entrada->T_b2,
        &dados_entrada->T_k2);
    fclose(entrada);

    return dados_entrada;
}