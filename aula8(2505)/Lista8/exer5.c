#include <stdio.h>
#include <stdlib.h>

int *uniao(int*, int, int*, int, int*);

int main(){
    int n1;
    printf("insira o tamanho do primeiro vetor: ");
    scanf("%d", &n1);
    int v1[n1];

    int n2;
    printf("insira o tamanho do segundo vetor: ");
    scanf("%d", &n2);
    int v2[n2];

    printf("insira os valores dentro do vetor 1:\n");
    for(int i=0; i<n1; i++){
        scanf("%d", &v1[i]);
    }

    printf("insira os valores dentro do vetor 2:\n");
    for(int i=0; i<n2; i++){
        scanf("%d", &v2[i]);
    }

    int p3;

    int *intersecao = uniao(v1, n1, v2, n2, &p3);

    printf("\nnovo vetor gerado: ");
    for(int i=0; i<p3; i++){
        printf("%d ", intersecao[i]);
    }
}


int *uniao(int *v1, int n1, int *v2, int n2, int *p3){
    *p3=n1+n2;
    int *novo_vetor = malloc((*p3)*sizeof(int));
    for(int i=0; i<n1; i++){
        novo_vetor[i]=v1[i];
    }
    for(int i=0; i<n2; i++){
        novo_vetor[n1+i]=v2[i];
    }

    return novo_vetor;
}