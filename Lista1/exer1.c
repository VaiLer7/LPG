#include <stdio.h>
// Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou se está sobre um dos eixos cartesianos ou na origem (x = y = 0).
//Se o ponto estiver na origem, escreva a mensagem “Origem”.
//Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou “Eixo Y”, conforme for a situação.
int main(){
    float X, Y;
    int SX, SY;
    printf("digite o valor de X: \n");
    scanf("%f", &X);
    printf("digite o valor de Y: \n");
    scanf("%f", &Y);

    if(X==0&&Y==0){
        printf("Origem");
    }else
    if(X>0){
        if(Y>0){
            printf("Q1");
        }else{
            printf("Q4");
        }
    }else if(X<0){
        if(Y>0){
            printf("Q2");
        }else{
            printf("Q3");
        }
    }
    getchar();
    getchar();
}