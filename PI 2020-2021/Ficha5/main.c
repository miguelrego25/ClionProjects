#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    float s=0;
    int i;
    for (i=0;i<6;i++){
        s+=a.miniT[i]*10;
    }
    if (s/6<8||a.teste<8) return 0;
    else{
        s=(s/6)*0.3+a.teste*0.7;
        return round(s);
    }

}
int procuraNum (int num, Aluno t[], int N){
    int i;
    for (i = 0; i < N && t[i].numero < num ; i++) {}
    if(t[i].numero == num) {
        return i;
    }
    else {return -1;}
}

void ordenaPorNum (Aluno t [], int N){
    Aluno temp;
    int b;
    int c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(t[j].numero > t[i].numero){
                temp=t[j];
                t[j]=t[i];
                t[i]=temp;
            }
        }
    }
}
void criaIndPorNum(Aluno t [], int N,int ind[]){
    int i;
    Aluno s[N];
    for(i=0;i<N;i++){
        s[i]=t[i];
    }
    ordenaPorNum(s,N);
    for (i=0;i<N;i++){
        ind[i]=procuraNum(s[i].numero,t,N);
    }
}
void imprimeTurma (int ind[], Aluno t[], int N){
    for (int i = 0; i < N; i++) {
        ind[]
    }
}
int main() {

}
