#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "../definicao/definicao.h"
#include "arquivacao.h"
#include "../dificuldade/dif.h"
#include "../funcionamento/funcional.h"
#include "../visual/visual.h"

void criacao();
void gravacao(int, float);
float leitura_valor(char[]);
int potenciacao(int, int);

void criacao(){ //cria arquivo se nao existir
    FILE *arquivo = fopen("arquivo.txt", "a");

    if(arquivo==NULL){
        printf("Erro na criacao do arquivo!");
        exit(1); //encerra programa caso erro
    }
    fclose(arquivo);
}

void gravacao(int escolha, float pontuacao){
    char linhas[5][100] = {
        "",
        "",
        "",
        "",
        ""
    };

    FILE *arquivo = fopen("arquivo.txt", "r");

    if(arquivo != NULL){
        for(int i = 0; i < 5; i++){
            if(fgets(linhas[i], sizeof(linhas[i]), arquivo) == NULL) linhas[i][0] = '\n'; //pega linha no arquivo e guarda na matriz linhas, se nao tiver linha, "cria" uma com '\n' 
        }
        fclose(arquivo);
    }else{
        printf("Erro ao abrir o arquivo! (r)\n");
        exit(1);
    }

    char *palavra_dificuldade = dificuldade(escolha);
    


    if(escolha!=6){ //exlcuindo a opção "personalizado" 
        if(linhas[escolha-1][0]=='\n'){
            sprintf(linhas[escolha-1], "Pontuacao modo %s: %.2f\n", palavra_dificuldade, pontuacao);
        }else{
            float valor = leitura_valor(linhas[escolha-1]); //pega o valor dentro da linha
            if(valor<=pontuacao){
                sprintf(linhas[escolha-1], "Pontuacao modo %s: %.2f\n", palavra_dificuldade, pontuacao); //atualiza matriz
            }
        }
    }

    arquivo = fopen("arquivo.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo! (w)\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++){ //reescreve todo o arquivo com a nova matriz
        fputs(linhas[i], arquivo);
    }

    fclose(arquivo);
}

float leitura_valor(char texto[]){
    int i=0;

    for(; texto[i]!='\0' && !isdigit(texto[i]); i++); //identifica aonde começa o numero

    if(texto[i] == '\0'){
        return 0;
    }
    
    int expoente = strlen(texto)-i-2; //-2 vem do: '/n' + o ponto ('.')
    int mult = potenciacao(10, expoente);

    float valor=0;

    for(; texto[i] != '\0' && texto[i] != '\n'; i++){ //conversao de texto pra numero
        if(texto[i]!='.'){
            valor += (float)(texto[i]-'0') * (float)mult;
            mult=(mult/10);
        }
    }

    valor = valor/100; //movendo os ultimos 2 caracteres para casas decimais

    return valor;
}

int potenciacao(int base, int expoente){
    if(expoente==0) return 1;

    return base * potenciacao(base, expoente-1);
}