#include <stdio.h>
#include <stdlib.h>

int *diagonal_secundaria( int **matriz, int tam);

int main(){
    int tam;

    printf("qual sera o tamanho da matriz quadrada: ");
    scanf("%d", &tam);

    int **matriz;

    matriz = malloc(tam*sizeof(int *));

    for(int i=0; i<tam; i++){
        matriz[i]=malloc(sizeof(int));
    }

    printf("preencha a matriz:\n");

    for(int i=0; i<tam; i++){
        int valor;
        for(int j=0; j<tam; j++){
            scanf("%d", &valor);
            matriz[i][j]=valor;
        }
    }

    int *vetor = diagonal_secundaria(matriz, tam);

    printf("\n\n");
    
    for(int i=0; i<tam; i++){
        printf("%d ", *(vetor++));
    }
}

int *diagonal_secundaria( int **matriz, int tam){

    
    int *vetor = malloc(tam*sizeof(int));
    
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            if(i==j){
                vetor[i]=matriz[i][j];
            }
        }
    }

    return vetor;
}