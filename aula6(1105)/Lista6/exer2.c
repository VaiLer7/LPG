#include <stdio.h>

int possuiChar(char str[], char carac){
    int qtdd=0;
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]==carac) qtdd++;;
    }
    return qtdd;
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
        
    printf("a letra %c aparece %d vez(es) em %s", carac, bool, str);
    
    getchar();
    getchar();
}