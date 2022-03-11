#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
void troca(int *px ,int *py){
int temp=*px;
*px=*py;
*py=temp;
}

int mdc1 (int a, int b){
    int i,divisor;//maior divisor do menor, que tambem é divisor do maior
    //calcular o menos de dois valores
    //assergutamos que o maior valor fica na variavel a
    if(a<b) troca (&a ,&b);
    //calcular os divisoes do menor(variavel b) , selecionar maior desses divisores que
    //seja tambem divisor do maior deles(variavel a)

    i=2; //valor inicial
    while(i<=b){
        if((b%i==0) && (a%i==0) )
            divisor = i;//encontramos um divisor comum



        i++; //incremento
    }

return divisor;
}