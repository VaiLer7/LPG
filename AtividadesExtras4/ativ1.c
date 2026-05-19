#include <stdio.h>
#include <stdlib.h>

int main(){
    int *num;

    num = malloc(sizeof(int));

    *num=1;

    printf("\nnum: %d", *num);

    free(num);

    printf("\nnum: %d", *num);

    *num=2;

    printf("\nnum: %d", *num);
}