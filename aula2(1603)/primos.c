#include <stdio.h>

int isprime(int num){
    int limite=num/2, dado=1;
    if(num==4){
        dado=0;
    }else{
        for(int i=2; i<limite; i++){
            if(num%i==0){
                dado=0;
                break;
            }
        }
    }
    return dado;
    
}

int main(){
    int comeco, qtdd, i=0;

    printf("digite o numero pra começar: ");
    scanf("%d", &comeco);
    printf("digite a quatidade de numeros ");
    scanf("%d", &qtdd);

    while(i!=qtdd){
        comeco++;
        if(isprime(comeco)){
            i++;
            printf("%d ", comeco);
        }
    }


    getchar();
    getchar();
}