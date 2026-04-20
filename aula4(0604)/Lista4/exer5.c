#include <stdio.h>
//Implemente a versão recursiva da função que faz a busca sequencial em um vetor. Protótipo da função:
//int busca_seq_rec(int v[], int n, int chave);

int busca_seq_rec(int v[], int n, int chave){
    if (n==0) {
        return -1;
    }

    if (v[n-1]==chave) {
        return n;
    }

    return busca_seq_rec(v, n-1, chave);
}

int main(){
    int termos, chave;

    printf("quantos termos tera seu vetor: ");
    scanf("%d", &termos);

    int vetor[termos];

    printf("preencha o vetor:\n");
    for(int i=0; i<termos; i++){
        scanf("%d", &vetor[i]);
    }

    printf("\nQual sera a chave de busca: ");
    scanf("%d", &chave);
    
    int pos=busca_seq_rec(vetor, termos, chave);
    if(pos==-1){
        printf("\n\nnao foi encontrado");
    }else{
        printf("\n\nencontrado na posicao: %d", pos);
    }

    getchar();
    getchar();
}