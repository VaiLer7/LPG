#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "../definicao/definicao.h"
#include "../arquivacao/arquivacao.h"
#include "../dificuldade/dif.h"
#include "funcional.h"
#include "../visual/visual.h"

void bandeira(int*, float*, int*, int*, int*, int tam, char[tam][tam], char[tam][tam]);
void clicar(int*, float*, int*, int*, int*, int tam, char[tam][tam], char[tam][tam]);

void bandeira(int *pontuacao_max, float *pontuacao_atual, int *qtdd_minas, int *total_jogadas, int *total_aberto, int tam, char tabela[tam][tam], char tabela_usuario[tam][tam]){
    do{
        limparTela();
        
        pontuacoes(total_aberto, total_jogadas, qtdd_minas, pontuacao_atual, pontuacao_max);
        
        visualizacao(tam, tabela_usuario);

        printf("\nPara sair do modo 'Colocar Bandeira', digite qualquer numero negativo nas cordenadas\n");
        int i, j;
        printf("\nSelecione linha e coluna:\n");

        printf("Linha: ");
        scanf(" %d", &i);
        if(i<0){
            break;
        }

        printf("Coluna: ");
        scanf(" %d", &j);
        if(j<0){
            break;
        }

        if(isdigit(tabela_usuario[i][j])){
            break;
        }

        switch(tabela_usuario[i][j]){
            case 'P':
                tabela_usuario[i][j]='+';
                break;
            default:
                tabela_usuario[i][j]='P';
                break;
        }

        (*total_jogadas)++;

        float dificuldade = ((float)*qtdd_minas) / (tam * tam);

        *pontuacao_atual=1 + (*pontuacao_max - 1) / (1 + (*total_jogadas) * (1.0f - dificuldade));;

        pontuacoes(total_aberto, total_jogadas, qtdd_minas, pontuacao_atual, pontuacao_max);
    }while(1);
}

void clicar(int *pontuacao_max, float *pontuacao_atual, int *qtdd_minas, int *total_jogadas, int *total_aberto, int tam, char tabela[tam][tam], char tabela_usuario[tam][tam]){
    do{
        limparTela();

        pontuacoes(total_aberto, total_jogadas, qtdd_minas, pontuacao_atual, pontuacao_max);

        visualizacao(tam, tabela_usuario);

        printf("\nPara sair do modo 'Clicar cordenada', digite qualquer numero negativo nas cordenadas\n");
        int i, j;
        printf("\nSelecione linha e coluna: \n");

        printf("Linha: ");
        scanf(" %d", &i);
        if(i<0){
            break;
        }

        printf("Coluna: ");
        scanf(" %d", &j);
        if(j<0){
            break;
        }
        
        if(tabela_usuario[i][j]!='P'&&!isdigit(tabela_usuario[i][j])){
            (*total_jogadas)++;

            float dificuldade = ((float)*qtdd_minas) / (tam * tam);

            *pontuacao_atual=1 + (*pontuacao_max - 1) / (1 + (*total_jogadas) * (1.0f - dificuldade));;

            if(tabela[i][j]=='X'){
                tabela_usuario[i][j]='#';
                *pontuacao_atual=0;
                *total_aberto=-1;
                break;
            }

            int bool_chording=1;

            cascata(i, j, tam, tabela, tabela_usuario, total_aberto, pontuacao_atual, bool_chording);

            if(*total_aberto<=0){
                break;
            }
        }
    }while(1);
}