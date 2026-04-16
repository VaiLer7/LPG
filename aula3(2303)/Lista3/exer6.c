#include <stdio.h>
//Faça um programa que mostre na tela os n primeiros termos da sequência de Fibonacci. Por exemplo, dado n = 8, temos: 1, 1, 2, 3, 5, 8, 13 e 21. A determinação do n-ésimo termo da sequência deve ser feita por uma função iterativa que tem o seguinte protótipo:
//int fibo(int n);

int fibovetor(int termos){
    int vetor[termos++];
    vetor[0]=0;
    vetor[1]=1;
    
    printf("%d ", vetor[1]);
    for(int i=2; i<termos; i++){
        vetor[i]=vetor[i-1]+vetor[i-2];
        printf("%d ", vetor[i]);
    }

    return vetor[termos-1];
}

int fibo(int termos){
    int a=1, b=1, c=1;
    printf("%d ", a);
    if(termos>1) printf("%d ", b);
    for(int i=2; i<termos; i++){
        c=a+b;
        printf("%d ", c);
        a=b;
        b=c;
    }

    return c;
}

int main(){
    int termos, nesimo;

    printf("Digite quantos numeros deseja mostrar na tela da sequencia Fibonacci(>=1): ");
    scanf("%d", &termos);

    nesimo=fibovetor(termos);
    printf("\nValor do n-esimo termo eh (vetor): %d", nesimo);

    printf("\n\n");
    nesimo=fibo(termos);
    printf("\nValor do n-esimo termo eh (formula): %d", nesimo);

    getchar();
    getchar();
}