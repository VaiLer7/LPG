#include <stdio.h>

void Maior(char[], int);

int main(){
    int tam;

    printf("qual o tamanho da string: ");
    scanf("%d", &tam);
    char str[tam];
    
    printf("insira a string: ");
    scanf("%s", str);

    Maior(str, 0);


    printf("\nString com letras maiusculas: %s", str);
    getchar();
    getchar();
}

void Maior(char str[], int numero){
    if(str[numero]>96&&str[numero]<124) str[numero]-=32;

    if(str[numero]!='\0') return Maior(str, numero+1);
}
