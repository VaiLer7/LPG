#include <stdio.h>
//Faça uma função que recebe 2 parâmetros, x e y, e calcule a soma dos números impares entre eles (sem contar com eles mesmos). Repare que a função deve levar em conta de que x pode ser maior do que y. Por exemplo, para x = 6 e y = -5, temos a seguinte soma (em ordem crescente): -3 + (-1) + 1 + 3 + 5 = 5. Outro exemplo: para x = 3 e y = 10 temos 5 + 7 + 9 = 21.

int main(){
    int X, Y, maior=1, soma=0;

    printf("Digite o numero X: ");
    scanf("%d", &X);
    printf("Digite o numero Y: ");
    scanf("%d", &Y);
    if(X>Y) maior = -1;

    for(X+=maior;X!=Y; X+=maior){
        if(X%2!=0) soma+=X;
    }
    printf("Soma: %d", soma);

    getchar();
    getchar();
}