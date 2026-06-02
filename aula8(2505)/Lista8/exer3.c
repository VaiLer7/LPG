#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(float*, int);
float *escaneamento(float*, float, int);

int main(){
    int tam;

    printf("O quao grande deseja que seja seu vetor? ");
    scanf("%d", &tam);

    float *vetor;

    vetor = malloc(tam*sizeof(float));

    printf("insira os numeros (float):\n");
    
    for(int i=0; i<tam; i++){
        scanf("%f", vetor+i);
    }

    float media_total = media(vetor, tam);

    float *numeros_acima_da_media = escaneamento(vetor, media_total, tam);

    if(*numeros_acima_da_media==1){
        printf("todos os valores sao iguais!\n");
        return 0;
    }

    printf("\n\nvalores acima da media: \n");
    for(int i=1; i<*numeros_acima_da_media; i++){
        printf("%f\n", *(numeros_acima_da_media+i));
    }
}

float media(float *vetor, int tamanho){
    float soma=0;
    for(int i=0; i<tamanho; i++){
        soma+=*(vetor+i);
    }

    return (soma/tamanho);
}

float *escaneamento(float *vetor, float media, int tam){
    int tamanho = 1;
    float *array = malloc(sizeof(float));

    for(int i=0; i<tam; i++){
        if(*(vetor+i)>media){
            tamanho++;
            array = realloc(array, tamanho*sizeof(float));
            array[tamanho-1] = *(vetor+i);
        }
    }
    array[0]=tamanho;

    return array;
}