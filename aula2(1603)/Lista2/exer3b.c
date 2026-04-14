#include <stdio.h>
//Implemente as duas formas para calcular o valor aproximado de π, conforme as séries a seguir. O número de termos é definido pelo usuário.
//Série de Nilakantha:

int divisor(int termo){
    int comeco=termo*2;
    comeco=(comeco)*(comeco+1)*(comeco+2);

    return comeco;
}
double calc_fracao(int termo){
    return (double)4.0/(divisor(termo));
}
int main(){
    int termos, mult=1;
    double fracao, pi=3;

    printf("Quantos termos deseja que tenha de precisao: ");
    scanf("%d", &termos);

    for(int i=1; i<termos; i++){
        fracao=calc_fracao(i);
        pi+=mult*fracao;
        mult=-mult;
    }

    printf("\nValor aproximado de PI: %lf", pi);

    getchar();
    getchar();
}