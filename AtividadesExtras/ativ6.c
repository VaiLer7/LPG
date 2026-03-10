#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int tamanho = 100, j=0;
    char texto[tamanho];

    printf("digite o texto: ");
    fgets(texto, tamanho, stdin);

    for(int i=0; i<=strlen(texto); i++){
        if(!isdigit(texto[i])){
            texto[j]=texto[i];
            j++;
        }
    }
    printf("texto sem digitos: \n%s", texto);

    getchar();
    getchar();
}