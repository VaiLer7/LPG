#include <stdio.h>
#include <string.h>

int main(){
    int tamanho = 12, isPali = 1, qtdd;  
    char texto1[tamanho];

    printf("Digite o primeiro texto: ");
    fgets(texto1, tamanho, stdin);

    qtdd = strlen(texto1)-1;
    for(int i = 0; qtdd/2>=i; i++){
        if(texto1[i] != texto1[qtdd-i]){
            isPali = 0;
            break;
        }
    }
    if(isPali==0) printf("NAO E ");
    printf("PALINDROMO");

    getchar();
    getchar();
}