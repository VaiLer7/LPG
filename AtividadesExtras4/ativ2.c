#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor = malloc(5*sizeof(int));

    printf("preencha o vetor: ");
    for(int i=0; i<5; i++){
        scanf("%d", vetor+i);
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf("%d ", *(vetor+i));
    }
    printf("\n\n");
}