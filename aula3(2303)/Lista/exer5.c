#include <stdio.h>
//Faça um programa que, dados k e n, mostre na tela os n primeiros números primos acima de k. A verificação do número (se é ou não é primo) deve ser feita através de uma função.

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

int main(){
    int Quantidade, Numero;

    printf("Numero pra comecar: ");
    scanf("%d", &Numero);
    printf("Quantidade primos pra mostrar: ");
    scanf("%d", &Quantidade);

    for(int i=0;i<Quantidade; Numero++){
        if(ehprimo(Numero)){
            i++;
            printf("%d ", Numero);
        }
    }
    getchar();
    getchar();
}