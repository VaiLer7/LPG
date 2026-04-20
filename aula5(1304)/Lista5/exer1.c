#include <stdio.h>
//Faça uma função que recebe dois números, a e b. A função deve incrementar a e decrementar b.

void inc_dec(int *a,int *b){
    a=(*a)++;
    b=(*b)--; 
}

int main(){
    int a, b;

    printf("defina o valor de A e B:\n");
    scanf("%d %d", &a, &b);

    inc_dec(&a, &b);

    printf("\n\nA: %d, B: %d", a, b);
    
    getchar();
}