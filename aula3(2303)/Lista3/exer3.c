#include <stdio.h>
//Escreva um programa que informa se um caractere digitado pelo usuário representa um dígito de 0 a 9. A verificação deve ser feita por uma função booleana (int) que recebe um char como parâmetro. Caso o caractere seja um dígito, converta-o para um valor inteiro e o armazene em uma variável int. Em seguida, mostre o valor inteiro na tela.

int ehdigito(char caractere){
    return (caractere>=48&&caractere<=57) ? 1 : 0;
}

int main(){
    int Digito, Valor;
    char caractere[1];

    printf("Digite a caractere: ");
    scanf("%c", caractere);
    Digito=ehdigito(caractere[0]);

    if(Digito){
        Valor=caractere[0] - '0';
        printf("Eh Digito: %d", Valor);
    }else{
        printf("Nao eh Digito");
    }

    getchar();
    getchar();
}