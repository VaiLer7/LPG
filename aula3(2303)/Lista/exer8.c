#include <stdio.h>
//Faça um programa que leia um inteiro n e determine a soma S da seguinte forma: 1 + 2 + 3 + 4 + ... + n. Escreva duas versões de funções: iterativa e recursiva.
int soma_re(int numero){
    if(numero<=1) return 1;

    return numero+soma_re(numero-1);
}

int main(){
    int numero, soma=0;

    printf("digite o numero: ");
    scanf("%d", &numero);
    for(int i=0; i<=numero; i++){
        soma+=i;
    }
    printf("soma iterativa (for): %d\n", soma);

    soma=(numero/2)*(numero+1);
    if(numero%2!=0) soma+=((numero+1)/2);
    printf("soma formula: %d\n", soma);

    soma=soma_re(numero);
    printf("soma recursiva: %d\n", soma);

    getchar();
    getchar();

}