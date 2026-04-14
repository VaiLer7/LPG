#include <stdio.h>
//Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e recursiva) para determinar a soma S da série harmônica definida a seguir:
//S=1+(1/2)+(1/3)+(1/4)+...+(1/n)
double serie_har(int numero){
    if(numero==1) return 1.0;

    return (1.0/numero) + serie_har(numero-1);
}

int main(){
    int numero;
    double soma=0;

    do{
        printf("digite um numero maior que 0: ");
        scanf("%d", &numero);
    }while(numero<=0);
    
    printf("\nSerie Harmonica:\n");

    for(int i=1;i<=numero;i++){
        soma+=(1.0/i);
    }
    printf("\nIterativo: %lf", soma);

    soma=0;
    soma=serie_har(numero);
    printf("\nRecursivo: %lf", soma);
    getchar();
    getchar();
}