#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "definicao/definicao.h"
#include "arquivacao/arquivacao.h"
#include "dificuldade/dif.h"
#include "funcionamento/funcional.h"
#include "visual/visual.h"

//cd (caminho pra pasta CampoMinado)
//gcc $(find -name "*.c") -o programa
//./programa

int main(){
    srand(time(NULL));
    int escolha;
    int tam;
    int qtdd_minas;
    char jogar_novamente='n';

    FILE *arquivo;

    arquivo = fopen("arquivo.txt", "r");

    if(arquivo==NULL){
        criacao();
    }else{
        fclose(arquivo);
    }

    do{
        limparTela();
        do{
            printf("Qual modo de jogo deseja?\n");
            printf("1 - Iniciante\n");
            printf("2 - Facil\n");
            printf("3 - Mediano\n");
            printf("4 - Dificil\n");
            printf("5 - Insano\n");
            printf("6 - Personalizado\n");

            scanf(" %d", &escolha);

            escolhas(escolha, &tam, &qtdd_minas);
        }while(escolha<1||escolha>6);

        char tabela[tam][tam];
        char tabela_usuario[tam][tam];
                    
        qtdd_minas=(tam*tam)*((float)qtdd_minas/100); //transforma o numero de porcentagem de minas, em quantidade de minas totais

        int localizacao_minas[qtdd_minas][2];

        limparTela();

        perfil(tam, qtdd_minas, tabela, tabela_usuario, localizacao_minas); //cria as tabelas

        int pontuacao_max=(tam*tam)*qtdd_minas;
        float pontuacao_atual=(float)pontuacao_max;
        int total_aberto = (tam*tam) - qtdd_minas;
        int total_jogadas = 0;
        do{
            int modo;

            limparTela();
            pontuacoes(&total_aberto, &total_jogadas, &qtdd_minas, &pontuacao_atual, &pontuacao_max);
            visualizacao(tam, tabela_usuario);
            //visualizacao(tam, tabela); //retirar '//' caso queira xitar
            
            printf("Deseja:\n");
            printf(" 1 - Modo: Colocar bandeira \n");
            printf(" 2 - Modo: Clicar cordenada \n");
            printf("-1 - Desistir \n");
            scanf(" %d", &modo);

            switch(modo){
                case 1:
                    bandeira(&pontuacao_max, &pontuacao_atual, &qtdd_minas, &total_jogadas, &total_aberto, tam, tabela, tabela_usuario);
                    break;
                case 2:
                    clicar(&pontuacao_max, &pontuacao_atual, &qtdd_minas, &total_jogadas, &total_aberto, tam, tabela, tabela_usuario);
                    break;
                case -1:
                    total_aberto=-2;
                    break;
                default:
                    break;
            }
        }while(total_aberto>0);

        switch(total_aberto){
            case 0://ganho
                ganho(total_jogadas, qtdd_minas, tam, tabela_usuario, localizacao_minas);
                break;
            case -1://bomba
                explodido(qtdd_minas, tam, tabela_usuario, localizacao_minas);
                break;
            case -2://desistencia
                desistencia(&pontuacao_atual, tam, tabela);
                break;
            default:
                printf("ERRO!\n %d", total_aberto);    
                break;
        }
        
        printf("Pontuacao final: %.2f  |  Pontuacao maxima: %d\n", pontuacao_atual, pontuacao_max);

        gravacao(escolha, pontuacao_atual);

        printf("Jogo finalizado!\n");
        
        printf("\nDeseja jogar novamente?(y/n) ");
        scanf(" %c", &jogar_novamente);
    }while(jogar_novamente=='y');
}