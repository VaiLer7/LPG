#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../definicao/definicao.h"
#include "../arquivacao/arquivacao.h"
#include "dif.h"
#include "../funcionamento/funcional.h"
#include "../visual/visual.h"

void perfil(int tam, int qtdd_bombas, char[tam][tam], char[tam][tam], int[qtdd_bombas][2]);
void personalizado(int*, int*);
char *dificuldade(int);
void escolhas(int, int*, int*);

void personalizado(int *tam, int *qtdd_minas){
    printf("\ninsira o tamanho do jogo(max 100): ");
    scanf("%d", tam);

    printf("\nescolha a porcentagem de preenchimento (0 a 100): ");
    scanf("%d", qtdd_minas);
}

void perfil(int tam, int qtdd_minas, char tabela[tam][tam], char tabela_usuario[tam][tam], int localizacao_bombas[qtdd_minas][2]){
    preenchimento(tam, tabela, '0');
    minas(qtdd_minas, tam, tabela, localizacao_bombas);
    preenchimento(tam, tabela_usuario, '+');
}

char *dificuldade(int escolha){
    switch(escolha){
        case 1:
            return "iniciante";
        case 2:
            return "facil";
        case 3:
            return "mediano";
        case 4:
            return "dificil";
        case 5:
            return "insano";
        case 6:
            return "pers";
    }
}

void escolhas(int escolha, int *tam, int *qtdd_minas){
    switch(escolha){
        case 1://iniciante
            *tam=8;
            *qtdd_minas=8;
            break;
        case 2://facil
            *tam=10;
            *qtdd_minas=10;
            break;
        case 3://mediano
            *tam=16;
            *qtdd_minas=16;
            break;
        case 4://dificil
            *tam=22;
            *qtdd_minas=22;
            break;
        case 5://insano
            *tam=50;
            *qtdd_minas=24;
            break;
        case 6://personalizado
            personalizado(tam, qtdd_minas);
            break;
        default:
            limparTela();
            printf("Valor nao reconhecido, tente novamente!\n");
            break;
    }
}