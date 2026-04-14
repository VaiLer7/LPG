#include <stdio.h>
//Faça um algoritmo que mostre na tela os k termos da série definida a seguir e, ao final, mostre o somatório dos termos (o resultado converge para o logaritmo natural de 2). O número de termos da série é definido pelo usuário.
int main(){
    float numero=1;
    int qtdd;
    
    printf("quantidade de termos a serem calculados: ");
    scanf("%d", &qtdd);

    for(int i=1; i<=qtdd; i++){
        if(i%2==1){
            numero=numero+(1.0/i);
        }else{
            numero=numero-(1.0/i);
        }
    }
    numero--;
    
    printf("%f", numero);

    getchar();
    getchar();
}