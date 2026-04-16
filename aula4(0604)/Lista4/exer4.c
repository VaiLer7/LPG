#include <stdio.h>
//Escreva uma função que recebe um vetor v, sua capacidade n e uma chave de busca. A função também recebe um vetor que vai armazenar os índices em que a chave se encontra em v. A função deve fazer a busca de maneira sequencial e armazenar os índices em que a chave se encontra e preencher o resto do vetor com -1. Os vetores v e indices devem ter a mesma capacidade. Protótipo da função:
//void busca_todos(int v[], int n, int chave, int indices[]);

void busca_todos(int v[], int n, int chave, int indices[]){
    int cont=0;
    for(int i=0; i<n; i++){
        if(v[i]==chave) indices[cont++]=i;
    }
    for(; cont<n; cont++){
        indices[cont]=-1;
    }

    printf("\n\n");
    for(int i=0; i<n; i++){
        printf("%d ", indices[i]);
    }
}

int main(){
    int termos, chave;

    printf("quantos termos tera seu vetor: ");
    scanf("%d", &termos);

    int vetor[termos], indices[termos];

    printf("preencha o vetor:\n");
    for(int i=0; i<termos; i++){
        scanf("%d", &vetor[i]);
    }

    printf("\nQual sera a chave de busca: ");
    scanf("%d", &chave);
    
    busca_todos(vetor, termos, chave, indices);

    getchar();
    getchar();
}