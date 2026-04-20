#include <stdio.h>
//Faça uma função que calcula o perímetro e a área de um círculo, dado o raio.

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    float pi=3.141592;
    *pPerimetro=(raio*2)*pi;
    *pArea=(raio*raio)*pi;
}

int main(){
    float raio, pPerimetro, pArea;

    printf("informe o raio do circulo: ");
    scanf("%f", &raio);

    calcula_circulo(raio, &pPerimetro, &pArea);

    printf("\nArea do circulo: %.2f\nPerimetro do circulo: %.2f", pArea, pPerimetro);

    getchar();
    getchar();
}