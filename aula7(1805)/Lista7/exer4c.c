#include <stdio.h>

main()
{
    int x[5]; //definindo vetor x com 5 entradas
    int *px; //definindo ponteiro px
    int i; //definindo int i

    px = x; //ponteiro px recebe o endereço do vetor x

    for(i=0;i<5;i++){ //conta de 0 até 4 (contatndo com o próprio)
        printf("\n%i",*(px++)); //mostra o valor dentro de px, depois ele incrementa a si mesmo o endereço
    }
}