#include <stdio.h>

void concatena(char[], char[]);

int main(){
    int tam1, tam2;

    printf("quan sera o tamanho da string 1 e 2: \n");
    scanf("%d %d", &tam1, &tam2);
    char str1[tam1+tam2], str2[tam2];

    printf("preencha a string 1 e 2: \n");
    scanf("%s %s", str1, str2);

    concatena(str1, str2);

    printf("\n%s", str1);
}
void concatena(char str1[], char str2[]){
    int pos=0, i=0;
    for(;str1[pos]!='\0'; pos++);
    for(;str2[i]!='\0'; i++) str1[pos+i]=str2[i];
    str1[pos+i]='\0';
}