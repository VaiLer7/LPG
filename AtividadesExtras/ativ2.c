#include <stdio.h>
#include <ctype.h>

int main(){
    int tamanho = 10;
    char texto[tamanho];

    fgets(texto, tamanho, stdin);
    for(int i=0; texto[i]!='\0'; i++){
        texto[i]=toupper(texto[i]);
    }
    printf("%s", texto);

    getchar();
    getchar();

}