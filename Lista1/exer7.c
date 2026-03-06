#include <stdio.h>

int impares(int A, int B){
    int mult=0, soma=0;
    B<A ? mult-- : mult++;

    for(A!=B ? A=A+mult : A;A!=B;A=A+mult){
        soma=soma+(A%2!=0? A: 0);
    }
    return soma;
}

int main(){
    int casos;
    printf("Quantos casos ira fazer? \n");
    scanf("%d", &casos);
    
    int X, Y, somatoria[casos];
    for(int i=0; i<casos; i++){
        printf("Digite ");
        i==0 ? printf("os dois valores:\n") : printf("novamente:\n");
        scanf("%d %d", &X, &Y);
        somatoria[i]=impares(X, Y);
    }
    for(int i=0; i<casos; i++){
        printf("Caso %d: %d\n", i+1, somatoria[i]);
    }

    getchar();
    getchar();
}