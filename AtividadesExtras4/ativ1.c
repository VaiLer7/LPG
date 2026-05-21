#include <stdio.h>
#include <stdlib.h>

int main(){
    int *num;

    num = malloc(sizeof(int));

    printf("digite o numero desejado: ");
    scanf("%d", num);

    int valor = *num;
    printf("\nnum: %d", valor);
}