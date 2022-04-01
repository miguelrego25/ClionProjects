//
// Created by migue on 31/03/2022.
//

#include "Alunos.h"
#include <stdio.h>


float calculanotafinal(){

}
float calculNotaMinT(int miniT[],int N){
    float res =0.0;
    int soma =0, i;
    for (i = 0; i<N ; i++) {
        soma += miniT[i];
    }
    res = ((soma*1.0)/N)*10; //nota de 0.0  a 20.0
    return res;
}

int nota (Aluno a) {
    int res = 0;
    float notaMiniT = calculNotaMinT(a.miniT, 6.0);
    if (a.teste < 8.00 || notaMiniT < 8.0) {
        res = 0;
    } else {
        res = 0.25 * notaMiniT + 0.75 * a.teste;
        if (res < 10) return 0;
        return res;
    }
}
int procuraNum (int num, Aluno t[], int N){
    int res = -1;
    for (int i = 0; t[i].numero!=num || i<N; i++) if (t->numero == num) res = i;

    if (num == -1) return -1;
    else{return num;}
}
int procuraNumBin (int num, Aluno t[], int N){
    int inf = 0, sup =N-1, meio;
    while (inf<=sup) {
        meio = (inf + sup) / 2;
        if (t[meio].numero == num) return meio;
        if (t[meio].numero < num) inf = meio + 1;
        if (t[meio].numero > num) sup = meio - 1;
    }
}
void swapAluno(Aluno t[],int i, int j){
    Aluno temp;
    temp = t[i];
    t[i]=t[j];
    t[j]=temp;
}
int ordenaPorNumero(Aluno t[],int N){
    int i,j;
    for(i=0;i<N;i++){
        for (j = 0; j < N; j++) {
            if(t[i].numero>t[j].numero) swapAluno(t,i,j);
        }
    }
}
void swapInt(int ind[], int i, int j){
    int temp = ind[i];
    ind[i]=ind[j];
    ind[j]=temp;
}
void ordenaIndPorNum(Aluno t[],N,ind[]){
    int i, j;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(t[ind[i]].numero > t[ind[j]].numero)
                swapInt(ind,i,j);//swapAluno(t,i,j);
        }
    }
}
void criaIndPorNum (Aluno t [], int N, int ind[]){
    //1º criar o indice identidade..
    int i ;
    for (int i = 0; i < N; i++) ind[i] = i;
    ordenaIndPorNum(t,N,ind);
}
int procuraNumInd (int num, int ind[], Aluno t[], int N){

}

void criaIndPorNome (Aluno t [], int N, int ind[]);



