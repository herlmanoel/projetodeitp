#ifndef LER_ENTRADA_H
#define LER_ENTRADA_H

#include <stdio.h>

FILE *entrada;

typedef struct dados_entrada_e {
    double S0;
    double I0;
    double R0;
    double h;
    double N_b;
    double T_b;
    double S_b0;
    double I_b0;
    double m_k;
    double n_k;
    double T_k;
    double dias;
    double percepcao;
    double T_b2;
    double T_k2;
} Dados_entrada;

Dados_entrada* ler_arquivo(char arquivo[]);

#endif