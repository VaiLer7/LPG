#include <stdio.h>

int main(){
    int v[10] = {7, 13, 8, 1, 9, 4, 27, 17, 6, 2};
    int *pv;
    int i;
    pv = v;

    for(i=0;i<10;i++){
        printf("\n%i | %i | %i | %i",v[i],&v[i],(pv+i),*(pv+i));
        printf("\n%i | %i | %i | %i\n",&pv[i],pv[i],*(v+i),(v+i));
    }

    /*
    
    Sempre vai seguir o mesmo padrao de:
    valor | endereço | endereço | valor
    depois na proxima linha inverte:
    endereço | valor | valor | endereço

    se considerarmos o seguinte:
    valor = v
    endereço = &
    
    entao sempre ficará assim:

    v | & | & | v
    & | v | v | &

    */
}