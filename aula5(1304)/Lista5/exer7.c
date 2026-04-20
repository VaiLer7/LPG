#include <stdio.h>
//Faça um programa que determine o menor valor de uma matriz 3x4, bem como suas coordenadas (linha e coluna). Tal processamento deve ser feito por uma função que recebe a matriz e “retorna” o menor elemento e suas coordenadas (i e j).


void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    *pMin=mat[0][0];
    *pI=1;
    *pJ=1;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(mat[i][j]<*pMin){
                *pMin=mat[i][j];
                *pI=i+1;
                *pJ=j+1;
            }
        }
    }
}

int main(){
    float mat[3][4], pMin;
    int pI, pJ;
    
    for(int i=0; i<=3; i++){

        if(i!=0){
            printf("Matriz atualmente: \n");
            for(int o=0; o<i; o++){
                printf("%.2f   %.2f   %.2f   %.2f\n", mat[o][0], mat[o][1], mat[o][2], mat[o][3]);
            }
        }
        if(i<3){
            printf("\nDigite os valores dos elementos da linha %d:\n", i+1);

            for(int j=0; j<4; j++){
                scanf("%f", &mat[i][j]);
            }
        }
    }

    min_matriz(mat, &pMin, &pI, &pJ);

    printf("\n\nO menor valor da matriz eh: %.2f\nE sua posicao eh na linha %d coluna %d", pMin, pI, pJ);

    getchar();
    getchar();
}