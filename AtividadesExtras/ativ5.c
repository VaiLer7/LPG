#include <stdio.h>
#include <string.h>

int main(){
    int tamanho = 10, iguais=1;
    char texto1[tamanho], texto2[tamanho];

    printf("Digite o primeiro texto:\n");
    fgets(texto1, tamanho, stdin);
    printf("Digite o segundo texto:\n");
    fgets(texto2, tamanho, stdin);

    int maior = (strlen(texto1)>=strlen(texto2)) ? strlen(texto1) : strlen(texto2);
    for(int i=0; i<=maior; i++){
        if(texto1[i]!=texto2[i]){
            iguais = 0;
            break;
        }
    }
    printf("Os textos sao ");
    iguais == 1 ? printf("iguais") : printf("diferentes");
    
    getchar();
    getchar();
}