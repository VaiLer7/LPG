#include <stdio.h>

int potenciacao(int, int);

int main(){
    int base, pot;

    printf("Qual o numero base: ");
    scanf("%d", &base);
    printf("Qual o numero potenciando: ");
    scanf("%d", &pot);

    int res=potenciacao(base, pot);

    printf("o resultado eh: %d", res);

    getchar();
    getchar();
}

int potenciacao(int base, int potencia){
    if(potencia==0){
        return 1;
    }

    return base * potenciacao(base, potencia-1);
}