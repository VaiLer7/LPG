#include <stdio.h>

int main(){
    char *pstr_e, dia_e[ ] = "os dias da semana são: seg, ter, quar, qui, sex, sab e dom";
    //cria endereço tipo char, e outro um array de char com o texto
    int i_e;
    pstr_e = dia_e;
    //ponteiro recebe o endereço do array
    //clrscr(); //nao compativel
    while(*pstr_e){
        //putch(*pstr_e, stdin); //nao compativel
        printf("%c", *pstr_e);
        //imprime uma unica caractere
        pstr_e +=1;
        //sooma o endereço pra proxima casa
    }
    getchar();
}