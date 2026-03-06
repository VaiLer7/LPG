#include <stdio.h>

int main(){
    int N, X, num=0;

    printf("digite o valor de N\n");
    scanf("%d", &N);
    printf("digite o valor de X\n");
    scanf("%d", &X);

    do{
        num++;
        printf("%d", num);
        if(num%X==0){
            printf(": Multiplo de X");
        }
        printf("\n");
    }while(num<N);

    getchar();
    getchar();
}