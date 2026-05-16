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
    texto[strlen(texto)-1]=' '; //substituindo o '\n' por espaço (' ') para melhor visualização
    printf("|%s|", texto);

    trim(texto);

    printf("\no mesmo texto sem os espaços iniciais e finais:\n|%s|\n\n", texto);
}

void trim(char texto[]){
    int i=0;
    for(; texto[i]==' '; i++);
    if(i>0){
        int j=0;
        for(; texto[i+j]!='\0'; j++){
            texto[j]=texto[i+j];
        }
        texto[j]='\0';
    }

    int tam = strlen(texto)-2; //'-2' para tirar o "\0" e "\n"
    i=tam;
    for(; texto[i]==' '; i--);
    if(i<tam){
        texto[i+1]='\0';
    }
}