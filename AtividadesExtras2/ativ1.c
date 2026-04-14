#include <stdio.h>

int main(){
    int numero = 10;
    printf("numero em si: %d\n", numero);
    printf("endereço do numero: %d\n", &numero);
    printf("ponteiro pro endereço do numero: %d\n", *&numero);

    //Basicamente: O endereço dá a localização de aonde aquele valor esta sendo guaradado.
    //Ja o ponteiro, é uma mecanica que pega o valor da localização que esta guardado apos o *
    //Um complementa o outro:
    //enquanto o & ve o endereço a partir do valor
    //o * ve o valor a partir do endereço
    
    getchar();
    getchar();
}