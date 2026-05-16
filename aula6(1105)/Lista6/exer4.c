#include <stdio.h>
#include <string.h>

int palindrome(char[]);

int main(){
    int tam;
    printf("qual o tamanho da palavra: ");
    scanf("%d", &tam);

    char vetor[tam];

    printf("insira a palavra: ");
    scanf("%s", vetor);

    int eh_pali=palindrome(vetor);

    printf("A palavra '%s' ", vetor);
    if(eh_pali==0) printf("nao ");
    printf("eh palidromo");

    getchar();
    getchar();
}

int palindrome(char str[]){
    int f=strlen(str)-1;
    int i=0;
    for(;f-i>1;){
        if(str[i]!=str[f]) return 0;
        f--;
        i++;
    }
    return 1;
}