#include <stdio.h>
#include <stdlib.h>
#include "calcular_mec_sir.h"

vetor_de_parametros *create() {
    vetor_de_parametros *vetor_de_params = (vetor_de_parametros *)malloc(sizeof(vetor_de_parametros));
    vetor_de_params->p = (Parametros *)calloc(1, sizeof(Parametros));
    vetor_de_params->tamanho_atual = 1;
    return vetor_de_params;
}

vetor_de_parametros *reallocar_vetor(vetor_de_parametros *vetor_de_params) {
    vetor_de_params->tamanho_atual++;
    vetor_de_params->p = realloc(vetor_de_params->p, vetor_de_params->tamanho_atual * sizeof(Parametros));
    return vetor_de_params;
}

double calcular_b(double N_b, double T_b, double S_b0, double I_b0) {
     return N_b / (T_b * S_b0 * I_b0);
}

double calcular_k(double m_k, double n_k, double T_k) {
     return m_k / (n_k * T_k);
}

void escrever_csv(vetor_de_parametros *vp, double h, double k, double b, int fim) {
    FILE *saida;
    /* Abrir um arquivo texto para gravação. Se o arquivo não existir, ele será criado. 
	    Se já existir, o conteúdo anterior será destruído */
    saida = fopen("saida.csv", "w"); 
    fclose(saida);

    for(int i = 0; i < fim; i++) {
        reallocar_vetor(vp);
        vp->p[i+1].S0 = vp->p[i].S0 - h * (b * vp->p[i].S0 * vp->p[i].I0);
        vp->p[i+1].I0 = vp->p[i].I0 + (h * (b * vp->p[i].S0 * vp->p[i].I0 - k * vp->p[i].I0));
        vp->p[i+1].R0 = vp->p[i].R0 + h * k * vp->p[i].I0;
        vp->p[i+1].tempo = vp->p[i].tempo + h; 
        saida = fopen("saida.csv", "a");
        fprintf(saida, "%lf,%lf,%lf,%lf\n", vp->p[i].S0, vp->p[i].I0, vp->p[i].R0, vp->p[i].tempo);
        fclose(saida);
    }
}

void imprimir_terminal(vetor_de_parametros *vp, double h, double k, double b, int fim) {
    for(int i = 0; i < fim; i++) {
        reallocar_vetor(vp);
        vp->p[i+1].S0 = vp->p[i].S0 - h * (b * vp->p[i].S0 * vp->p[i].I0);
        vp->p[i+1].I0 = vp->p[i].I0 + (h * (b * vp->p[i].S0 * vp->p[i].I0 - k * vp->p[i].I0));
        vp->p[i+1].R0 = vp->p[i].R0 + h * k * vp->p[i].I0;
        vp->p[i+1].tempo = vp->p[i].tempo + h; 
        printf("%lf,%lf,%lf,%lf\n", vp->p[i].S0, vp->p[i].I0, vp->p[i].R0, vp->p[i].tempo);
    }
}

void liberar_vetor_de_parametros(vetor_de_parametros *vp) {
    free(vp->p);
    free(vp);
}