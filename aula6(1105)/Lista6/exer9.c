#include  <stdio.h>
#include <string.h>

void trim(char[]);

int main(){
    int tam;
    printf("qual sera o tamanho da frase: ");
    scanf("%d", &tam);
    char texto[tam];

    printf("digite a frase: ");
    getchar();
    fgets(texto, tam, stdin);

    trim(texto);

    printf("\no mesmo texto sem os espaços iniciais e finais:\n%s", texto);
}

void trim(char texto[]){
    printf("\n\n\n%s", texto);
    for(int i=0; texto[i]==' '; i++){
        if(texto[i+1]!=' ' && i>0){
            int j=0;
            for(; texto[j]!='\0'; j++){
                texto[j]=texto[i+j+1];
            }
            texto[j]='\0';
        }
    }
    printf("\n\n\n%s", texto);

    int tam = strlen(texto)-2; //'-2' para tirar o "\0" e "\n"
    for(int i=tam; texto[i]==' '; i--){
        if(texto[i-1]!=' ' && i<tam){
            texto[i]='\0';
        }
    }
    printf("\n\n\n%s", texto);
}