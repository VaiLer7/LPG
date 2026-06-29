#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char pais[50];
    char grupo;
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
} Selecao;

void cadastrarSelecao(int*, Selecao[]);
void listarSelecoes(int, Selecao[], int, int);
void buscarSelecao(Selecao[], int);
void calcularClassificacao();
void impressao(Selecao[], int);
void ordenacao(int **classificacao_vetor, int tamanho);
void impressao_ranking(int tamanho, int **classificacao, Selecao selecoes[]);
void criacao();
void leitura(Selecao*, int*);
int conversao(char[]);
void guarda_info(Selecao*, int, int, int);
int pot(int, int);
void cadastro_impressao(int, char[]);
const char *texto_cadastro(int);
void tratamento_grupo(char[]);
void tratamento_resto(char[]);
void removerSelecao(Selecao[], int*);
void limparTela();


int main(){ 

    Selecao selecoes[100];
    int tamanho=0;

    FILE *arquivo;

    arquivo = fopen("arquivo.txt", "r");

    if(arquivo==NULL){
        criacao();
    }else{
        fclose(arquivo);
    }

    int escolha;
    do{
        leitura(selecoes, &tamanho);

        printf("Deseja fazer oque?\n");
        printf("1 - Cadastrar nova selecao\n");
        printf("2 - Listar todos os paises e suas informacoes\n");
        printf("3 - Buscar por pais individual\n");
        printf("4 - Ranking atual\n");
        printf("5 - Remover uma selecao\n");
        printf("6 - Sair\n");

        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                limparTela();
                cadastrarSelecao(&tamanho, selecoes);
                break;
            case 2:
                limparTela();
                listarSelecoes(tamanho, selecoes, 0, 0);
                break;
            case 3:
                limparTela();
                buscarSelecao(selecoes, tamanho);
                break;
            case 4:
                limparTela();
                calcularClassificacao(selecoes, tamanho);
                break;
            case 5:
                limparTela();
                removerSelecao(selecoes, &tamanho);
                break;
            case 6:
                printf("Saindo...\n");
                return 1;
                break;
            default:
                printf("Comando nao identificado, tente novamente!");
                break;
        }
    }while(escolha>0||escolha<7);
}

void removerSelecao(Selecao selecoes[], int *ultimo){
    char busca[50];
    printf("\nqual selecao deseja apagar? ");
    getchar();
    fgets(busca, 50, stdin);
    busca[strlen(busca)-1] = '\0';

    int apagado;
    int igual=0;
    for(apagado=0; apagado<*ultimo; apagado++){
        if(strcmp(selecoes[apagado].pais, busca)==0){
            igual=1;
            break;
        }
    }

    if(!igual){
        printf("\nSelecao nao encontrada!\n");
        return;
    }
    
    FILE *arquivo = fopen("arquivo.txt", "r");
    FILE *temp = fopen("temp.txt", "a");

    for(int i=0; i<*ultimo; i++){
        if(i!=apagado){
            char informacao[256];
            fgets(informacao, 256, arquivo);

            fputs(informacao, temp);
        }else{
            char deletado[256];
            fgets(deletado, 256, arquivo);
        }
    }

    (*ultimo)--;

    remove("arquivo.txt");
    rename("temp.txt", "arquivo.txt");

    fclose(arquivo);
    fclose(temp);

    printf("Selecao '%s' apagada!\n\n", busca);
    
}

void cadastrarSelecao(int *posicao, Selecao selecoes[]){
    char info[TMP_MAX] = "";
    char pais_txt[50];

    printf("\ndigite o nome da nova selecao: "); //fgets
    getchar();
    fgets(pais_txt, 50, stdin);
    pais_txt[strcspn(pais_txt, "\n")] = ';';
    strcat(info, pais_txt);

    printf("%s", texto_cadastro(1));
    char grupo_txt[16];
    scanf(" %s", grupo_txt);
    tratamento_grupo(grupo_txt);
    strcat(info, grupo_txt);
    strcat(info, ";");

    for(int i=2; i<8; i++) cadastro_impressao(i, info); //scanf com string
    info[strlen(info)-1]='\n';
    printf("\n");

    (*posicao)++;

    FILE *arquivo = fopen("arquivo.txt", "r+");

    fseek(arquivo, 0, SEEK_END);
    
    fputs(info, arquivo);

    fclose(arquivo);
}

void cadastro_impressao(int i, char info[]){
    const char *texto = texto_cadastro(i);
    printf("%s", texto);

    char parte_info[16];
    scanf(" %s", parte_info);
    tratamento_resto(parte_info);
    strcat(info, parte_info);
    strcat(info, ";");
}

void tratamento_grupo(char texto[]){
    int bool;
    do{
        bool=0;
        if(strlen(texto)>1){
            printf("Somente uma caractere! Digite novamente: ");
            scanf(" %s", texto);
            bool=1;
        }else if(texto[0]>'0'&&texto[0]<'9'){
            printf("Deve ser uma letra! Digite novamente: ");
            scanf(" %s", texto);
            bool=1;
        }
        if(bool==0){
            texto[0]=toupper(texto[0]);
        }
    }while(bool==1);
}

void tratamento_resto(char texto[]){
    int bool;
    do{
        bool=0;
        int tamanho_str = strlen(texto);
        for(int i=0; texto[i]!='\0'; i++){
            if(!isdigit(texto[i])){
                bool=1;
                break;
            }
        }
        if(bool==1){
            printf("Deve ser somente numero! Digite novamente: ");
            scanf(" %s", texto);
        }
    }while(bool==1);
}

const char *texto_cadastro(int i){
    switch (i) {
        case 1: return "digite o grupo: ";
        case 2: return "digite o numero de jogos: ";
        case 3: return "digite a quantidade de vitorias: ";
        case 4: return "digite a quantidade de empates: ";
        case 5: return "digite a quantidade de derrotas: ";
        case 6: return "digite a quantidade de gols marcados: ";
        case 7: return "digite a quantidade de gols sofridos: ";
        default: return "erro! ";
    }
}

void listarSelecoes(int ultimo, Selecao selecoes[], int unico, int posicao){
    printf("\n");
    if(ultimo==0){
        printf("Sem selecoes cadastradas!\n\n");
        return;
    }
    do{
        impressao(selecoes, posicao);
        posicao++;
        printf("\n");
    }while(unico==0&&posicao<ultimo);
}

void impressao(Selecao selecoes[], int posicao){
    printf("Nome da selecao: |%s|\n", selecoes[posicao].pais);
    printf("Grupo: %c\n", selecoes[posicao].grupo);
    printf("Quantidade de:\n");
    printf("- Jogos: %d\n", selecoes[posicao].jogos);
    printf("- Vitorias: %d\n", selecoes[posicao].vitorias);
    printf("- Empates: %d\n", selecoes[posicao].empates);
    printf("- Derrotas: %d\n", selecoes[posicao].derrotas);
    printf("- Gols marcados: %d\n", selecoes[posicao].gols_marcados);
    printf("- Gols sofridos: %d\n", selecoes[posicao].gols_sofridos);
}

void buscarSelecao(Selecao selecoes[], int ultimo){

    char busca[50];
    printf("\nqual selecao quer procurar? ");
    getchar();
    fgets(busca, 50, stdin);
    busca[strlen(busca)-1] = '\0';

    for(int i=0; i<ultimo; i++){
        if(strcmp(selecoes[i].pais, busca)==0){
            listarSelecoes(ultimo, selecoes, 1, i);
            return;
        }
    }
    printf("\nSelecao nao encontrada!\n");
}

void calcularClassificacao(Selecao selecoes[],int ultimo){
    int **classificacao_vetor;

    classificacao_vetor = malloc(2*sizeof(int *));

    classificacao_vetor[0] = malloc(ultimo * sizeof(int));
    classificacao_vetor[1] = malloc(ultimo * sizeof(int));

    int pont_vitorias = (selecoes[0].vitorias)*3;
    int pont_empates = selecoes[0].empates;
    classificacao_vetor[0][0] = pont_vitorias+pont_empates;
    classificacao_vetor[1][0]=0;

    if(ultimo>0){
        for(int i=1; i<ultimo; i++){
            pont_vitorias = (selecoes[i].vitorias)*3;
            pont_empates = selecoes[i].empates;
            classificacao_vetor[0][i] = pont_vitorias+pont_empates;
            classificacao_vetor[1][i]=i;
        }

        ordenacao(classificacao_vetor, ultimo);
    }

    printf("\n");
    impressao_ranking(ultimo, classificacao_vetor, selecoes);
    printf("\n");
}

void ordenacao(int **classificacao_vetor, int tamanho){
    int ordena[2];

    for(int i=0; i<tamanho; i++){
        for(int j=i+1; j<tamanho; j++){
            if(classificacao_vetor[0][j]>classificacao_vetor[0][i]){
                ordena[0]=classificacao_vetor[0][j];
                ordena[1]=classificacao_vetor[1][j];

                classificacao_vetor[0][j]=classificacao_vetor[0][i];
                classificacao_vetor[1][j]=classificacao_vetor[1][i];

                classificacao_vetor[0][i]=ordena[0];
                classificacao_vetor[1][i]=ordena[1];
            }
        }
    }
}

void impressao_ranking(int tamanho, int **classificacao, Selecao selecoes[]){
    for(int i=0; i<tamanho; i++){
        int pontuacao = classificacao[0][i];
        int posicao = classificacao[1][i];

        char nome_pais[50];

        strcpy(nome_pais, selecoes[posicao].pais);

        printf("%dº - %s: %d Pontos\n", i+1, nome_pais, pontuacao);
    }
}

void criacao(){ //cria arquivo se nao existir
    FILE *arquivo = fopen("arquivo.txt", "a");

    if(arquivo==NULL){
        printf("Erro na criacao do arquivo!");
        exit(1); //encerra programa caso erro
    }
    fclose(arquivo);
}

void leitura(Selecao *selecoes, int *tamanho){
    FILE *arquivo = fopen("arquivo.txt", "r");
    
    /*
    exemplo de estrutura dos dados dentro do arquivo:
    Brasil;A;3;2;1;0;6;2(\n)
    Argentina;B;3;3;0;0;8;1(\n)
    */

    for(int i=0; i<100; i++){ //i<100 pois nao é possivel encaixar mais de 100 selecoes dentro da estrutura
        int pv=1;
        do{
            switch(pv){
                case 1:
                    //verificando se ja acabou arquivo
                    char string_pais[50];

                    int c=fgetc(arquivo);

                    if (c==EOF){
                        *tamanho = i;
                        fclose(arquivo);
                        return;
                    }
                    string_pais[0] = (char)c;

                    for(int j=1; j<50; j++){
                        string_pais[j] = (char)(fgetc(arquivo));
                        if(string_pais[j]==';'){
                            string_pais[j]='\0';
                            break;
                        }
                    }

                    strcpy(selecoes[i].pais, string_pais);
                    break;
                case 2:
                    char var = (char)(fgetc(arquivo));
                    selecoes[i].grupo = var;
                    fgetc(arquivo); //para "gastar" o ';', e no proximo case, já estar no numero
                    break;
                default:
                    char string_numero[16];
                    int numget;
                    for(int j=0; j<16; j++){
                        numget = fgetc(arquivo);

                        if(numget==';'||numget=='\n'||numget==EOF){
                            string_numero[j]='\0';
                            break;
                        }

                        string_numero[j] = (char)numget;
                    }

                    int numero = conversao(string_numero); //converte o char em int

                    guarda_info(selecoes, i, pv, numero);
                    break;
            }
            pv++;
        }while(pv<9);
        *tamanho = i;
    }
    fclose(arquivo);
}

int conversao(char texto[]){
    int tamanho = strlen(texto)-1;

    int mult = pot(10, tamanho);

    int numero=0;

    for(int i=0; texto[i]!='\0'; i++){
        numero+=(texto[i]-'0')*mult;
        mult/=10;
    }

    return numero;
}

int pot(int base, int expo){
    if(expo==0) return 1;

    return base * pot(base, expo-1);
}

void guarda_info(Selecao *selecoes, int i, int pv, int numero){
    switch (pv) {
        case 3: selecoes[i].jogos = numero; break;
        case 4: selecoes[i].vitorias = numero; break;
        case 5: selecoes[i].derrotas = numero; break;
        case 6: selecoes[i].empates = numero; break;
        case 7: selecoes[i].gols_marcados = numero; break;
        case 8: selecoes[i].gols_sofridos = numero; break;
    }
}

void limparTela() { //percebe qual sistema operacional está, e limpa a tela de acordo
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