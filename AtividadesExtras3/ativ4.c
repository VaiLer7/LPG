#include <stdio.h>
#include <windows.h>

int contagem(int);

int main(){
    int seg;

    printf("quantos segundos pra contagem regressiva? ");
    scanf("%d", &seg);

    contagem(seg);

    getchar();
    getchar();
}

int contagem(int timer){
    if(timer==0){
        printf("0\nAcabou!");
        return 0;
    }
    
    printf("%d ", timer);
    Sleep(1000);
    timer--;

    return contagem(timer);
}