#include <stdio.h>
#include <stdlib.h>

float *clone(float*, int);

int main(){
    int n;
    printf("insira o tamanho do vetor: ");
    scanf("%d", &n);

    float vetor[n];
    printf("insira os valores (float) no vetor:\n");

    for(int i=0; i<n; i++) scanf("%f", &vetor[i]);

    float *vetor_clone = clone(&vetor, n);
    printf("\n");

    for(int i=0; i<n; i++) printf("%f ", *(vetor_clone+i));
}

float *clone(float *v, int n){
    float *vetor_novo;
    vetor_novo = malloc(n*sizeof(float));

    for(int i=0; i<n; i++) vetor_novo[i] = *(v+i);

    return vetor_novo;
}