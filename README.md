# Prova 1 de Álgebra Linear Computacional

<h2> Questão 1 </h2>

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

<h2> Questão 2 </h2>

Sejam A ∊ R<sup>m x n</sup> e x ∊ Rn. O vetor Ax consiste em

![CursoemVideo](img/matriz-questao2.png)

Dados A ∊ R<sup>m x n</sup>, x ∊ R<sup>n</sup> e y ∊ R<sup>m</sup>, escreva um algoritmo, levando em consideração a operação
descrita, que aloque em y o vetor Ax + y. 

~~~c
void alocaY(int m, int n, float ** matriz, float * x, float * y){
    float Ax[m];
    zeraVetor(Ax, m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            Ax[i] += (matriz[i][j] * x[j]);
        }
        y[i] = Ax[i] + y[i];
    }
}
~~~