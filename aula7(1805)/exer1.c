#include <stdio.h>

void converteSegundos( int segundos, int *h, int *m, int *s){
    *h = segundos/3600;
    *m = (segundos%3600) / 60;
    *s = (segundos%3600) % 60;
}

int main(){
    int s;
    int horas, minutos, segundos;

    printf("quantos segundos: ");
    scanf("%d", &s);

    converteSegundos(s, &horas, &minutos, &segundos);

    printf("%d horas\n", horas);
    printf("%d minutos\n", minutos);
    printf("%d segundos\n", segundos);
}