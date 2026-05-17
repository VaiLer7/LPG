#include <stdio.h>
#include <string.h>

int comp(char[], char[]);

int main(){
    int tam;
    printf("digite o tamanho das strings: ");
    scanf("%d", &tam);
    char texto1[tam], texto2[tam];

    printf("escreva o texto 1: \n");
    getchar();
    fgets(texto1, tam, stdin);

    printf("\nescreva o texto 2: \n");
    fgets(texto2, tam, stdin);

    texto1[strlen(texto1)-1]=' ';
    texto2[strlen(texto2)-1]=' ';

    int val = comp(texto1, texto2);

    switch (val){
    case 1:
        printf("\n%s eh maior que %s\n", texto1, texto2);
        break;

    case -1:
        printf("\n%s eh maior que %s\n", texto2, texto1);
        break;

    case 0:
        printf("\nambos textos sao iguais\n");
        break;
    
    default:
        break;
    }
}

int comp(char texto1[], char texto2[]){
    int i=0;
    for(; texto1[i]!='\0'; i++){
        if(texto1[i]!=texto2[i]){
            if(texto1[i]>texto2[i]){
                return 1;
            }else{
                return -1;
            }
        }
    }
    if(texto2[i]!='\0') return -1;
    return 0;
}
