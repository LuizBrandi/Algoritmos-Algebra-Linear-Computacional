#include <stdio.h>
#include <stdlib.h>

float ** alocaMatriz(int linha, int coluna);
void escaneiaMatriz(float ** matriz, int linha, int coluna);
void escaneiaVetor(float * vetor, int n, char c);
void imprimeMatriz(float ** matriz, int linha, int coluna);
void zeraVetor(float * vetor, int tamanho);
void alocaY(int m, int n, float ** matriz, float * x, float * y);

int main(void){
    int linhas, colunas;
    printf("Informe a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("Informe a quantidade de colunas: ");
    scanf("%d", &colunas);

    float ** matriz = alocaMatriz(linhas, colunas);
    printf("\nInforme os valores da matriz A: \n");
    escaneiaMatriz(matriz, linhas, colunas);
    printf("\n");
    imprimeMatriz(matriz, linhas, colunas);
    printf("\n");
    float vX[colunas];
    float vY[colunas];

    printf("Informe os valores dos vetores:\n");
    escaneiaVetor(vX, colunas, 'X');
    escaneiaVetor(vY, colunas, 'Y');
    alocaY(linhas, colunas, matriz, vX, vY);

    printf("\nVetor Y:");
    for(int i = 0; i < colunas; i++) printf(" %.1f", vY[i]);
    printf("\n");
}

void alocaY(int m, int n, float ** matriz, float * x, float * y){
    float Ax[m];
    zeraVetor(Ax, m);
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            Ax[j] += matriz[j][i] * x[i];
        }
    }
    for(int i = 0; i < m; i++) y[i] += Ax[i];
}

float ** alocaMatriz(int linha, int coluna){
    float ** matriz = (float **) malloc(sizeof(float *) * linha);
    int i;
    for(i = 0; i < linha; i++){
        matriz[i] = (float *) malloc(sizeof(float) * coluna);
    }
    return matriz;
}

void escaneiaMatriz(float ** matriz, int linha, int coluna){
    int i, j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void imprimeMatriz(float ** matriz, int linha, int coluna){
    int i, j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("%6.1f", matriz[i][j]);
        }
        printf("\n");
    }
}

void escaneiaVetor(float * vetor, int n, char c){
    for(int i = 0; i < n; i++){
        printf("Valor do vetor %c na posição [%d]: ", c, i);
        scanf("%f", &vetor[i]);
    } 
}

void zeraVetor(float * vetor, int tamanho){
    for(int i = 0; i < tamanho; i++) vetor[i] = 0.0;
}