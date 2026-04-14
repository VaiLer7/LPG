#include <stdio.h>
//Implemente a série de Taylor para calcular a função exponencial e^(x):

int fatorial(int num){
    int valor=1;
    for(num>1;num!=0;num--){
        valor=valor*num;
    }
    return valor;
}

int expo(int num, int qtdd){
    int valor=num;
    if(qtdd==0) return 1;
    for(int i=1; i<qtdd; i++){
        valor=valor*num;
    }
    return valor;
}

int main(){
    int qtdd, fat, dividendo, X;

    printf("quantidade de termos: ");
    scanf("%d", &qtdd);
    printf("valor de X ");
    scanf("%d", &X);

    float ValorE=0, termo;
    for(int i=0; i<qtdd; i++){
        fat=fatorial(i);
        dividendo=expo(X, i);
        termo=(float)dividendo/(float)fat;
        ValorE=ValorE+(termo);
    }
    printf("%f", ValorE);

    getchar();
    getchar();
}