#include <stdio.h>

int main(){
    int quant, num, pos=0, neg=0, par=0, impar=0;
    printf("quantos numeros serao lidos?\n");
    scanf("%d", &quant);
    printf("escreva a sequencia de numeros:\n");

    for(int i=0; i<quant; i++){
        scanf("%d", &num);
        if(num>0||num<0){
            num>0 ? pos++ : neg++;
        }
        num%2==0 ? par++ : impar++;
    }
    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", impar);
    printf("%d valor(es) positivo(s)\n", pos);
    printf("%d valor(es) negativo(s)\n", neg);

    getchar();
    getchar();
}