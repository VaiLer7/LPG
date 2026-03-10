#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int tamanho = 100;
    char texto[tamanho];

    printf("digite a frase: ");
    fgets(texto, tamanho, stdin);
    texto[0]=toupper(texto[0]);

    for(int i=1; texto[i]!='\0'; i++){
        if(texto[i-1]==' '){
            texto[i]= toupper(texto[i]);
        }else{
            texto[i] = tolower(texto[i]);
        }
    }
    printf("\n%s", texto);

    getchar();
    getchar();
}