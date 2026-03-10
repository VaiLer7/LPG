#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int tamanho = 100, letra, numero, i;
    char texto[tamanho];

    printf("A senha deve possuir no minimo 8 caracteres\nPelo menos 1 numero\nPelo menos 1 Letra\nDigite a senha: ");
        
    do{
        letra=0; numero=0;
        fgets(texto, tamanho, stdin);

        for(i=0; texto[i]!='\0'; i++){
            if(isdigit(texto[i])) numero=1;
            else if(isalpha(texto[i])) letra=1;
        }

        if(numero!=1||letra!=1||i<7){
            printf("Senha Invalida!\n");
            if(numero!=1) printf("Necessario pelo menos um numero!\n");
            if(letra!=1) printf("Necessario pelo menos uma letra!\n");
            if(i<7) printf("Necessario pelo menos 8 carateres!\n");
            printf("Digite a senha novamente: ");
            getchar();
        }
    }while(numero!=1||letra!=1||i<7);
    printf("Senha Valida");

    getchar();
    getchar();
}