#include <stdio.h>
#include <stdlib.h>
#include "calculo_cenarios.h"
#include "ler_entrada.h"

vetor_de_parametros *create(Dados_entrada* pe) {
    vetor_de_parametros *vetor_de_params = (vetor_de_parametros *)malloc(sizeof(vetor_de_parametros));
    vetor_de_params->p = (Parametros_da_saida *)calloc(10, sizeof(Parametros_da_saida));
    vetor_de_params->tamanho_atual = 1;
    vetor_de_params->tamanho = 10;
    vetor_de_params->p[0].S0 = pe->S0;
    vetor_de_params->p[0].I0 = pe->I0;
    vetor_de_params->p[0].R0 = pe->R0;
    
    pe->percepcao = (pe->percepcao * 24);
    printf("%lf \n\n", pe->percepcao);
    
    vetor_de_params->p[0].tempo = 0;
    return vetor_de_params;
}

vetor_de_parametros *reallocar_vetor(vetor_de_parametros *vetor_de_params) {
    vetor_de_params->tamanho += 10;
    vetor_de_params->p = realloc(vetor_de_params->p, (vetor_de_params->tamanho) * (sizeof(Parametros_da_saida)));
    return vetor_de_params;
}

void liberar_vetor_de_parametros(vetor_de_parametros *vp) {
    free(vp->p);
    free(vp);
}

double calcular_b(double N_b, double T_b, double S_b0, double I_b0) {
     return N_b / (T_b * S_b0 * I_b0);
}

double calcular_k(double m_k, double n_k, double T_k) {
     return m_k / (n_k * T_k);
}

void calcular_mec_sir(vetor_de_parametros *vp, Dados_entrada *dados_entrada) {
    double b, k;
    b = calcular_b(dados_entrada->N_b, dados_entrada->T_b, dados_entrada->S_b0, dados_entrada->I_b0); // comportamento de contágio
    k = calcular_k(dados_entrada->m_k, dados_entrada->n_k, dados_entrada->T_k);
    int tamanho_vp = (dados_entrada->dias * 24) / dados_entrada->h;
    double h = dados_entrada->h;
    
    int inicio = vp->p[0].tempo;
    
    // printf("%i %i \n", inicio, tamanho_vp);
    int entra = 1;
    for(int i = 0; i < tamanho_vp; i++) {
        if(vp->tamanho_atual >= vp->tamanho){
            vp = reallocar_vetor(vp);
        }  
        
        if(((int)dados_entrada->percepcao) == ((int)vp->p[i].tempo)) {
                if(entra && dados_entrada->T_b2 != 0) {
                    printf("%lf \n", b);
                    b = calcular_b(dados_entrada->N_b, dados_entrada->T_b2, vp->p[i].S0, vp->p[i].I0);
                    entra = 0;
                    printf("%lf \n", b);
                    printf("bbbbbbbbbbbbbbbb\n\n");
                } else if(entra && dados_entrada->T_k2 != 0) {
                    printf("%lf \n", k);
                    k = calcular_k(dados_entrada->m_k, dados_entrada->n_k, dados_entrada->T_k2);
                    entra = 0;
                    printf("%lf \n", k);
                    printf("kkkkkkkkkkkkkk\n\n");
                }
        }
        // printf("%lf | %lf | \n\n", vp->p[i].tempo, dados_entrada->percepcao);
              
        printf("%lf \n", b);
        vp->p[i+1].S0 = vp->p[i].S0 - h * (b * vp->p[i].S0 * vp->p[i].I0);
        vp->p[i+1].I0 = vp->p[i].I0 + (h * (b * vp->p[i].S0 * vp->p[i].I0 - k * vp->p[i].I0));
        vp->p[i+1].R0 = vp->p[i].R0 + h * k * vp->p[i].I0;
        vp->p[i+1].tempo = vp->p[i].tempo + h;
        vp->tamanho_atual++; 
        // printf("%i %i \n", inicio, tamanho_vp);
    }
}

void calcular_mec_sir_mortes(vetor_de_parametros *vp, Dados_entrada *dados_entrada) {
    double b, k;
    b = calcular_b(dados_entrada->N_b, dados_entrada->T_b, dados_entrada->S_b0, dados_entrada->I_b0); // comportamento de contágio
    k = calcular_k(dados_entrada->m_k, dados_entrada->n_k, dados_entrada->T_k);
    int tamanho_vp = (dados_entrada->dias * 24) / dados_entrada->h;
    double h = dados_entrada->h;
    
    int inicio = vp->p[0].tempo;

    // --------------------------
    vp->p->M0 = dados_entrada->R0 * 0.02;

    for(int i = 0; i < tamanho_vp; i++) {
        
        if(vp->tamanho_atual >= vp->tamanho){
            vp = reallocar_vetor(vp);
        }        
        
        vp->p[i+1].S0 = vp->p[i].S0 - h * (b * vp->p[i].S0 * vp->p[i].I0);
        vp->p[i+1].I0 = vp->p[i].I0 + (h * (b * vp->p[i].S0 * vp->p[i].I0 - k * vp->p[i].I0));
        vp->p[i+1].R0 = vp->p[i].R0 + h * k * vp->p[i].I0;

        // --------------------------
        vp->p[i+1].M0 = (vp->p[i].R0) * 0.02;

        vp->p[i+1].tempo = vp->p[i].tempo + h;
        vp->tamanho_atual++; 
        printf("%lf %lf %lf %lf %lf \n", vp->p[i].S0, vp->p[i].I0, vp->p[i].R0, vp->p[i].M0, vp->p[i].tempo);
    }
}