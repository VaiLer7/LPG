#include <stdio.h>

int main(){
    float x = 10.5;
    printf("%f ", x);

    float *px = &x;

    float **ppx = &px;

    /*
    *pxx = 100; essa instrução esta errada pois ela está tirando o endereço de px e botando um valor em ppx, o correto seria fazer uma desreferenciação de desreferenciação de ppx (**ppx), para entao acessar o valor de x:
    */

    **ppx = 100.5;
    
    printf("%f ", x);
}