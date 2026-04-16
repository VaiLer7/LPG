#include <stdio.h>
//Escreva uma função que recebe dois vetores de mesma capacidade n e compara se os mesmos são iguais, ou seja, se contêm os mesmos valores e na mesma ordem. A função deve ser booleana, ou seja, se forem iguais retorna 1, caso contrário retorna 0. Protótipo da função:
//int compara(float a[], float b[], int n);

int compara(float a[], float b[], int n){
    for(n--; n>=0; n--){
        if(a[n]!=b[n]) return 0;
    }
    return 1;
}

int main(){
    int n;

    printf("qual sera o tamanho dos vetores? ");
    scanf("%d", &n);

    float a[n], b[n]; 

    printf("coloque os valores do vetor a: \n");
    for(int i=0; i<n; i++){
        scanf("%f", &a[i]);
    }
    printf("coloque os valores do vetor b: \n");
    for(int i=0; i<n; i++){
        scanf("%f", &b[i]);
    }

    printf("\nOs vetores ");
    
    int igual=compara(a, b, n);
    if(igual==0) printf("nao ");

    printf("sao iguais");

    getchar();
    getchar();
}