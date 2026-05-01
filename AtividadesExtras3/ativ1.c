#include <stdio.h>

int fat(int);

int main(){
    int num, res;

    printf("Insira o valor para ser calculada o fatorial: ");
    scanf("%d", &num);

    res=fat(num);

    printf("\nfatorial de %d eh: %d", num, res);

    getchar();
    getchar();
}

int fat(int num){
    if(num==0){
        return 1;
    }

    return num--*fat(num);
}