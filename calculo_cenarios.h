#ifndef CALCULO_CENARIO_ZERO_H
#define CALCULO_CENARIO_ZERO_H

#include <stdio.h>
#include "ler_entrada.h"

typedef struct parametros_type {
    double S0; 
    double I0; 
    double R0; 
    double M0;
    double tempo;
} Parametros_da_saida;

typedef struct vetor_de_parametros_type {
    int tamanho;
    int tamanho_atual;
    Parametros_da_saida *p;
} vetor_de_parametros;

vetor_de_parametros *create(Dados_entrada* pe);
vetor_de_parametros *reallocar_vetor(vetor_de_parametros *vetor_de_params);
void liberar_vetor_de_parametros(vetor_de_parametros *vp);
double calcular_b(double N_b, double T_b, double S_b0, double I_b0);
double calcular_k(double m_k, double n_k, double T_k);
void calcular_mec_sir(vetor_de_parametros *vp, Dados_entrada *dados_entrada);

void calcular_mec_sir_mortes(vetor_de_parametros *vp, Dados_entrada *dados_entrada);

#endif