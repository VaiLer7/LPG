#include <stdio.h>
//Escreva um programa que determine o maior valor de um vetor bem como sua posição no vetor (índice). Tal processamento deve ser feito em uma função que recebe o vetor (do tipo float) e sua capacidade, e “retorna” o maior elemento e sua posição.


void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    *pMax=vet[0];
    *pIndice=0;
    for(int i=1; i<tam; i++){
        if(vet[i]>*pMax){
            *pMax=vet[i];
            *pIndice=i;
        }
    }
}

int main(){
    int tam, pIndice;
    float pMax;

    printf("qual o tamanho do vetor: ");
    scanf("%d", &tam);
    float vet[tam];

    printf("insira os valores dentro do vetor:\n");
    for(int i=0; i<tam; i++){
        scanf("%f", &vet[i]);
    }

    max_vetor(vet, tam, &pMax, &pIndice);

    printf("\nO maior valor dentro do vetor eh: %.2f, na posicao: %d do vetor", pMax, pIndice);

    getchar();
    getchar();
}