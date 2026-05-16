#include <stdio.h>

int soNum(char[]);

int main(){
    int tam;

    printf("qual o tamanho da string: ");
    scanf("%d", &tam);
    char str[tam];

    printf("insira a string: ");
    scanf("%s", str);

    int bool=soNum(str);

    printf("a string %s ", str);
    if(bool==0) printf("nao ");
    printf("tem so numero");

    getchar();
    getchar();
}

int soNum(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]<48||str[i]>57) return 0;
    }
    return 1;
}