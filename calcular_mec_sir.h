#include <stdio.h>
// prototipo de funções, tipos de ponteiros, dados globalmente acessíveis 
FILE *entrada;

typedef struct parametros_type {
    double S0; 
    double I0; 
    double R0; 
    double tempo;
} Parametros;

typedef struct vetor_de_parametros_type {
    int tamanho_atual;
    Parametros *p;
} vetor_de_parametros;

vetor_de_parametros *create();
vetor_de_parametros *reallocar_vetor(vetor_de_parametros *vetor_de_params);

double calcular_b(double N_b, double T_b, double S_b0, double I_b0);
double calcular_k(double m_k, double n_k, double T_k);

void escrever_csv(vetor_de_parametros *vp, double h, double k, double b, int fim);
void imprimir_terminal(vetor_de_parametros *vp, double h, double k, double b, int fim);
void liberar_vetor_de_parametros(vetor_de_parametros *vp);


