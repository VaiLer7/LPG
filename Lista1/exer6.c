#include <stdio.h>

int main(){
    int A, B, mult=0, soma=0;

    printf("Digite os valores: \n");
    scanf("%d %d", &A, &B);

    B<A ? mult-- : mult++;
    
    for(A!=B ? A=A+mult : A;A!=B;A=A+mult){
        soma=soma+(A%2!=0? A: 0);
    }
    printf("\n%d", soma);

    getchar();
    getchar();
}