
#include <stdlib.h>
#include <stdio.h>


typedef struct lista{
    int valor;
    struct lista *prox;
}*Lista;

Lista newLista(int x, Lista l){
    Lista r;
    r=malloc (sizeof(struct lista));
    r->valor = x;
    r->prox = l;
    return r;
}
Lista fromArray(int v[], int N){
    //constroi uma lista com os N elementos de v
    Lista r = NULL;
    if(N>0) r = newLista(v[0],fromArray (v+1, N-1));

    return r;
}

int procura (Lista *l, int x){
    Lista aux = (*l) ,prev = NULL;
    Lista new = malloc(sizeof(struct lista));
    new->valor= x;
    new->prox= NULL;
    while(aux && aux->valor!=x){
        prev = aux;
        aux = aux->prox;
    }
    if(aux==NULL){
        return 0;
    }
    if(aux->valor = x){
        prev->prox = aux->prox;
        free(prev);
        new->prox = (*l);
        return 1;
    }
}

void insertOrd (Lista *l, int x) {
    Lista ant = NULL;
    Lista atual = (*l);
    Lista aux = malloc(sizeof(struct lista));
    aux->valor = x;
    aux->prox = NULL;

    if (atual == NULL)atual = aux;

    while (atual->valor < aux->valor && atual != NULL) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) atual = aux;
    else {

        aux->prox = atual;
        ant->prox = aux;
    }
}
    int removeOneOrd (Lista *l, int x) {
        Lista ant;
        Lista pro;
        Lista atual = (*l);
        Lista aux = NULL;

        if (atual->valor > x) {
            aux = atual;
            atual = atual->prox;
            free(aux);
        } else {
            while (atual->valor != x && atual) {
                ant = atual;
                atual = atual->prox;
            }
            if (atual->valor == x) {
                aux = atual;
                ant->prox = atual->prox;
                free(aux);
            }
            if (atual == NULL) {
                return 1;
            }
        }
        return 0;
    }

    void adicionar (Lista *l, int x){
        Lista current = *l;

        while(current!=NULL){
            current = current->prox;
        }


        current->valor = x;
        current->prox = NULL;
    }

    Lista cloneL (Lista l){
        Lista a = malloc(sizeof(Lista));
        a->valor = l->valor;
        a->prox = NULL;
        l = l->prox;

        while(l != NULL){
            adicionar(&a, (l->valor));
            l = l->prox;
        }

        return a;
    }

int main(){
    Lista x,y,z;
    int i=0;
    int a[5] = {1,22,33,44,55};
    int b[5] = {2,3, 70 ,80 ,90};
    x = fromArray (a,5);
    y = fromArray (b,5);
    //insertOrd(x,43);
    //y=removeOneOrd(&x,39);
    //merge(&z,x,y);

    //y = cloneL (x);
    //procura(&a,44);
    //return y;


}