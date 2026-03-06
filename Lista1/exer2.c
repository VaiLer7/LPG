#include <stdio.h>

int comparar(int I, float X, float Y, float Z){
    switch(I){
        case 1:
            if(X*X==(Y*Y)+(Z*Z)||
            Y*Y==(X*X)+(Z*Z)||
            Z*Z==(Y*Y)+(X*X)){
                return 1;
            }else{
                return 0;
            }
        break;

        case 2:
            if(X*X>(Y*Y)+(Z*Z)||
            Y*Y>(X*X)+(Z*Z)||
            Z*Z>(Y*Y)+(X*X)){
                return 1;
            }else{
                return 0;
            }
        break;

        case 3:
            if(X*X<(Y*Y)+(Z*Z)||
            Y*Y<(X*X)+(Z*Z)||
            Z*Z<(Y*Y)+(X*X)){
                return 1;
            }else{
                return 0;
            }
        break;
    }
}

int main(){
    float A, B, C;
    printf("Valor do lado A: ");
    scanf("%f", &A);
    printf("Valor do lado B: ");
    scanf("%f", &B);
    printf("Valor do lado C: ");
    scanf("%f", &C);

    if(A>=B+C||B>=+A+C||C>=A+B){
        printf("Triangulo impossivel");
    }else{
        if(comparar(1, A, B, C)){
            printf("Triangulo Retangulo ");
        }else if(comparar(2, A, B, C)){
            printf("Triangulo Obtusangulo ");
        }else if(comparar(3, A, B, C)){
            printf("Triangulo Acutangulo ");
        }
        if(A==B&&B==C){
            printf("Equilatero");
        }else if(A==B||B==C||C==A){
            printf("Isosceles");
        }else{
            printf("Escaleno");
        }
    }
    getchar();
    getchar();
}