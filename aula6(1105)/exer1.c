#include <stdio.h>

int possuiChar(char str[], char carac){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]==carac) return 1;
    }
    return 0;
}

int main(){
    int tamanho;

    printf("qual o tamanho da string: ");
    scanf("%d", &tamanho);
    char str[tamanho], carac;

    printf("insira o texto: ");
    scanf("%s", str);

    getchar();
    printf("caractere para ser procurado: ");
    scanf("%c", &carac);

    int bool = possuiChar(str, carac);
        
    printf("%s ", str);
    if(bool==0) printf("nao ");
    printf("possui a letra %c", carac);
    
    getchar();
    getchar();
}