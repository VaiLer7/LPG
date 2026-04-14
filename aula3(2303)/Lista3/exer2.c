#include <stdio.h>
//Faça uma função que recebe três valores inteiros e retorna o maior valor. É preciso considerar que podem haver dois (ou mesmo os três) parâmetros iguais como sendo o maior valor. Por exemplo, os parâmetros poderiam ser 5, 8 e 8. Neste caso, a função deve retornar 8.
int main(){
    int Valor, temp;

    printf("Digite o valor A:");
    scanf("%d", &Valor);
    printf("Digite o valor B:");
    scanf("%d", &temp);
    Valor = (temp>Valor) ? temp : Valor;
    printf("Digite o valor C:");
    scanf("%d", &temp);
    Valor = (temp>Valor) ? temp : Valor;

    printf("Maior valor: %d", Valor);

    getchar();
    getchar();

}