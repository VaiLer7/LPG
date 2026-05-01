#include <stdio.h>

int soma(int);

int main(){
    int num, res;

    printf("digite o numero para ser somado ate: ");
    scanf("%d", &num);

    res=soma(num);

    printf("soma de 0 ate %d eh: %d", num, res);

    getchar();
    getchar();
}

int soma(int num){
    if(num==0){
        return 0;
    }

    return num-- + soma(num);
}