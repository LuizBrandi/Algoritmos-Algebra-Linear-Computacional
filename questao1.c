#include <stdio.h>

void alocaY(float * x, float * y, float a, int n);
void escaneiaVetor(float * vetor, int n, char c);

int main(void){
    int tamanho;

    printf("Informe o tamanho dos vetores:\n");
    scanf("%d", &tamanho);

    float vX[tamanho];
    float vY[tamanho];
    float constante;

    printf("Informe os valores:\n");
    escaneiaVetor(vX, tamanho, 'X');
    escaneiaVetor(vY, tamanho, 'Y');

    printf("Informe o valor da constante real: ");
    scanf("%f", &constante);

    alocaY(vX, vY, constante, tamanho);
    
    printf("\n\nVetor Y:");
    for(int i = 0; i < tamanho; i++) printf(" %.1f", vY[i]);
    printf("\n");
}

void alocaY(float * x, float * y, float a, int n){
    for(int i = 0; i < n; i++){
        printf("\n(%.1f * %.1f) + %.1f = ", a, x[i], y[i]);

        y[i] = (a * x[i]) + y[i];

        printf("%.1f", y[i]);
    }
}

void escaneiaVetor(float * vetor, int n, char c){
    for(int i = 0; i < n; i++){
        printf("Valor do vetor %c na posição [%d]: ", c, i);
        scanf("%f", &vetor[i]);
    } 
}

