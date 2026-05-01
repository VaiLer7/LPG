#include <stdio.h>

int fibo(int, int, int);

int main(){
    int termos, num1=0, num2=1;

    printf("diga quantos termos deseja fazer do termo fibonacci: ");
    scanf("%d", &termos);

    fibo(termos-2, num1, num2);
    
    getchar();
    getchar();
}

int fibo(termos, num1, num2){
    if(termos<=0){
        printf("%d", num1);
        if(termos==0){
            printf(", %d", num2);
        }
        return 0;
    }

    printf("%d, ", num1);

    int novo=num1+num2;
    num1=num2;
    num2=novo;

    termos--;
    return fibo(termos, num1, num2);
}