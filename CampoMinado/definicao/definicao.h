#ifndef definicao_h
#define definicao_h

void preenchimento(int tam, char[tam][tam], char);
void minas(int qtdd_bombas, int tam, char[tam][tam], int[qtdd_bombas][2]);
void numeracao(int, int, int tam, char[tam][tam]);
void cascata(int, int, int tam, char[tam][tam], char[tam][tam], int*, float*, int);
int qtdd_bandeiras(int, int, int tam, char[tam][tam]);
void chording(int, int, int tam, char[tam][tam], char[tam][tam], int*, float*);

#endif