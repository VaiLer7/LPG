#include <stdio.h>
/*
Ele vai alocar um espaço na memoria para essa matriz, e esse espaço é dividido em 3 partes iguais com 5*sizeof(especie int, char, float, etc...) bytes de armazenamento
*/

int main(){
    int num=3;

    int array[num][5];

    printf("%p\n", array);
    for(int i=1; i<num; i++){
        long valor = (char*)array[i]-(char*)array[i-1];
        printf(" - %ld Bytes\n", valor);
        printf("%p\n", array[i]);
    }
}