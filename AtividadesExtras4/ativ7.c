#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam;
    printf("qual sera o tamanho do vetor: ");
    scanf("%d", &tam);

    int *vetor = malloc(tam*sizeof(int));
    
    printf("\ninsira os valores:\n");
    for(int i=0; i<tam; i++){
        scanf("%d", vetor+i);
    }

    char res;
    do{
        printf("\ndeseja adicionar mais valores?\n(y/n): ");
        getchar();
        scanf("%c", &res);

        if(res=='y'){
            int amais;

            printf("\nquantos valores a mais deseja adicionar? ");
            scanf("%d", &amais);

            tam+=amais;
            vetor = realloc(vetor, tam*sizeof(int));

            printf("\ninsira os valores:\n");
            int *local;
            for(int i=0; i<amais; i++){
                local=vetor+i+(tam-amais);
                scanf("%d", local);
            }
        }
    }while(res=='y');

    printf("\ntodos os valores:\n");
    for(int i=0; i<tam; i++){
        printf("%d ", *(vetor+i));
    }
}