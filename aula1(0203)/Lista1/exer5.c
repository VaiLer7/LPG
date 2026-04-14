#include <stdio.h>
// Leia 1 valor inteiro N, que representa o número de casos de teste que vem a seguir. Cada caso de teste consiste de 3 valores reais, cada um deles com uma casa decimal. Apresente a média ponderada para cada um destes conjuntos de 3 valores, sendo que o primeiro valor tem peso 2, o segundo valor tem peso 3 e o terceiro valor tem peso 5.
float media(float X, float Y, float Z){
    int peso1=2, peso2=3, peso3=5;

    return ((X*peso1)+(Y*peso2)+(Z*peso3))/(peso1+peso2+peso3);
}

int main(){
    int casos;
    printf("Quantos casos ira fazer? \n");
    scanf("%d", &casos);
    
    float nota1, nota2, nota3, notas[casos];
    for(int i=0; i<casos; i++){
        printf("Digite ");
        i==0 ? printf("as tres notas:\n") : printf("novamente:\n");
        scanf("%f %f %f", &nota1, &nota2, &nota3);
        notas[i]=media(nota1, nota2, nota3);
    }
    for(int i=0; i<casos; i++){
        printf("Caso %d: %.1f\n", i+1, notas[i]);
    }

    getchar();
    getchar();
}