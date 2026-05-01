#include <stdio.h>
#include <string.h>

char invertor(char[], int, int);

int main(){
    char texto[50];
    int tamanho=0, atual=0;

    printf("insira texto(max 50 caracteres): ");
    fgets(texto, 50, stdin);

    for(; texto[tamanho]!='\0'; tamanho++);

    invertor(texto, tamanho-2, atual);
    
    printf("\n%s", texto);

    getchar();
    getchar();
}

char invertor(char texto[], int tamanho, int atual){
    if(tamanho-atual<2){
        return 0;
    }
    char aux=texto[atual];
    texto[atual]=texto[tamanho];
    texto[tamanho]=aux;

    return invertor(texto, tamanho-1, atual+1);
}