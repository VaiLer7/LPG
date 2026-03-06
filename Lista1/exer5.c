#include <stdio.h>

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