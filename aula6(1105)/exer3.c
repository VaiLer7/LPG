#include <stdio.h>
#include <string.h>

int pow(int base, int expo);
int SomenteNum(char[]);
int conversao(char[]);

int SomenteNum(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]<'0' || str[i]>'9') return 0;
    }
    return 1;
}

int conversao(char stringue[]){
    int valor=0;
    int tamanho = pow(10, strlen(stringue)-1);
    for(int i=0; stringue[i]!='\0'; i++){
        valor+=(stringue[i]-'0')*tamanho;
        tamanho=(tamanho/10);
    }
    return valor;
}

int pow(int base, int expo){
    if(expo==0) return 1;

    return base * pow(base, expo-1);
}

int main(){
    int tamanho;

    printf("qual o tamanho da string: ");
    scanf("%d", &tamanho);
    char str[tamanho], carac;

    printf("insira o texto: ");
    scanf("%s", str);

    int bool = SomenteNum(str);

    if(bool==0){
        printf("%s nao possui somente numeros", str);
    }else{
        int valor = conversao(str);

        printf("valor: %d", valor);
    }
    
    getchar();
    getchar();
}