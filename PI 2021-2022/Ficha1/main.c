#include <stdio.h>

void quadrado(int numero){
    for (int i = 0; i < numero; ++i) {
        for (int j = 0; j < numero; ++j) {
            printf("#");
        }
        printf("\n");
    }
}

void xadrez (int numero){
    for (int i = 0; i < numero; ++i) {
        for (int j = 0; j < numero; ++j) {
            if((j+i)%2 == 0 ){
                printf("#");
            }
            else{
                printf("_");
            }
        }
        printf("\n");
    }
}

void triangulo(int numero){
    for (int i = 0; i<numero; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("#");
        }

        printf("\n");
    }
    for (int i=numero; i>0 ; i--) {
        for (int j=numero; j > 0; j--) {
            printf("#");
        }
        numero = numero-1;
        printf("\n");
    }
}

traingulo(int numero){
    numero++;
    int espacos=numero;
    int simbolos=0;

    //fazer o numero de linhas
    for (int i = 0; i < numero; i++) {

        for (int j = 0; j < espacos; ++j) {
            putchar(' ');
        }
        espacos--;

        for (int j = 0 ; j< (simbolos*2)-1;j++) {
            putchar('#');
        }
        simbolos++;
        printf("\n");
    }
}















int main() {
    quadrado (5);
    xadrez (5);
    triangulo(5);
    traingulo(5);
    return 0;
}
