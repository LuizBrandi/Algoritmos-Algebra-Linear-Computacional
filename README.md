# Prova 1 de Álgebra Linear Computacional

<font size="5">Questão 1 </font>

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
<font size="5">Questão 2 </font>

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

<font size="1">Questão 3 </font>

Sejam A ∊ R<sup>m x n</sup> e x ∊ R<sup>n</sup>. O vetor Ax consiste numa combinação
linear das colunas de A, cujas coordenadas da combinação são as componentes de x, isto é,

![CursoemVideo](img/matriz-questao3.png)

Dados A ∊ R<sup>m x n</sup>, x ∊ R<sup>n</sup> e y ∊ R<sup>m</sup>, escreva um algoritmo, levando em consideração a operação
descrita, que aloque em y o vetor Ax + y. 

~~~c
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
~~~