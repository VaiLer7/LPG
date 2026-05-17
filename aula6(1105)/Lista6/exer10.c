#include <stdio.h>
#include <string.h>

void invertor(char[]);

int main(){
    int tam;
    printf("digita o tamanho da string: ");
    scanf("%d", &tam);
    char texto[tam];

    printf("digite o texto:\n");
    scanf("%s", texto);

    invertor(texto);

    printf("\n%s", texto);
}

void invertor(char texto[]){
    int tam=strlen(texto)-1;
    char aux;

    for(int i=0; tam-i>0; i++){
        aux=texto[tam];
        texto[tam--]=texto[i];
        texto[i]=aux;
    }
}