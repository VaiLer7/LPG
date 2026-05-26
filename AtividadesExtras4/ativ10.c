#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addnum(int**, int*);
void remnum(int**, int*);
void listar(int*, int);

int SomenteNum(char str[]);
int potencia(int base, int expo);
int conversao(char stringue[]);

int main(){
    printf("Oque deseja fazer?\n");
    
    char escolha;
    
    int tam=0;
    int *vetor = NULL;
    do{
        printf("1 - Adicionar numeros\n");
        printf("2 - Remover numeros\n");
        printf("3 - Listar numeros\n");
        printf("4 - Sair\n");
        scanf(" %c", &escolha);
        printf("\n");

        switch(escolha){
            case '1':
                addnum(&vetor, &tam);
                break;
            case '2':
                remnum(&vetor, &tam);
                break;
            case '3':
                listar(vetor, tam);
                break;
            case '4':
                printf("Terminando programa\n");
                break;
            default:
                printf("Caractere nao correspondente, tente novamente:\n");
                break;
        }
    }while(escolha!='4');

    free(vetor);

    return 0;
}

void addnum(int **vetor, int *tam){
    printf("Para parar de adicionar numeros, digite qualquer caractere que nao seja numero:\n");
    char texto[12];
    int ehnum, numero;
    do{
        scanf("%s", texto);
        ehnum = SomenteNum(texto);
        if(ehnum) {
            numero = conversao(texto);

            (*tam)++;

            *vetor=realloc(*vetor, *tam*sizeof(int));

            (*vetor)[*tam-1]=numero;

        }
    }while(ehnum);

    printf("\nOque deseja fazer agora?\n");
}

void remnum(int **vetor, int *tam){
    if(*tam==0){
        printf("Nao eh possivel remover nenhum numero, vetor vazio!\n\n");
    }else{
        char res;
        do{
            printf("Deseja apagar esse numero: %d?\n(y/n): ", (*vetor)[*tam-1]);
            scanf(" %c", &res);
            printf("\n");
            if(res=='y'){
                (*tam)--;
            }
        }while(res=='y'&&*tam>0);

        if(*tam==0) {
            printf("O vetor esvaziou, encha-o novamente!\n\n");

            free(*vetor);
            *vetor=NULL;
        }
    }
}

void listar(int *vetor, int tam){
    if(tam==0){
        printf("Nao eh possivel listar nenhum numero, vetor vazio!\n\n");
    }else{
        printf("O vetor possui %d entradas, sendo elas:\n", tam);
        for(int i=0; i<tam; i++){
            printf("%d ", *(vetor+i));
        }
        printf("\n\n");
    }
}



//mecanismos de funcionamento
int SomenteNum(char str[]){
    int i=0;
    if(str[0]=='-') i=1;
    for(; str[i]!='\0'; i++){
        if(str[i]<'0' || str[i]>'9') return 0;
    }
    return 1;
}

int potencia(int base, int expo){
    if(expo==0) return 1;

    return base * potencia(base, expo-1);
}

int conversao(char stringue[]){
    int i=0, mult=1;
    if(stringue[0]=='-'){
        i=1;
        mult=-1;
    }
    int valor=0;

    int tamanho = potencia(10, strlen(stringue)-(1+i));

    for(; stringue[i]!='\0'; i++){
        valor+=(stringue[i]-'0')*tamanho;
        tamanho=(tamanho/10);
    }
    return valor*mult;
}