#include <stdio.h>

int main(){
    int x=1, y=2, z[10]; //definindo x e y, seus valores, e vetor z e seu tamanho;
    int *ip, *ip2; //definindo ponteiros ip e ip2

    ip = &x; //ip recebendo o endereço de x
    y = *ip; // y recebe o valor dentro do endereço guardado por ip (1) 
    *ip = 0; //o valor dentro de ip vira 0
    ip=&z[2]; //ip recebe o endereço da segunda posição do vetor z
    ip2=&z[5]; //ip2 recebe o endeeço da quinta posição do vetor z

    int k = ip2-ip; //subtraindo endereço do outro para saber quando elementos tem entre os dois

    y = *ip+1; //y recebe a soma do valor dentro de ip + 1
    (*ip)++; //valor dentro de ip soma mais 1
}