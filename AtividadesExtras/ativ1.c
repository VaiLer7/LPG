#include <stdio.h>
#include <string.h>

int main(){
    int Q_caracteres = 10;
    char texto[Q_caracteres];
    fgets(texto, Q_caracteres, stdin);
    printf("tamanho da string (contando o \\n): %zu", strlen(texto)+1);

    getchar();
    getchar();
}