#include <stdio.h>

int soma_digitos(char[], int);

int main(){
    char numero[100];
    int tamanho=0;

    printf("digite o numero a ser somado seus digitos(ate 100 digitos): ");
    scanf("%s", numero);

    for(; numero[tamanho]!='\0'; tamanho++);

    int res = soma_digitos(numero, tamanho);

    printf("A soma dos digitos internos eh: %d", res);

    getchar();
    getchar();
}

int soma_digitos(char numeros[], int tamanho){
    if(tamanho==0){
        return 0;
    }
    tamanho--;

    return (numeros[tamanho] - '0') + soma_digitos(numeros, tamanho);
}