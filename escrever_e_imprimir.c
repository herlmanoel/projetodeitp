#include <stdio.h>
#include "calculo_cenarios.h"

void escrever_csv(vetor_de_parametros *vp, char *caminho_saida) {
    FILE *saida;
    
    saida = fopen(caminho_saida, "w"); // apaga o conteúdo
    fclose(saida);
    
    for(int i = 0; i < vp->tamanho_atual; i++) {
        saida = fopen(caminho_saida, "a");
        fprintf(saida, "%lf,%lf,%lf,%lf\n", vp->p[i].S0, vp->p[i].I0, vp->p[i].R0, vp->p[i].tempo);
        fclose(saida);
    }
}

void escrever_csv_mortes(vetor_de_parametros *vp, char *caminho_saida) {
    FILE *saida;
    
    saida = fopen(caminho_saida, "w"); // apaga o conteúdo
    fclose(saida);
    
    for(int i = 0; i < vp->tamanho_atual; i++) {
        saida = fopen(caminho_saida, "a");
        fprintf(saida, "%lf,%lf,%lf,%lf,%lf\n", vp->p[i].S0, vp->p[i].I0, vp->p[i].R0, vp->p[i].M0, vp->p[i].tempo);
        fclose(saida);
    }
}

void imprimir_terminal(vetor_de_parametros *vp) {
     for(int i = 0; i < vp->tamanho_atual; i++) {
        printf("%lf %lf %lf %lf \n", vp->p[i].S0, vp->p[i].I0, vp->p[i].R0, vp->p[i].tempo);
    }
}