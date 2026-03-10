#include <stdio.h>
#include <string.h>

int main(){
    int tamanho = 10, iguais=1;
    char texto1[tamanho], texto2[tamanho];

    printf("Digite o primeiro texto:\n");
    fgets(texto1, tamanho, stdin);
    printf("Digite o segundo texto:\n");
    fgets(texto2, tamanho, stdin);

    iguais = strcmp(texto1, texto2);
    printf("Os textos sao ");
    iguais == 0 ? printf("iguais") : printf("diferentes");
    
    getchar();
    getchar();
}