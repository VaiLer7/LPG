#include <stdio.h>
//Escreva uma função que troca os valores entre duas variáveis do tipo float. Faça um programa que leia duas variáveis e mostre seus valores na tela. Em seguida, troque os valores (usando a função) e mostre novamente os valores.

void troca_valor(float *a, float *b){
    float ponte = *a;
    *a=(*b);
    *b=ponte;
}

int main(){
    float a, b;

    printf("digite os numeros:\n");
    scanf("%f %f", &a, &b);

    troca_valor(&a, &b);

    printf("\nvalores trocados:\n%.2f\n%.2f", a, b);

    getchar();
    getchar();
}