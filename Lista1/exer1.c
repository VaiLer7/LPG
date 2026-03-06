#include <stdio.h>

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