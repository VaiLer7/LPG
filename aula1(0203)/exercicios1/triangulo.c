#include <stdio.h>
#include <windows.h>

int main(){
    float A, B, C;
    printf("escreva o valor dos lados: \n");
    scanf("%f %f %f", &A, &B , &C);

    if(A==B&&B==C){
        printf("equilatero");
    }else if(A==B||B==C||C==A){
        printf("escaleno");
    }else{
        printf("isosceles");
    }
    
    Sleep(2000);

}