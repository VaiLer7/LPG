#include <stdio.h>

int main(){
    char str[ ] = "linguagem C", *px, *py, aux;
    px=py=str;
    //cria uma string com texto, e 2 ponteiros px e py que recebem o endereço da string
    for(; *py!= '\0'; py++);
    py--;
    //chega até o final da string e volta uma casa para ficar na ultima caractere

    while(px<py){ //enquanto a posição do endereço de px for inferior que a posição do endereço de py, continua

        aux= *px; //aux recebe a caractere dentro de px
        *px = *py; //dentro de px recebe a caractere dentro py
        *py = aux; //dentro de px recebe a caractere de aux
        
        px++; //ponteiro px avaça uma casa
        py--; //ponteiro py retrocede uma casa

        //o codigo está invertendo a string
    }
    //clrscr();
    //puts(str);
    printf("%s", str);
    getchar();
}