#include <stdio.h>

float pow(float num, int qtdd){
    if(qtdd==1) return num;

    return num * pow(num, qtdd-1);
}

double raizQuadrada(double numero) {
    if (numero < 0) {
        return -1; // erro para números negativos
    }

    if (numero == 0) {
        return 0;
    }

    double x = numero;
    double precisao = 0.000001;

    while ((x * x - numero > precisao) || (numero - x * x > precisao)) {
        x = (x + numero / x) / 2;
    }

    return x;
}

int root2g(float *x1, float *x2, int a, int b, int c){
    float delta;

    if(a!=0){
        delta = pow(b, 2) -4 * a * c;

        if(delta>=0){
            *x1 = (-b + raizQuadrada(delta))/(2*a);
            *x2 = (-b - raizQuadrada(delta))/(2*a);
            return 1;
        }else {
            printf("\nsem raízes reais");
            return 0;
        }
    }
    printf("\nvalor de a deve ser diferente de 0");
    return 0;
}

int main(){
    float r1=0, r2=0, a, b, c;

    printf("Digite o coeficiente a: ");
    scanf("%f", &a);
    printf("Digite o coeficiente b: ");
    scanf("%f", &b);
    printf("Digite o coeficiente c: ");
    scanf("%f", &c);

    if(root2g(&r1, &r2, a, b, c)){
        printf("\nx'=%.2f\nx''=%.2f\n", r1, r2);
    }
}