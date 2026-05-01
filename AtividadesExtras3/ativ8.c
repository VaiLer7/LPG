#include <stdio.h>

int palindromo(char[], int, int);

int main(){
    char texto[50];
    int tamanho=0, atual=0;

    printf("insira a palavra(max 50 caracteres): ");
    scanf("%s", texto);

    for(; texto[tamanho]!='\0'; tamanho++);

    int pali = palindromo(texto, tamanho-2, atual);
    
    printf("a palavra %s ", texto);
    if(pali==0) printf("nao ");
    printf("eh palindromo");

    getchar();
    getchar();
}

int palindromo(char texto[], int tamanho, int atual){
    if(texto[atual]!=texto[tamanho]){
        return 0;
    }
    if(tamanho-atual<2){
        return 1;
    }

    return palindromo(texto, tamanho-1, atual+1);
}