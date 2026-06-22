#include <stdio.h>

int main(){
    int *p, i=20;
    p=&i;
    printf("%ld\n", sizeof(p)); //imprime quantos bytes um ponteiro ocupa (8)
    printf("%ld\n", sizeof(*p)); //imprie quantos bytes a desreferenciação do ponteiro p ocupa (é um int, entao 4)
}