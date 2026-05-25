#include <stdio.h>

main(){
    double x[5]; //definindo o vetor x coomo vetor com 5 valores double

    double *px; //definindo ponteiro px (tambem como double)
    int i; //definindo int i
    px = x; //ponteiro recebe o endereço do vetor x
    for(i=0;i<5;i++){ //faz de 0 ate chegar 4 (contando o proprio)
        printf("\n%lf",*px); //mostra o valor dentro de px
        px++; //soma o endereço de px para proxima unidade
    }

    px = x; //valor anterior de px era o seu maximo (4), entao volta a pegar o valor inicial do vetor x
    for(i=0;i<5;i++){ //faz de 0 ate 4 (contando o prprio)
        printf("\n%lf",*(px+i)); //mostra o valor dentro do resultado da soma do endereço de px + valor de i
    }
}

//Explique a diferença no uso de ponteiro entre a 1ª e a 2ª estrutura de repetição no programa anterior
/*
A diferença é que no final nao é necesssario setar valor de px novamene para origem
pois o valor de px nunca muda, oque muda é o valor sendo somado à ele
*/