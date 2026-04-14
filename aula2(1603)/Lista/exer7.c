#include <stdio.h>
//Escreva um algoritmo que determine o valor aproximado do cosseno de x com base na série abaixo. O número de termos da série bem como o valor de x são determinados pelo usuário. Obs.: para a potenciação, não é permitido o uso de funções ou operadores predefinidos.

double fatorial(int num){
    double valor=1;
    for(;num>1;num--){
        valor=valor*num;
    }
    return valor;
}

double expo(double num, int qtdd){
    double valor=1;
    for(int i=1; i<qtdd; i++){
        valor=valor*num;
    }
    return valor;
}

int main(){
    int qtdd, X, mult=-1;

    printf("quantidade de termos: ");
    scanf("%d", &qtdd);
    printf("valor de X: ");
    scanf("%d", &X);
    double x_rad=X*(3.14159265/180);

    double ValorE=0, termo;
    qtdd=qtdd*2;
    for(int i=0; i<qtdd; i=i+2){
        double fat=fatorial(i);
        double dividendo=expo(x_rad, i);

        termo=(dividendo/fat)*mult;
        ValorE+=termo;

        mult=-mult;
    }
    printf("%lf", ValorE);

    getchar();
    getchar();
}