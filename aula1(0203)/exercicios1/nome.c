#include <stdio.h>
#include <windows.h>

int main(){
    char nome[50];
    int sexo=1;

    printf("qual seu nome?\n");
    scanf("%s", &nome);
    printf("qual seu sexo?\n1. Masculino\n2. Femininno");
    scanf("%d", &sexo);

    if(sexo==1){
        printf("\n%s. Sr.", nome);
    }else{
        printf("%s. Sra.", nome);
    }
    Sleep(2000);
}