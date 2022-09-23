# Prova 1 de Álgebra Linear Computacional

## **Questão 1**

Dados x, y ∊ R<sup>n</sup> e a ∊ R, escreva um algoritmo, com complexidade *O(n)*, que aloque em y o vetor ax + y.

~~~c
void alocaY(float * x, float * y, float a, int n){
    for(int i = 0; i < n; i++){
        printf("\n(%.1f * %.1f) + %.1f = ", a, x[i], y[i]);

        y[i] = (a * x[i]) + y[i];

        printf("%.1f", y[i]);
    }
}
~~~

## **Questão 2**

Sejam A ∊ R<sup>m x n</sup> e x 2 Rn. O vetor Ax consiste em

~~~c
void alocaY(float * x, float * y, float a, int n){
    for(int i = 0; i < n; i++){
        printf("\n(%.1f * %.1f) + %.1f = ", a, x[i], y[i]);

        y[i] = (a * x[i]) + y[i];

        printf("%.1f", y[i]);
    }
}

