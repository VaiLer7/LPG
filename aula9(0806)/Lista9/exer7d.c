#include <stdio.h>

int main(){
    char *dias[ ] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};
    //criando matriz

    int i;
    clrscr();
    for(i=0; i<7; i++){
        printf("\n dia da semana: %d\n", i+1);
        printf("\n%s", dias[i]);
        //imprime a string guardada em cada posição dentro do ponteiro dias
    }
}