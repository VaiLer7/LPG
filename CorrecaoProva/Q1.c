#include <stdio.h>

int eh_primo(int);
void ContagemPrimos(int, int);

int main(){
    int K, N;

    printf("digite o valor para comecar: ");
    scanf("%d", &K);
    printf("quantos digitos deseja mostrar: ");
    scanf("%d", &N);

    ContagemPrimos(K, N);

    return 0;
}

 int eh_primo(int numero){
    int metade=numero/2;
    for(int i=2; i<=metade; i++){ //o unico erro no codigo nessa questao era que o 'int i=1' na definicao do for, causando sempre o 'return 0;'
        if(numero%i==0) return 0;
    }
    return 1;
 }

 void ContagemPrimos(int comeco, int qtdd){
    for(; qtdd>0; qtdd--){
        do{
            comeco++;
        }while(!eh_primo(comeco));
        printf("%d ", comeco);
    }
 }