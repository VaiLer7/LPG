#include <stdio.h>
#include <stdlib.h>

int main(){
    double **array_p;

    printf("digite 10 valores:\n");
    for(int i=0; i<10; i++){
        double *p = malloc(sizeof(double));
        scanf("%lf", p);
        array_p[i] = p;
    }

    printf("\nvalores digitados:\n");
    for(int i=0; i<10; i++){
        printf("%lf ", *array_p[i]);
    }
}