#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "definicao.h"
#include "../arquivacao/arquivacao.h"
#include "../dificuldade/dif.h"
#include "../funcionamento/funcional.h"
#include "../visual/visual.h"

void preenchimento(int tam, char[tam][tam], char);
void minas(int qtdd_bombas, int tam, char[tam][tam], int[qtdd_bombas][2]);
void numeracao(int, int, int tam, char[tam][tam]);
void cascata(int, int, int tam, char[tam][tam], char[tam][tam], int*, float*, int);
int qtdd_bandeiras(int, int, int tam, char[tam][tam]);
void chording(int, int, int tam, char[tam][tam], char[tam][tam], int*, float*);


void preenchimento(int tam, char tabela[tam][tam], char conteudo){
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            tabela[i][j]=conteudo;
        }
    }
}

void minas(int preenchimento, int tam, char tabela[tam][tam], int localizacao_minas[preenchimento][2]){
    for(int i=0; i<preenchimento; i++){
        int num1;
        int num2;
        do{
            num1=rand()%tam;
            num2=rand()%tam;
        }while(tabela[num1][num2]=='X');

        localizacao_minas[i][0]=num1;
        localizacao_minas[i][1]=num2;

        numeracao(num1, num2, tam, tabela);
        tabela[num1][num2]='X';
    }
}

void numeracao(int i, int j, int tam, char tabela[tam][tam]){
    for(int i2=i-1; i2<=i+1; i2++){
        if(i2>=0&&i2<tam){
            for(int j2=j-1; j2<=j+1; j2++){
                if(j2>=0&&j2<tam){
                    if(tabela[i2][j2]!='X') (tabela[i2][j2])++;
                }
            }
        }
    }
}

void cascata(int i, int j, int tam, char tabela[tam][tam], char tabela_usuario[tam][tam], int *total_aberto, float *pontuacao_atual, int boolchord){
    if(tabela[i][j]=='0'){
        for(int i2=i-1; i2<=i+1; i2++){
            if(i2>=0&&i2<tam){
                for(int j2=j-1; j2<=j+1; j2++){
                    if(j2>=0&&j2<tam){
                        if(isdigit(tabela[i2][j2])){
                            if(tabela_usuario[i2][j2] == '+'){
                                (*total_aberto)--;
                                tabela_usuario[i2][j2] = tabela[i2][j2];
                                if(tabela[i2][j2] == '0'){
                                    cascata(i2, j2, tam, tabela, tabela_usuario, total_aberto, pontuacao_atual, 0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(tabela_usuario[i][j]=='+'){//se nao for 0, vai ser numero, pois senao ja teria explodido até aqui (na funcao clicar antes de chamar funcao cascata)
        int bandeiras = qtdd_bandeiras(i, j, tam, tabela_usuario);
        if(bandeiras==tabela[i][j]-'0'&& boolchord==1){

            printf("\n\nbandeiras: %d | numero do quadrado: %d\n\n", bandeiras, tabela[i][j]-'0');

            chording(i, j, tam, tabela, tabela_usuario, total_aberto, pontuacao_atual);
        }else{
            (*total_aberto)--;
            tabela_usuario[i][j]=tabela[i][j];
        }
    }
}

int qtdd_bandeiras(int i, int j, int tam, char tabela_usuario[tam][tam]){
    int bandeiras=0;
    for(int i2=i-1; i2<=i+1; i2++){
        if(i2>=0&&i2<tam){
            for(int j2=j-1; j2<=j+1; j2++){
                if(j2>=0&j2<tam){
                    if(tabela_usuario[i2][j2]=='P'){
                        bandeiras++;
                    }
                }
            }
        }
    }

    return bandeiras;
}

void chording(int i, int j, int tam, char tabela[tam][tam], char tabela_usuario[tam][tam], int *total_aberto, float *pontuacao_atual){
    int explodiu=0;
    for(int i2=i-1; i2<=i+1; i2++){
        if(i2>=0&&i2<tam){
            for(int j2=j-1; j2<=j+1; j2++){
                if(j2>=0&j2<tam){
                    if(tabela_usuario[i2][j2]!='P'&&!isdigit(tabela_usuario[i2][j2])){

                        if(tabela[i2][j2]=='X'){
                            explodiu=1;
                            tabela_usuario[i2][j2]='#';
                        }

                        cascata(i2, j2, tam, tabela, tabela_usuario, total_aberto, pontuacao_atual, 0);

                    }
                }
            }
        }
    }
    if(explodiu){
        *pontuacao_atual=0;
        *total_aberto=-1;
    }
}