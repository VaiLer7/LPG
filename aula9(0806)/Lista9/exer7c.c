#include <stdio.h>

int main(){
    char *dias[ ] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};
    //criando matriz
    int i;
    //clrscr();
    for(i=0; i<7; i++){
        printf("\n dia da semana: %d \n", i+1);
        while(*dias[i]){
            printf("%c", *dias[i]++); //avança uma casa toda vez que essa linha é executada
            //enquanto o valor dentro do de *dias[i] nao for nulo, ele imprime as caracteres dentro
        }
    }
    getchar();
}