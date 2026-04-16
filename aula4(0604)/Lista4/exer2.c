#include <stdio.h>
//Escreva uma função que recebe um vetor v e um inteiro n. A função deve gerar o n termos de sequência de Fibonacci dentro de v. Protótipo da função:
//void fibonacci(int v[], int n);

void fibonacci(int vetor[], int termos){
    vetor[termos];

    vetor[0]=1;
    printf("%d ", vetor[0]);

    if(termos>1){
        vetor[1]=1;
        printf("%d ", vetor[1]);
    }
    
    for(int i=2; i<termos; i++){
        vetor[i]=vetor[i-1]+vetor[i-2];
        printf("%d ", vetor[i]);
    }
}

int main(){
    int termos;

    printf("quantos termos deseja gerar? ");
    scanf("%d", &termos);

    int vertoV[termos];
    fibonacci(vertoV, termos);

    getchar();
    getchar();
}