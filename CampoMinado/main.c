#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void visualizacao(int tam, char[tam][tam]); //visual
void preenchimento(int tam, char[tam][tam], char); //def
void minas(int qtdd_bombas, int tam, char[tam][tam], int[qtdd_bombas][2]); //def
void numeracao(int, int, int tam, char[tam][tam]); //def
void cascata(int, int, int tam, char[tam][tam], char[tam][tam], int*); //def
void perfil(int tam, int qtdd_bombas, char[tam][tam], char[tam][tam], int[qtdd_bombas][2]); //dif
void personalizado(int*, int*); //dif

void bandeira(int*, float*, int*, int*, int*, int tam, char[tam][tam], char[tam][tam]); //func
void clicar(int*, float*, int*, int*, int*, int tam, char[tam][tam], char[tam][tam]); //func

void criacao(); //arq
void gravacao(int, float); //arq
char *dificuldade(int); //dif

void coloracao(char); //visual

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
// ^^visual

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
        do{
            printf("\nQual modo de jogo deseja?\n");
            printf("1 - Iniciante\n");
            printf("2 - Facil\n");
            printf("3 - Mediano\n");
            printf("4 - Dificil\n");
            printf("5 - Insano\n");
            printf("6 - Personalizado\n");

            scanf(" %d", &escolha);

            switch(escolha){
                case 1://iniciante
                    tam=8;
                    qtdd_minas=8;
                    break;
                case 2://facil
                    tam=10;
                    qtdd_minas=10;
                    break;
                case 3://mediano
                    tam=16;
                    qtdd_minas=16;
                    break;
                case 4://dificil
                    tam=22;
                    qtdd_minas=22;
                    break;
                case 5://insano
                    tam=50;
                    qtdd_minas=24;
                    break;
                case 6://personalizado
                    personalizado(&tam, &qtdd_minas);
                    break;
                default:
                    printf("\nValor nao reconhecido, tente novamente!\n");
                    break;
            }
        }while(escolha<1||escolha>6);

        char tabela[tam][tam];
        char tabela_usuario[tam][tam];
                    
        qtdd_minas=(tam*tam)*((float)qtdd_minas/100);

        int localizacao_bombas[qtdd_minas][2];

        perfil(tam, qtdd_minas, tabela, tabela_usuario, localizacao_bombas);
        
        visualizacao(tam, tabela); //pra ativar cheat se necessario
        
        int i, j;

        int pontuacao_max=(tam*tam)*qtdd_minas;
        float pontuacao_atual=(float)pontuacao_max;
        int total_aberto = (tam*tam) - qtdd_minas;
        int total_jogadas = 0;
        int modo;
        do{
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
                    if(total_aberto==0) break;
                    break;
                case -1:
                    total_aberto=-2;
                    break;
                default:
                    printf("\nComando nao identificado, tente novamente!\n");
                    break;
            }
        }while(total_aberto>0);

        switch(total_aberto){
            case 0://ganho
                printf("\nParabens! Voce concluiu o campo minado!\n");
                printf("Total jogadas: %d\n", total_jogadas);
                printf("Quantidade de bombas: %d\n", qtdd_minas);
                visualizacao(tam, tabela_usuario);
                break;
            case -1://bomba
                printf("Bomba acertada! ");
                for(int i=0; i<qtdd_minas; i++){
                    char *quadrado = &tabela_usuario[localizacao_bombas[i][0]][localizacao_bombas[i][1]];
                    
                    if(*quadrado!='P' && *quadrado!='#'){
                        *quadrado='X';
                    }
                }
                visualizacao(tam, tabela_usuario);
                break;
            case -2://desistencia
                pontuacao_atual=0;
                printf("Voce Desistiu!\n");
                visualizacao(tam, tabela);
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

void criacao(){
    FILE *arquivo = fopen("arquivo.txt", "a");

    if(arquivo==NULL){
        printf("Erro na criacao do arquivo!");
        exit(1);
    }

    for(int i=0; i<4; i++){
        fputs(" \n", arquivo);
    }

    fclose(arquivo);
}

void gravacao(int escolha, float pontuacao){
    char caractere;
    char txt_pontuacao[50];

    FILE *arquivo=fopen("arquivo.txt", "r++");
    rewind(arquivo);

    for(int i=1; i<escolha; i++){
        do{
            caractere = fgetc(arquivo);
        }while(caractere!='\n' && caractere!=EOF);
    }
    fgets(txt_pontuacao, 50, arquivo);
    
    char *palavra_dificuldade = malloc(10*sizeof(char));
    
    palavra_dificuldade = dificuldade(escolha);

    sprintf(txt_pontuacao, "Pontuacao modo %s: %f\n", palavra_dificuldade, pontuacao);

    rewind(arquivo);

    for(int i=1; i<escolha; i++){
        do{
            caractere = fgetc(arquivo);
        }while(caractere!='\n' && caractere!=EOF);
    }

    int erro = fputs(txt_pontuacao, arquivo);

    if(erro==EOF) printf("Erro ao gravar dados!\n");

    fclose(arquivo);
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

void personalizado(int *tam, int *qtdd_minas){
    printf("insira o tamanho do jogo(max 100): ");
    scanf("%d", tam);

    printf("\nescolha a porcentagem de preenchimento (0 a 100): ");
    scanf("%d", qtdd_minas);
}

void perfil(int tam, int qtdd_minas, char tabela[tam][tam], char tabela_usuario[tam][tam], int localizacao_bombas[qtdd_minas][2]){
    preenchimento(tam, tabela, '0');
    minas(qtdd_minas, tam, tabela, localizacao_bombas);
    preenchimento(tam, tabela_usuario, '+');
    visualizacao(tam, tabela_usuario);
}

void bandeira(int *pontuacao_max, float *pontuacao_atual, int *qtdd_bombas, int *total_jogadas, int *total_aberto, int tam, char tabela[tam][tam], char tabela_usuario[tam][tam]){
    do{
        visualizacao(tam, tabela_usuario);

        printf("\nPara sair do modo 'Colocar Bandeira', digite qualquer numero negativo nas cordenadas\n");
        int i, j;
        printf("\nSelecione linha e coluna: \nLinha: ");
        scanf(" %d", &i);

        if(i<0){
            break;
        }

        printf("Coluna: ");
        scanf(" %d", &j);
        if(j<0){
            break;
        }

        if(tabela_usuario[i][j]>='0'&&tabela_usuario[i][j]<='8'){
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

        float dificuldade = ((float)*qtdd_bombas) / (tam * tam);

        *pontuacao_atual=1 + (*pontuacao_max - 1) / (1 + (*total_jogadas) * (1.0f - dificuldade));;

        printf("\nQuadrados abertos sobrando: %d\n", *total_aberto);
        printf("Total jogadas: %d\n", *total_jogadas);
        printf("Quantidade de bombas: %d\n", *qtdd_bombas);
        printf("Pontuacao atual: %.2f  |  Pontuacao maxima: %d\n", *pontuacao_atual, *pontuacao_max);
    }while(1);
}

void clicar(int *pontuacao_max, float *pontuacao_atual, int *qtdd_bombas, int *total_jogadas, int *total_aberto, int tam, char tabela[tam][tam], char tabela_usuario[tam][tam]){
    do{
        visualizacao(tam, tabela_usuario);

        printf("\nPara sair do modo 'Clicar cordenada', digite qualquer numero negativo nas cordenadas\n");
        int i, j;
        printf("\nSelecione linha e coluna: \nLinha: ");
        scanf(" %d", &i);

        if(i<0){
            break;
        }

        printf("Coluna: ");
        scanf(" %d", &j);
        if(j<0){
            break;
        }
        
        (*total_jogadas)++;

        float dificuldade = ((float)*qtdd_bombas) / (tam * tam);

        *pontuacao_atual=1 + (*pontuacao_max - 1) / (1 + (*total_jogadas) * (1.0f - dificuldade));;

        if(tabela[i][j]=='X'){
            tabela_usuario[i][j]='#';
        if(*total_aberto==0){
            break;
        }
            *pontuacao_atual=0;
            *total_aberto=-1;
            break;
        }

        cascata(i, j, tam, tabela, tabela_usuario, total_aberto);

        visualizacao(tam, tabela_usuario);
        printf("\nQuadrados abertos sobrando: %d\n", *total_aberto);
        printf("Total jogadas: %d\n", *total_jogadas);
        printf("Quantidade de bombas: %d\n", *qtdd_bombas);
        printf("Pontuacao atual: %.2f  |  Pontuacao maxima: %d\n", *pontuacao_atual, *pontuacao_max);
    }while(1);
}

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

void preenchimento(int tam, char tabela[tam][tam], char conteudo){
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            tabela[i][j]=conteudo;
        }
    }
}

void minas(int preenchimento, int tam, char tabela[tam][tam], int localizacao_bombas[preenchimento][2]){
    for(int i=0; i<preenchimento; i++){
        int num1;
        int num2;
        do{
            num1=rand()%tam;
            num2=rand()%tam;
        }while(tabela[num1][num2]=='X');

        localizacao_bombas[i][0]=num1;
        localizacao_bombas[i][1]=num2;

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

void cascata(int i, int j, int tam, char tabela[tam][tam], char tabela_usuario[tam][tam], int *area_aberta){
    if(tabela[i][j]=='0'){
        for(int i2=i-1; i2<=i+1; i2++){
            if(i2>=0&&i2<tam){
                for(int j2=j-1; j2<=j+1; j2++){
                    if(j2>=0&&j2<tam){
                        if(tabela[i2][j2]>='0'&&tabela[i2][j2]<='9'){
                            if(tabela_usuario[i2][j2] == '+'){
                                (*area_aberta)--;
                                tabela_usuario[i2][j2] = tabela[i2][j2];
                                if(tabela[i2][j2] == '0'){
                                    cascata(i2, j2, tam, tabela, tabela_usuario, area_aberta);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        (*area_aberta)--;
        tabela_usuario[i][j]=tabela[i][j];
    }
}