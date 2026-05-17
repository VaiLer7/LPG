#include <stdio.h>
#include <string.h>

void apagar(char, char[]);

int main(){
    int tam;
    printf("digite o tamanho da string: ");
    scanf("%d", &tam);
    char texto[tam];

    printf("escreva o texto: \n");
    getchar();
    fgets(texto, tam, stdin);

    char carac;
    printf("qual caractere deseja apagar: ");
    scanf("%c", &carac);
    apagar(carac, texto);

    printf("texto sem a caractere '%c':\n%s\n", carac, texto);
}

void apagar(char carac, char texto[]){
    int soma=0, i=0;

    for(; texto[i]!='\0'; i++){
        if(texto[i]==carac){
            soma++;
        }else{
            texto[i-soma]=texto[i];
        }
    }
    texto[i-soma]='\0';
}