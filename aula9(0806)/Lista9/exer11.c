#include <stdio.h>
#include <stdlib.h>

int **matriz(int, int);
int **mult_matrizes(int **matrizA, int **matrizB, int linhasA, int colunasA, int linhasB, int colunasB);
int *func_coluna(int**, int, int);

int main(){
    int l1, c1, l2, c2;

    printf("quantas linha deseja ter na matriz A: ");
    scanf("%d", &l1);

    printf("quantas colunas deseja ter na matriz A: ");
    scanf("%d", &c1);

    printf("Digite os valores dentro da matriz:\n");
    int **matrizA = matriz(l1, c1);


    printf("quantas linha deseja ter na matriz B: ");
    scanf("%d", &l2);

    printf("quantas colunas deseja ter na matriz B: ");
    scanf("%d", &c2);

    printf("Digite os valores dentro da matriz:\n");
    int **matrizB = matriz(l2, c2);


    if(!(c1==l2)){
        printf("dimensoes incompativeis de matriz!\n");
        return 0;
    }


    int **matrizR = mult_matrizes(matrizA, matrizB, l1, c1, l2, c2);


    printf("Matriz resultante:\n");
    for(int i=0; i<l1; i++){
        for(int j=0; j<c2; j++){
            printf("%d ", matrizR[i][j]);
        }
        printf("\n");
    }
}

int **matriz(int linha, int coluna){
    int **matriz;

    matriz = malloc(linha * sizeof(int *));

    for(int i = 0; i < linha; i++){
        matriz[i] = malloc(coluna * sizeof(int));
    }

    for(int i = 0; i < linha; i++){
        printf("\nLinha %d:\n", i);
        for(int j = 0; j < coluna; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}

#include <stdlib.h>

int **mult_matrizes(int **matrizA, int **matrizB, int linhasA, int colunasA, int linhasB, int colunasB){
    int **resultado = malloc(linhasA * sizeof(int *));
    if (resultado == NULL)
        return NULL;

    for (int i = 0; i < linhasA; i++) {
        resultado[i] = malloc(colunasB * sizeof(int));

        if (resultado[i] == NULL) {
            while (--i >= 0)
                free(resultado[i]);
            free(resultado);
            return NULL;
        }
    }

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            resultado[i][j] = 0;

            for (int k = 0; k < colunasA; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    return resultado;
}

int *func_coluna(int **matriz, int atual, int linhas){
    int *vetor = malloc(linhas*sizeof(int));

    for(int i=0; i<linhas; i++){
        vetor[i]=matriz[i][atual];
    }

    return vetor;
}