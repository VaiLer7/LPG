#include <stdio.h>
//Escreva uma função que recebe um vetor e sua capacidade como parâmetros e precisa “retornar” o maior e o menor valores do vetor.

void max_min(int vet[], int tam, int *pMin, int *pMax){
    *pMin=vet[0];
    *pMax=vet[0];
    for(int i=1; i<tam; i++){
            if(vet[i]>*pMax){ *pMax=vet[i];
        }else{
            if(vet[i]<*pMin) *pMin=vet[i];
        }
    }
}

int main(){
    int tam, pMin,pMax;

    printf("insira o tamanho do vetor: ");
    scanf("%d", &tam);

    int vet[tam];
    printf("\ninsira os valores do vetor:\n");
    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }

    max_min(vet, tam, &pMin, &pMax);

    printf("\nmaior valor no vetor: %d\nmenor valor no vetor: %d", pMax, pMin);

    getchar();
    getchar();
}