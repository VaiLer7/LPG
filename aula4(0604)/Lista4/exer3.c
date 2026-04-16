#include <stdio.h>
//Faça uma função que recebe um vetor e sua capacidade como parâmetros e retorna o somatório dos números primos contidos no vetor. Recomenda-se utilizar a função de verificação (se um número é primo ou não) já implemetada. Protótipo:
//int soma_primos(int v[], int n);

int ehprimo(int numero){
    int base = numero/2, primo=1;
    for(int i=0; i<base; i++){
        if(numero%2!=1){
            primo=0;
            break;
        }
    }
    return primo;
}

int soma_primos(int v[], int n){
    int soma=0;
    for(n--; n>=0; n--){
        if(ehprimo(v[n])) soma+=v[n];
    }
    return soma;
}

int main(){
    int termos;

    printf("quantidade de termos que tera o vetor: ");
    scanf("%d", &termos);

    int vetor[termos];
    printf("coloque os valores do vetor: \n");
    for(int i=0; i<termos; i++){
        scanf("%d", &vetor[i]);
    }

    int somatorio = soma_primos(vetor, termos);

    printf("A somatoria dos primos eh: %d", somatorio);

    getchar();
    getchar();
}