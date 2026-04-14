#include <stdio.h>
//Faça um programa que mostre na tela os n primeiros termos da sequência de Fibonacci. Por exemplo, dado n = 8, temos: 1, 1, 2, 3, 5, 8, 13 e 21. A determinação do n-ésimo termo da sequência deve ser feita por uma função iterativa que tem o seguinte protótipo:
//int fibo(int n);

int fibo(int termos){
    int vetor[termos];
    vetor[-1]=0;
    vetor[0]=1;
    printf("1 ");
    for(int i=1; i<termos; i++){
        vetor[i]=vetor[i-1]+vetor[i-2];
        printf("%d ", vetor[i]);
    }
    return vetor[termos-1];
}

int main(){
    int termos, nesimo;

    printf("Digite quantos numeros deseja mostrar na tela da sequencia Fibonacci(>1): ");
    scanf("%d", &termos);

    nesimo=fibo(termos);
    printf("\nValor do n-esimo termo eh: %d", nesimo);

    getchar();
    getchar();
}