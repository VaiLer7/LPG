#include <stdio.h>
//Escreva uma função que calcula o somatório dos n termos que são múltiplos de k a partir de x. Os parâmetros são determinados pelo usuário e a função é chamada pelo programa principal, que em seguida mostra o resultado na tela. Exemplo: para n = 3, k = 4 e x = 18, temos, 20 + 24 + 28 = 72. Protótipo da função:
//int soma_especial(int n, int k, int x);
int soma_especial(int qtdd, int mult, int comeco){
    int soma=0;
    comeco--;
    for(int i=0; i<qtdd; i++){
        do{
            comeco++;
        }while(comeco%mult!=0);
        soma+=comeco;
    }
    return soma;
}

int main(){
    int comeco, qtdd, mult;

    printf("digite quantos termos vai ter: ");
    scanf("%d", &qtdd);
    printf("digite de qual numero tera de ser multiplo: ");
    scanf("%d", &mult);
    printf("digite de que numero vai comecar: ");
    scanf("%d", &comeco);

    int soma = soma_especial(qtdd, mult, comeco);
    printf("valor final: %d", soma);
    getchar();
    getchar();
    // comeco--;
    // for(int i=0; i<qtdd; i++){
    //     do{
    //         comeco++;
    //     }while(comeco%mult!=0);
    //     soma+=comeco;
    // }
    
}