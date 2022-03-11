#include <stdio.h>
int primeira(){
    int maior = 0;
    while(1){
        int x;
        scanf("%d",&x);
        if(maior < x) maior = x;
        if(x==0) return printf("%d",maior);
    }

}
int  segunda(){
    int somadevalores = 0;
    int numerovalores = 0;
    int flag=1;
    while(flag){
        int x;
        scanf("%d",&x);
        if(x==0) {
            flag = 0;
        }else{
            numerovalores += 1;
            somadevalores += x;
        }
    }
    return somadevalores/numerovalores;
}

int terceira(){
    int maior = 0;
    int  segundomaior = 0;
    int  flag=1;
    while(flag) {
        int x;
        scanf("%d", &x);
        if (x == 0) flag = 0;
        if (x > maior) {
            segundomaior = maior;
            maior = x;
        }
        if (x < maior && x > segundomaior) segundomaior = x;
    }
    return segundomaior ;
}
//int bitsUm (unsigned int n)
int quarta(unsigned int n){

}
int main() {
    //primeira();
    //segunda();
    //terceira();

    return terceira();
}

