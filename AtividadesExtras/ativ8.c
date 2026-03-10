#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int tamanho = 100, j=0;
    char texto[tamanho];

    printf("Digite o texto: ");
    fgets(texto, tamanho, stdin);

    for(int i=0; texto[i]!='\0'; i++){
        // if(isupper(texto[i])||isdigit(texto[i])||ispunct(texto[i])){

        // }
        if(isupper(texto[i])){
            texto[j]=tolower(texto[i]);
            j++;
        }else if(!isdigit(texto[i])&&!ispunct(texto[i])){
            texto[j]=texto[i];
            j++;
        }
    }
    texto[j]='\0';
    printf("\n%s", texto);

    getchar();
    getchar();

}