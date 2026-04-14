#include <stdio.h>

int main(){
    int x=5, *p=&x;

    printf("valor de x: %d\n", x);
    printf("endereço de x: %d\n\n", &x);
    // printf("ponteiro de x: %d\n", *x);
    //nao é possivel fazer a ponteiro de x pois o valor de x nao é uma localização em si, somente um inteiro.


    printf("valor de p: %d\n", p);
    printf("endereço de p: %d\n", &p);
    printf("ponteiro de p: %d\n", *p);

    getchar();
    getchar();

}