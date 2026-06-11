#ifndef visual_h
#define visual_h

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

#endif