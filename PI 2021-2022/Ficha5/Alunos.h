//
// Created by migue on 31/03/2022.
//
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a);

void ordenaPorNum (Aluno t [], int N);
int procuraNum (int num, Aluno t[], int N);

void criaIndPorNum (Aluno t [], int N, int ind[]);
int procuraNumInd (int num, int ind[], Aluno t[], int N);

void criaIndPorNome (Aluno t [], int N, int ind[]);

void imprimeTurmaInd (int ind[], Aluno t[], int N);

void dumpV (int v[], int N);

void imprimeAluno (Aluno *a);

