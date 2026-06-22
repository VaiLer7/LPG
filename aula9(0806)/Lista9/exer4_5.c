#include <stdio.h>

int main(){

    //4:
    int *var1; //ponteiro int 'var1'
    int var2; //int 'var2' 
    int **var3; //ponteiro pra ponteiro 'var3'

    
    //5:
    //declarando de forma direta
    var2 = 123;
    printf("valor de var2: %d\n", var2);
    var2=0;

    //de forma indireta através do ponteiro var1 (que deve apontar para var2)
    var1=&var2;
    *var1 = 123;
    printf("valor de var2: %d\n", var2);
    var2=0;
    var1=NULL;

    //de forma indireta através do ponteiro var3 (que deve apontar para o ponteiro var1)
    var3 = &var1;
    var1 = &var2;
    var2 = 123;
    printf("valor de var2: %d\n", var2);
    var2=0;
    var1=NULL;
    var3=NULL;

    

    
}