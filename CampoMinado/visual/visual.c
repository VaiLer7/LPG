#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../definicao/definicao.h"
#include "../arquivacao/arquivacao.h"
#include "../dificuldade/dif.h"
#include "../funcionamento/funcional.h"
#include "visual.h"

void coloracao(char);
void visualizacao(int tam, char[tam][tam]);
void limparTela();
void pontuacoes(int*, int*, int*, float*, int*);
void desistencia(float*, int tam, char[tam][tam]);
void ganho(int, int qtdd_minas, int tam, char[tam][tam], int[qtdd_minas][2]);
void explodido(int qtdd_minas, int tam, char[tam][tam], int[qtdd_minas][2]);

#define ANSI_RESET "\033[0m"

#define ANSI_0 "\033[0;37m"//0
#define ANSI_1 "\033[1;34m"//1
#define ANSI_2 "\033[1;32m"//2
#define ANSI_3 "\033[1;38;2;255;0;0m"//3
#define ANSI_4 "\033[1;38;2;0;75;128m"//4
#define ANSI_5 "\033[1;38;2;255;128;0m"//5
#define ANSI_6 "\033[1;36m"//6
#define ANSI_7 "\033[1;35m"//7
#define ANSI_8 "\033[1;38;2;255;0;126m"//8

#define ANSI_BANDEIRA "\033[1;33m"//Bandeira
#define ANSI_BOMBA "\033[1;38;2;0;0;0m"//Bomba
#define ANSI_BOMBA_EXPLODIDA "\033[1;38;2;0;0;0m"//Bomba explodida
#define ANSI_NAO_DESCOBERTO "\033[1;37m"//Nao descoberto

void visualizacao(int tam, char tabela[tam][tam]){

    //numeracao coluna
    
    printf("     ");
    if(tam%10>9){
        printf(" ");
    }
    //numeracao  dezenas
    for(int i=0; i<tam; i++){
        char num = (i/10>0) ? (i/10)+48 : ' ';
        printf("%c ", num);
    }
    printf("\n");

    printf("     ");
    if(tam%10>9){
        printf(" ");
    }
    //numeracao resto
    for(int i=0; i<tam; i++){
        printf("%d ", i%10);
    }
    printf("\n");
    printf("\n");


    for(int i=0; i<tam; i++){

        //numeracao linha
        //numeracao dezena
        char num = (i/10>0) ? (i/10)+48 : ' ';
        printf("%c", num);

        //numeracao resto
        printf("%d   ", i%10);

        for(int j=0; j<tam; j++){
            coloracao(tabela[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void coloracao(char caractere){
    switch(caractere){
        case '0':
            printf(ANSI_0 "%c " ANSI_RESET, caractere);
            break;
        case '1':
            printf(ANSI_1 "%c " ANSI_RESET, caractere);
            break;
        case '2':
            printf(ANSI_2 "%c " ANSI_RESET, caractere);
            break;
        case '3':
            printf(ANSI_3 "%c " ANSI_RESET, caractere);
            break;
        case '4':
            printf(ANSI_4 "%c " ANSI_RESET, caractere);
            break;
        case '5':
            printf(ANSI_5 "%c " ANSI_RESET, caractere);
            break;
        case '6':
            printf(ANSI_6 "%c " ANSI_RESET, caractere);
            break;
        case '7':
            printf(ANSI_7 "%c " ANSI_RESET, caractere);
            break;
        case '8':
            printf(ANSI_8 "%c " ANSI_RESET, caractere);
            break;
        case 'P':
            printf(ANSI_BANDEIRA "%c " ANSI_RESET, caractere);
            break;
        case 'C':
            //printf(ANSI_CHORDING "%c " ANSI_RESET, caractere);
            printf("\033[1;33;2;0;0;0;41m%c\033[0m ", caractere);
            break;
        case 'X':
            printf(ANSI_BOMBA "%c " ANSI_RESET, caractere);
            break;
        case '+':
            printf(ANSI_NAO_DESCOBERTO "%c " ANSI_RESET, caractere);
            break;
        case '#':
            //printf(ANSI_BOMBA_EXPLODIDA "%c " ANSI_RESET, caractere);
            printf("\033[1;38;2;0;0;0;41m%c\033[0m ", caractere);
            break;
        default:
            printf("%c ", caractere);
            break;
    }
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #elif defined(__linux__) || defined(__unix__)
        system("clear");
    #elif defined(__APPLE__)
        system("clear");
    #else
        printf("Sistema operacional não suportado.\n");
    #endif
}

void pontuacoes(int *total_aberto, int *total_jogadas, int *qtdd_minas, float *pontuacao_atual, int *pontuacao_max){
    printf("\nQuadrados abertos sobrando: %d\n", *total_aberto);
    printf("Total jogadas: %d\n", *total_jogadas);
    printf("Quantidade de bombas: %d\n", *qtdd_minas);
    printf("Pontuacao atual: %.2f  |  Pontuacao maxima: %d\n", *pontuacao_atual, *pontuacao_max);
}

void desistencia(float *pontuacao_atual, int tam, char tabela[tam][tam]){
    limparTela();
    *pontuacao_atual=0;
    printf("Voce Desistiu!\n");
    visualizacao(tam, tabela);
}

void ganho(int total_jogadas, int qtdd_minas, int tam, char tabela_usuario[tam][tam], int localizacao_minas[qtdd_minas][2]){
    limparTela();
    printf("\nParabens! Voce concluiu o campo minado!\n");
    printf("Total jogadas: %d\n", total_jogadas);
    printf("Quantidade de bombas: %d\n", qtdd_minas);
    for(int i=0; i<qtdd_minas; i++){
        tabela_usuario[localizacao_minas[i][0]][localizacao_minas[i][1]]='P';
    }
    visualizacao(tam, tabela_usuario);
}

void explodido(int qtdd_minas, int tam, char tabela_usuario[tam][tam], int localizacao_bombas[qtdd_minas][2]){
    limparTela();
    for(int i=0; i<qtdd_minas; i++){
        char *quadrado = &tabela_usuario[localizacao_bombas[i][0]][localizacao_bombas[i][1]];
        
        if(*quadrado!='P' && *quadrado!='#'){
            *quadrado='X';
        }
    }
    visualizacao(tam, tabela_usuario);
}