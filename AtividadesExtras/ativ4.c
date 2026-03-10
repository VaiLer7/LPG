#include <stdio.h>
#include <string.h>

int main(){
    int tamanho = 10;
    char texto[tamanho], memoria;
    fgets(texto, tamanho, stdin);
    int qtdd = strlen(texto)-1;
    for(int i = 0; qtdd/2>=i; i++){
        memoria = texto[i];
        texto[i] = texto[qtdd-i];
        texto[qtdd-i] = memoria;
    }
    printf("\n%s", texto);

    getchar();
    getchar();
}