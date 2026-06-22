#include <stdio.h>

//9. Qual a saída do comando “printf” para o programa abaixo?

int main(){
    char *vetor_pt [ ] = {"joao", "maria", "zeze"};
    char antes_era [ ][9] = {"joão", "maria", "zeze"};

    printf("%s||%s||%s", vetor_pt[0], vetor_pt[1], vetor_pt[2]);

    //saida: "joao||maria||zeze"
}