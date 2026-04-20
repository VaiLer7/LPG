#include <stdio.h>
//Faça uma função que receba um parâmetro (por valor) com o total de minutos passados ao longo do dia e receba também dois parâmetros (referência) no qual deve preencher com o valor da hora e do minuto corrente. Faça um programa que leia do teclado quantos minutos se passaram desde meia-noite e imprima a hora corrente (use a sua função).

void cacula_hora(int totalMinutos, int *ph, int *pm){
    int horas=totalMinutos/60;
    int minutos=totalMinutos%60;

    *ph=horas;
    *pm=minutos;
}

int main(){
    int totalMinutos, ph, pm;

    printf("digite quantos minutos ja passaram desde a meia noite: ");
    scanf("%d", &totalMinutos);

    cacula_hora(totalMinutos, &ph, &pm);
    
    printf("agora eh: %d:%d", ph, pm);

    getchar();
    getchar();
}