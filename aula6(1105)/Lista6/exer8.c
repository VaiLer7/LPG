#include <stdio.h>
#include <string.h>

int potencia(int, int);
int conversao(char[]);

int SomenteNum(char[]);
int Barras(char[], int*, int*, int*);

void Erro(int res);

int main(){
    char data[11];
    int Dia, Mes, Ano, res;

    printf("digite a data atual(no formato 'DD/MM/AAAA'): ");
    for(;;){
        scanf("%s", data);

        res = Barras(data, &Dia, &Mes, &Ano);
        if(res==0) break;
        Erro(res);
    }

    printf("\nData: %d/%d/%d", Dia, Mes, Ano);

    getchar();
    getchar();
}

int Barras(char texto[], int *Dia, int *Mes, int *Ano){
    char DD[3], MM[3], AAAA[5];
    int i;

    for(i=0; texto[i]!='/' && i<11; i++){
        DD[i]=texto[i];
    }
    DD[i]='\0';
    if(i!=2 || !SomenteNum(DD)) return 1;

    for(i=0; texto[i+3]!='/' && i<8; i++){
        MM[i]=texto[i+3];
    }
    MM[i]='\0';
    if(i!=2 || !SomenteNum(MM)) return 2;

    for(i=0; texto[i+6]!='\0' && i<5; i++){
        AAAA[i]=texto[i+6];
    }
    AAAA[i]='\0';
    if(i!=4 || !SomenteNum(AAAA)) return 3;
    
    *Dia = conversao(DD);
    *Mes = conversao(MM);
    *Ano = conversao(AAAA);

    return 0;
}

void Erro(int res){
    char problema[4];

    switch (res){
    case 1:
        strcpy(problema, "dia");
        break;
    case 2:
        strcpy(problema, "mes");
        break;
    case 3:
        strcpy(problema, "ano");
        break;
    
    default:
        break;
    }
    printf("Problema na formatacao do %s\nDigite a data novamente: ", problema);
}

int SomenteNum(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]<'0' || str[i]>'9') return 0;
    }
    return 1;
}

int potencia(int base, int expo){
    if(expo==0) return 1;

    return base * potencia(base, expo-1);
}

int conversao(char stringue[]){
    int valor=0;
    int tamanho = potencia(10, strlen(stringue)-1);
    for(int i=0; stringue[i]!='\0'; i++){
        valor+=(stringue[i]-'0')*tamanho;
        tamanho=(tamanho/10);
    }
    return valor;
}