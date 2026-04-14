#include <stdio.h>
//Faça um programa que lê os três lados de um triângulo e determina o seu tipo, conforme códigos a seguir. Os códigos devem ser retornados por uma função de tipo int, que recebe os lados do triângulo como parâmetro.
int main(){
    int LadoA, LadoB, LadoC;

    printf("Digite o valor do lado A: ");
    scanf("%d", &LadoA);
    printf("Digite o valor do lado B: ");
    scanf("%d", &LadoB);
    printf("Digite o valor do lado C: ");
    scanf("%d", &LadoC);

    if(
        LadoA>=LadoB+LadoC||
        LadoB>=LadoA+LadoC||
        LadoC>=LadoB+LadoA
    ){
        printf("Valores incompativeis");
    }
    else{
        if(LadoA==LadoB&&LadoB==LadoC){
            printf("Equilatero");
        }else if(LadoA==LadoB||LadoB==LadoC||LadoC==LadoA){
            printf("Isosceles");
        }else{
            printf("Escaleno");
        }
    }
    getchar();
    getchar();
}