#include <stdio.h>

int main(){
    int num, i=0, soma=0, quad=0;
    float media;
    printf("Digite o numero: ");
    scanf("%d", &num);

    //somatoria e quadrados
    do{
        i++;
        soma=i+soma;
        quad=(i*i)+quad;
    }while(i<num);

    media=soma/num;//media

    printf("\nSomatoria:%d\nSoma dos quadrados:%d\nMedia:%0.2f", soma, quad, media);

    getchar();
    getchar();
}