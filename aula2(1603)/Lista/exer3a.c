#include <stdio.h>
//Implemente as duas formas para calcular o valor aproximado de π, conforme as séries a seguir. O número de termos é definido pelo usuário.
//Série de Gregory-Leibniz:
int main(){
    float numero=0, operacao=1;
    int qtdd;
    
    printf("quantidade de termos a serem calculados: ");
    scanf("%d", &qtdd);
    qtdd=qtdd*2;

    for(int i=1; i<=qtdd; i+=2){
        if(operacao){
            numero=numero+(4.0/i);
            operacao--;
        }else{
            numero=numero-(4.0/i);
            operacao++;
        }
    }
    
    printf("%f", numero);

    getchar();
    getchar();
}