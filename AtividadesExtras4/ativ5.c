#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("insira a quantidade de numeros: ");
    int tam;
    scanf("%d", &tam);

    int *vetor = malloc(tam*sizeof(int));

    int total=0, *local;
    for(int i=0; i<tam; i++){
        local=vetor+i;

        scanf("%d", local);

        total+=*local;
    }

    printf("\nvalor total: %d", total);
}