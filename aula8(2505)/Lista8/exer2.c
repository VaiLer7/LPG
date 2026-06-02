#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor(char*, int);

int main(){
    int tam=50;
    char texto[tam];

    printf("insira o texto: ");
    scanf(" %s", texto);

    int vezes_repetido;

    printf("quantas vezes deseja repeti-lo?\n");
    scanf("%d", &vezes_repetido);

    char *novo_texto = repetidor(texto, vezes_repetido);

    printf("\ntexto repetido: \n%s", novo_texto);

    free(novo_texto);
}

char *repetidor(char *texto, int vezes){
    int tamanho_texto = strlen(texto);
    int tamanho_total = tamanho_texto * vezes + 1;

    char *novo_texto;

    novo_texto = malloc(tamanho_total*sizeof(char));

    for(int i=0; i<vezes; i++){
        for(int j=0; j<tamanho_texto; j++){
            novo_texto[(i*tamanho_texto)+j] = texto[j];
        }
    }
    novo_texto[tamanho_texto*vezes]='\0';

    return novo_texto;
}