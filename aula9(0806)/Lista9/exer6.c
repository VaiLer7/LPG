#include <stdio.h>

int main(){
    int X = 2, Y = 3, Z = 14;

    int *p1, *p2;

    //6.a:
    p1=&X;
    p2=&Y;

    //6.b:

    //ponteiros pra ponteiros sao aqules que sao capazes de apontar para o endereço de um ponteiro por si só

    int **pp = &p1;

    printf("%p\n", p1); //aqui mostra o endereço de X
    printf("%p\n",pp); // aqui o endereço de p1
    printf("%i\n", *p1); //aqui mostra a desreferenciação do ponteiro p1 (valor de X)
    printf("%p\n", *pp); //aqui a desreferenciação do ponteiro pp (endereço de p1)
    printf("%i\n", **pp); //aqui desreferenciação da desreferenciação do ponteiro pp (valor de X)
    printf("%p\n", &p1); //aqui endereço do ponteiro p1
    printf("%p\n", &pp); //aqui endereço do ponteiro pp
}