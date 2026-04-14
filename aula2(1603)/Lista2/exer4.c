#include <stdio.h>
//Implemente o programa para determinar o valor da constante e:

int fatorial(int num){
    int valor=1;
    for(num>1;num!=0;num--){
        valor=valor*num;
    }
    return valor;
}

int main(){
    int qtdd, fat;

    printf("quantidade de termos: ");
    scanf("%d", &qtdd);
    float ValorE=0;
    for(int i=0; i<qtdd; i++){
        fat=fatorial(i);
        ValorE=ValorE+(1.0/fat);
    }
    printf("%f", ValorE);

    getchar();
    getchar();
}