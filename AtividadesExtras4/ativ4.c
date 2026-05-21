#include <stdio.h>
#include <stdlib.h>

int main(){
    char *nome = malloc(20*sizeof(char));

    printf("Digite seu nome: ");
    fgets(nome, 20, stdin);

    printf("\n%s", nome);
}