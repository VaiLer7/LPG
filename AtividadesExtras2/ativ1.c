#include <stdio.h>

int main(){
    int numero = 10;
    printf("numero em si: %d\n", numero);
    printf("endereço do numero: %d\n", &numero);
    printf("ponteiro pro endereço do numero: %d\n", *&numero);

    //Basicamente: O endereço dá a localização de aonde aquele valor esta sendo guaradado.
    //Ja o ponteiro, é uma mecanica que pega o valor da localização que esta guardado apos o *
    //Um complementa o outro:
    //enquanto o & ve o endereço a partir do valor
    //o * ve o valor a partir do endereço

    //printf("endereço do numero: %d\n", *numero); 
    //nao faz sentido usar "*numero" pois o "numero" nao é um endereço

    int valor = 50;
    int *p = &valor;
    
    //Aqui o "p" esta sendo declarado como ponteiro, através do "*" antes dele
    //A "int" serve para indicar qual sera o tipo do valor sendo apontado:
    // - "valor" é inteiro, entao o ponteiro deve ser inteiro tambem
    //Depois tem a declaração de aonde deve apontar, que sempre deve ser um endereço:
    // - por isso o "&" antes do "valor", para resgatar o endereço de onde aquele valor esta sendo guardado

    //Se for pra pôr essa linha inteira numa frase, seria assim:
    //"crie um ponteiro "p" do tipo inteiro (int *p) e receba o endereço de "valor" (= &valor)" : int *p = &valor;

    //É importante mencionar que o "*" nesse caso tem função de declaração, ele nao esta fazendo nenhuma operação:
    // - basicamente ta dizendo "o "p" é um ponteiro"
    //entao é possivel fazer o seguinte:
    
    int a = 5;
    int *p;
    
    p = &a;

    //Pois o programa sabe que "p" é um ponteiro, devido a declaração do "int *p;"

    //o "*" tem duas funções e isso confunde:
    // - função de declaração, como no exemplo anterior
    // - função de desreferenciação:

    int a = 20;
    int *p = &a;

    int b = *p;

    //Nesse caso, o segundo "*" esta servindo como desreferenciação, que é basicamente pegar o valor dentro do endereço dado
    //O "p" é o endereço de "a", entao está pegando o valor do endereço de "a"
    //Se for seguir uma linha lógica seria:
    // - "o valor de "b" recebe a desreferenciação do ponteiro "p", que é igual ao endereço de "a", que possui o valor 20"


    getchar();
    getchar();
}