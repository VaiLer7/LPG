#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor = malloc(8*sizeof(int));
    
    scanf("%d", vetor);
    int maior = *vetor, *local;
    for(int i=1; i<8; i++){
        local=vetor+i;
        scanf("%d", local);
        if(*local>maior) maior=*local;
    }

    printf("\nO maior numero eh: %d", maior);
}