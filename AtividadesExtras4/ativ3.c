#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("qual o tamanho do vetor: ");
    int tam;
    scanf("%d", &tam);

    int *vetor = malloc(tam*sizeof(int));

    printf("digite os valores:\n");
    for(int i=0; i<tam; i++){
        scanf("%d", vetor+i);
    }

    printf("\n");
    for(int i=0; i<tam; i++){
        printf("%d ", *(vetor+i));
    }
}