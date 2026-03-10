#include <stdio.h>
#include <ctype.h>

int main(){
    int tamanho = 30, letra=0, numero=0, espaco=0, algo=0;
    char textao[tamanho];

    fgets(textao, tamanho, stdin);
    for(int i=0; textao[i]!='\0'; i++){
        isalpha(textao[i]) ? letra++ :
        isdigit(textao[i]) ? numero++ :
        isspace(textao[i]) ? espaco++ : algo++;
    }
    printf("letras: %d\nnumeros: %d\nespacos: %d", letra, numero, espaco-1);

    getchar();
    getchar();
}