#include <stdio.h>

int maior(int[], int, int);

int main(){
    int tam;

    printf("Qual sera o tamanho do vetor: ");
    scanf("%d", &tam);
    int vet[tam];

    printf("Insira os valores no vetor: \n");
    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }

    int Nmaior=maior(vet, tam-1, vet[0]);

    printf("o maior numero eh: %d", Nmaior);

    getchar();
    getchar();
}

int maior(int vet[], int tam, int Nmaior){
    if(tam==0) return Nmaior;

    if(vet[tam]>Nmaior) Nmaior=vet[tam];

    return maior(vet, tam-1, Nmaior);
}