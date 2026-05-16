#include <stdio.h>

int SomenteNum(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]<'0' || str[i]>'9') return 0;
    }
    return 1;
}

int main(){
    int tamanho;

    printf("qual o tamanho da string: ");
    scanf("%d", &tamanho);
    char str[tamanho], carac;

    printf("insira o texto: ");
    scanf("%s", str);

    int bool = SomenteNum(str);
        
    printf("'%s' ", str);
    if(bool==0) printf("nao ");
    printf("possui somente numeros");
    
    getchar();
    getchar();
}