#include <stdio.h>
//Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e recursiva) para calcular o somatório que determina o valor da constante e:
//e=(1/0!)+(1/1!)+(1/2!)+(1/3!)+(1/4!)+...(1/n!)
double fatorial(int num){
    int valor=1;
    for(num>1;num!=0;num--){
        valor=valor*num;
    }
    return valor;
}

double serie_har(int numero){
    if(numero==0) return 1.0;

    return (1.0/fatorial(numero)) + serie_har(numero-1);
}

int main(){
    int numero;
    double soma=0, fat;

    do{
        printf("digite um numero maior que 0: ");
        scanf("%d", &numero);
    }while(numero<=0);
    
    printf("\nValor da constante e:\n");

    for(int i=0;i<=numero;i++){
        fat=fatorial(i);
        soma+=(1.0/fat);
    }
    printf("\nIterativo: %lf", soma);

    soma=0;
    soma=serie_har(numero);
    printf("\nRecursivo: %lf", soma);
    getchar();
    getchar();
}