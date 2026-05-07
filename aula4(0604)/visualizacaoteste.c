#include <stdio.h>

void visualizacao(int tamanho, int torres[tamanho][3]);

int main(){
    int n;

    printf("quantos discos deseja ter: ");
    scanf("%d", &n);

    int torres[3][n];

    for(int i = 0; i < n; i++){
        torres[0][i]=i+1;
        torres[1][i]=0;
        torres[2][i]=0;
    }

    visualizacao(n, torres);

    return 0;
}

void visualizacao(int tamanho, int torres[3][tamanho]){
    for(int i=0; i < tamanho; i++){
        for(int j=0; j<3; j++){
            printf("%d      ", torres[j][i]);
        }
        printf("\n");
    }
}