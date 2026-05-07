#include <stdio.h>
#include <unistd.h>

void visualizacao(int tamanho, int torres[3][tamanho]);
int primeironum(int tamanho, int torre[3][tamanho], int posicao);

void hanoi(int n,char origem,char destino,char auxiliar, int tamanho, int torres[3][tamanho]){
/* Se sobrar apenas o disco 1, mova fazer o movimento e retornar */
    if(n==1){
        printf("\nMova o disco 1 da torre %c para a torre %c  \n",origem ,destino);
        
        int de=origem-'A'; //identificar de qual torre esta send "pego" o disco
        int para=destino-'A'; //identificar pra qua torre o disco irá
        int poszero=primeironum(tamanho, torres, para)-1; //identificar a posicao do ultimo zero dentro da torre destino
        int posnum=primeironum(tamanho, torres, de); //identificar a posição do primeiro numero dentro da torre origem

        torres[para][poszero] = torres[de][posnum];//movendo o disco da torre origem pro destino
        torres[de][posnum] = 0; //apagando o mesmo disco da torre origem (para nao ter informção duplicada)
        visualizacao(tamanho, torres);//visualização das torres
        printf("\n\n");
    }

    else {
        /* Mover o n-1 disco de A para B, usando C de auxiliar */
        hanoi(n-1, origem, auxiliar, destino, tamanho, torres);
        /* Mover os discos restantes de A para C */
        printf("Mova o disco %d da torre %c para a torre %c  \n",n,origem,destino);

        //aqui segue mesmo raciocinio que o anterior do if(n==1)

        int de=origem-'A';
        int para=destino-'A';
        int poszero=primeironum(tamanho, torres, para)-1;
        int posnum=primeironum(tamanho, torres, de);

        torres[para][poszero] = torres[de][posnum];
        torres[de][posnum] = 0;
        visualizacao(tamanho, torres);
        printf("\n\n");

        /* Mover os n-1 discos de B para C usando A como auxiliar */
        hanoi(n-1, auxiliar, destino, origem, tamanho, torres);
    }
}

int main(){
    int n;
    printf("Digite o numero de discos : ");
    scanf("%d",&n);


    int torres[3][n];

    for(int i = 0; i < n; i++){
        torres[0][i]=i+1;
        torres[1][i]=0;
        torres[2][i]=0;
    }

    hanoi(n,'A','C','B', n, torres);

    return 0;
}

void visualizacao(int tamanho, int torres[3][tamanho]){
    for(int i=0; i < tamanho; i++){
        for(int j=0; j<3; j++){
            printf("%d      ", torres[j][i]);
        }
        printf("\n");
    }
    printf("A      B      C");
}

int primeironum(int tamanho, int torre[3][tamanho], int posicao){
    for(int i=0; i<tamanho; i++){
        if(torre[posicao][i]!=0){
            return i;
        }
    }
    return tamanho;
}