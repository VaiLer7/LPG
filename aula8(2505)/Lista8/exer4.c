#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tam;
    printf("insira o tamanho do vetor: ");
    scanf(" %d", &tam);

    int v[tam];

    printf("insira os valores no vetor: \n");
    for(int i=0; i<tam; i++){
        scanf("%d", &v[i]);
    }

    int *vp = NULL;
    int *vn = NULL;

    int tamVp=0, tamVn=0;

    for(int i=0; i<tam; i++){
        if(v[i]>0){
            vp = realloc(vp, tamVp*sizeof(int));

            vp[tamVp]=v[i];
            tamVp++;
        }
        if(v[i]<0){
            vn = realloc(vn, tamVn*sizeof(int));

            vn[tamVn]=v[i];
            tamVn++;
        }
    }

    printf("Vetor principal: \n");
    for(int i=0; i<tam; i++){
        printf("%d ", v[i]);
    }
    if(tamVn==0&&tamVp==0){
        printf("O vetor principal eh inteiramente nulo!");
    }else{
        if(tamVp>0){
            printf("\nVetor positivo: \n");
            for(int i=0; i<tamVp; i++){
                printf("%d ", vp[i]);
            }
        }
        if(tamVn>0){
            printf("\nVetor negativo: \n");
            for(int i=0; i<tamVn; i++){
                printf("%d ", vn[i]);
            }
        }
    }
    printf("\n");

}