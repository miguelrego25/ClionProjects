#include <stdio.h>
//#include <assert.h>

//Defina um programa que le (usando a funcao scanf uma sequencia
// de numeros inteiros terminada com o
// numero 0 e imprime no ecran o maior elemento da sequencia.
//1
void elem () {
    int bigger=0;
    int scand = 1;
    while(scand != 0){
        scanf("%d", &scand);
        if (scand>bigger) bigger = scand;

    }
    printf("%d", bigger);
}

//Defina um programa que le (usando a funcao scanf uma sequencia de numeros
// inteiros terminada com o numero 0 e imprime no ecran a
// media da sequencia
//2
void average(){
    int cont=0;
    float scand=1;
    float sum=0;
    while(scand != 0){
        scanf("%f", &scand);
        if (scand!=0) cont++;
        sum = sum + scand;
    }
    sum = sum/cont;
    printf("%f", sum);
}

// Defina um programa que le (usando a funcao scanf uma
// sequencia de numeros inteiros terminada com o numero 0 e
// imprime no ecran o segundo maior elemento.
//3
void scdbigger(){
    int biggest=0;
    int second=0;
    int scand=1;
    while(scand!=0){
        scanf("%d", &scand);
        if (scand>biggest) biggest = scand;
        if (scand<biggest && scand>second) second = scand;
    }
    printf("%d", second);
}

//Defina uma funcao int bitsUm (unsigned int n) que calcula o numero de bits
// iguais a 1 usados na representacao binaria de um dado numero n.
//4
int bitsUm (unsigned int x){
    int r=0;

    while (x>0){
        if(x%2!=0) r = r + 1;
        x=x/2;
    }

    return r;
}

//Defina uma funcao int trailingZ (unsigned int n) que calcula
// o numero de bits a 0 no final da representacao binaria de
// um numero (i.e. o expoente da maior potencia de 2 que e
//divisor desse numero)
//5
int trailingZ (unsigned int n) {
    int bigst=0;
    int count=1;
    while(n>1){
        if(n%2==0) bigst = count;
        n=n/2;
        count++;
    }
    if(n==0) bigst = 32;
    return bigst;
}

//Defina uma funcao int qDig (unsigned int n) que calcula o
// numero de dıgitos necessarios para escrever o inteiro n
// em base decimal. Por exemplo, qDig (440) deve retornar 3.
//6
int qDig (int n) {
    int r = 0;

    return r;
}


int main() {
//elem(); //1
//average(); //2
//scdbigger(); //3
//bitsUm(n); //4
trailingZ(0);
return 0;
}

