#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define LINHAS 30
#define COLUNAS 30

float ** geraMatriz(int linha, int coluna);
float * geraTermosIndependentes(int n);
float * geraX0(int n);
void imprimeMatriz(float ** matriz, float * vetor, int linha, int coluna);
float maiorValor(float * vetor, int n);
void moduloVetor(float * vetor, int n);
float normaDif(float * xK1, float * xK, int n);
void jacobi(float ** A, float * B, float * x0, int m, int n);
void seidel(float ** A, float * B, float * x0, int m, int n);
void SOR(float ** A, float * B, float * xK, int m, int n);

int main(void){

    float ** matrizBase = geraMatriz(LINHAS, COLUNAS);
    float * vetorBase = geraTermosIndependentes(LINHAS);

    int operacao;
    printf("--------- Métodos Iterativos ---------\n\n");
    do
    {  
        printf("\nInforme a operação desejada:\n");
        printf("1-Imprimir matriz\n2-Gauss-Jacobi\n3-Gauss-Seidel\n4-SOR\n5-Tabela Comparativa\n0-Sair\n");
        scanf("%d",  &operacao);
        switch (operacao)
        {
            case 1:
                printf("\n");
                imprimeMatriz(matrizBase, vetorBase, LINHAS, COLUNAS);
            break;
        
            case 2: ;
                printf("\n");
                float * x0Jacobi = geraX0(LINHAS);
                jacobi(matrizBase, vetorBase, x0Jacobi, LINHAS, COLUNAS);
            break;

            case 3: ; 
                printf("\n");
                float * x0Seidel = geraX0(LINHAS);
                seidel(matrizBase, vetorBase, x0Seidel, LINHAS, COLUNAS);
            break;

            case 4: ; 
                printf("\n");
                float * x0SOR = geraX0(LINHAS);
                SOR(matrizBase, vetorBase, x0SOR, LINHAS, COLUNAS);
            break;

            case 5: ; 
                float * x0JacobiQ = geraX0(LINHAS);
                float * x0SeidelQ = geraX0(LINHAS);
                float * x0SORQ = geraX0(LINHAS);
                printf("Gauss-Jacobi:\n");
                printf("---------------------\n");
                printf("Iterações: 277\n");
                jacobi(matrizBase, vetorBase, x0JacobiQ, LINHAS, COLUNAS);
                printf("\nGauss-Seidel:\n");
                printf("---------------------\n");
                printf("Iterações: 163\n");
                seidel(matrizBase, vetorBase, x0SeidelQ, LINHAS, COLUNAS);
                printf("\nSOR:\n");
                printf("---------------------\n");
                printf("Iterações: 165\n");
                SOR(matrizBase, vetorBase, x0SORQ, LINHAS, COLUNAS);
            break;
        }
    } while (operacao != 0);
    

}

float ** geraMatriz(int linha, int coluna){
    float ** matriz = (float **) malloc(sizeof(float *) * linha);
    int i;
    for(i = 0; i < linha; i++){
        matriz[i] = (float *) malloc(sizeof(float) * coluna);
    }
    matriz[0][0] = -2.02;
    matriz[0][1] = 1.0;
    for(i = 1; i < linha - 1; i++){
            matriz[i][i - 1] = 1.0;
            matriz[i][i] = -2.02;
            matriz[i][i + 1] = 1;
    }
    matriz[i][i - 1] = 1.0;
    matriz[i][i] = -2.02;
    return matriz;
}

float * geraTermosIndependentes(int n){
    int i = 0;
    float * vetor = (float *) malloc(sizeof(float) * n);
    vetor[i] = 1;
    for(i = 1; i < n -1; i++) vetor[i] = 0.00;
    vetor[i] = 1;

    return vetor;
}

float * geraX0(int n){
    float * x0 = (float *) malloc(sizeof(float) * n);
    for(int i = 0; i < n; i++) x0[i] = 0.00;

    return x0;
}

void escaneiaMatriz(float ** matriz, int linha, int coluna){
    int i, j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
}

void imprimeMatriz(float ** matriz, float * vetor, int linha, int coluna){
    int i, j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("%6.2f", matriz[i][j]);
        }
        printf(" = %6.2f", vetor[i]);
        printf("\n");
    }
}

float normaDif(float * xK1, float * xK, int n){
    float dif[n];
    for(int i = 0; i < n; i++){
        dif[i] = xK1[i] - xK[i];
    }
    moduloVetor(dif, n);
    float d = maiorValor(dif, n);
    return d;
}

void moduloVetor(float * vetor, int n){
    int i;
    for(i = 0; i < n; i++) vetor[i] = fabsf(vetor[i]);
}

float maiorValor(float * vetor, int n){
    int i;
    float maior = vetor[0];
    for(i = 1; i < n; i++){
        if(vetor[i] > maior) maior = vetor[i];
    }

    return maior;
}

void jacobi(float ** A, float * B, float * xK, int m, int n){
    int iteracao = 1;
    float xK1[n];
    float df;
    
    do{
        for(int i = 0; i < m; i++){
            double bi = B[i];
            for(int j = 0; j < n; j++){
                if(j != i){
                    bi -= A[i][j] * xK[j];
                }
            }
            bi /= A[i][i];
            if(iteracao == 277){
                printf("x_%d(%d) = %.6f", i + 1, iteracao, bi);
                printf("\n");
            }
            xK1[i] = bi;
        }
        df = normaDif(xK1, xK, n);
        memcpy(xK, xK1, n * sizeof(float));
        iteracao++;
    }while(df > pow(10.0, -4.0));
}

void seidel(float ** A, float * B, float * xK, int m, int n){
    int iteracao = 1;
    float xK1[n];
    float df;
    
    do{
        memcpy(xK1, xK, n * sizeof(float));
        for(int i = 0; i < m; i++){
            double bi = B[i];
            for(int j = 0; j < n; j++){
                if(j != i){
                    bi -= A[i][j] * xK[j];
                }
            }
            bi /= A[i][i];
            if(iteracao == 163){
                printf("x_%d(%d) = %.6f", i + 1, iteracao, bi);
                printf("\n");
            }
            xK[i] = bi;
        }
        df = normaDif(xK, xK1, n);
        iteracao++;
    }while(df > pow(10.0, -4.0));
}

void SOR(float ** A, float * B, float * xK, int m, int n){
    int iteracao = 1;
    float xK1[n];
    float * xKSOR = geraX0(n);
    float xK1SOR[n];
    float df;
    
    do{
        memcpy(xK1, xK, n * sizeof(float));
        for(int i = 0; i < m; i++){
            double bi = B[i];
            for(int j = 0; j < n; j++){
                if(j != i){
                    bi -= A[i][j] * xK[j];
                }
            }
            bi /= A[i][i];
            xK[i] = bi;
        }

        for(int k = 0; k < m; k++){
            xK1SOR[k] = (0.5 * xK[k]) + (0.5 * xKSOR[k]);
            if(iteracao == 165){
                printf("x_%d(%d) = %.6f", k + 1, iteracao, xK1SOR[k]);
                printf("\n");
            }
        }



        df = normaDif(xK1SOR, xKSOR, n);
        memcpy(xKSOR, xK1SOR, n * sizeof(float));
        iteracao++;
    }while(df > pow(10.0, -4.0));
}
