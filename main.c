#include <stdio.h>
#include "calcular_mec_sir.h"

int main() {
    vetor_de_parametros *vp = create();
    double N_b, T_b, S_b0, I_b0, m_k, n_k, T_k, k, b, dias, h;

    /* Abre um arquivo texto para leitura. O arquivo deve existir antes de ser aberto. */
    entrada = fopen("entrada.csv", "r");

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 0;
    }

    // 68,2,0,0.1,12,24,50,10,6,22,24,21
    fscanf(entrada, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &vp->p->S0, &vp->p->I0, &vp->p->R0, &h, &N_b, &T_b, &S_b0, &I_b0, &m_k, &n_k, &T_k, &dias);
    fclose(entrada);

    vp->p->tempo = 0; // posição 0 é 0 -> tempo(0)=0
    
    int horas = (int) dias * 24;
    int fim = horas / h; // 500 / 0.1 = 5000
    
    b = calcular_b(N_b, T_b, S_b0, I_b0);
    k = calcular_k(m_k, n_k, T_k);  

    escrever_csv(vp, h, k, b, fim);
    imprimir_terminal(vp, h, k, b, fim);

    liberar_vetor_de_parametros(vp);

    return 0;
}
// gcc main.c calcular_mec_sir.c -o z.exe && ./z
// gcc main.c -o main.exe && ./main