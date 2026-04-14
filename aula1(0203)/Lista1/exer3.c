#include <stdio.h>
// Leia a hora inicial e a hora final de um jogo. A seguir calcule a duração do jogo, sabendo que o mesmo pode começar em um dia e terminar em outro, tendo uma duração máxima de 24 horas.
int main(){
    int H1, H2, i;
    printf("Hora do comeco: ");
    scanf("%d", &H1);
    printf("Hora final: ");
    scanf("%d", &H2);

    for(i=0; i<=24; H1++){
        if(H1==24){
            H1=0;
        }
        if(H1==H2&&i!=0){
            break;
        }
        i++;
    }
    printf("\nO jogo durou %d hora(s)", i);
    
    getchar();
    getchar();
}