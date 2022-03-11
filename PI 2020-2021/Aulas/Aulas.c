#include <stdlib.h>
#include <stdio.h>

/*
typedef struct lista{
    int valor;
    struct lista *cauda;
}*Lista;

int main(){
    Lista x,y;

    //x=[]
    x=NULL;

    //y = [42]
    (*y).valor= 42;
    (*y).cauda = NULL;

    x = malloc (10*sizeof(int));

}
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

Lista cloneL (Lista l){
    Lista r ,cauda;

    if(l==NULL) r = NULL;
    else{cauda = cloneL (l->prox);
    r = newLista (l->valor,cauda);
    }


    return r;
  }
int main(){
    Lista x,y;
     int a[5] = {1,22,33,44,55};
     x = fromArray (a,5);
     y= cloneL(x);

     return 0;
}
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

/*
Lista cloneL(Lista l){
    Lista r, ult,nova;

    if(l==NULL) r = NULL;
    else{
      r = malloc(sizeof(struct lista));
      r->valor = l->valor;
      ult=r;
      l = l->prox;

        while(l!=NULL){
        nova=malloc(sizeof(struct lista));
        nova->valor = l->valor;
        ult->prox = nova;
        ult = nova;
        l = l->prox;
        }
      ult->prox=NULL;
    }
    return r;
  }
*/
/*
Lista cloneL(Lista l){
    Lista r, ult, *sitio;

    sitio = & r;



    while(l!=NULL){
      *sitio = malloc(sizeof(struct lista));
      (*sitio)->valor=l->valor;
      l=l->prox;
      sitio = &((*sitio)->prox);
    }
    *sitio = NULL;

    return r;
  }

Lista insereOrd(Lista l, int x){
    // l esta ordenada

    Lista nova,*sitio;


    //criar celula para o novo elemento
    nova=malloc(sizeof(struct lista));
    nova->valor=x;

    sitio = &l;

    //percorre a lista ate encontrar um elemento maior do que x

    while(*sitio!=NULL && (*sitio)->valor < x){
        sitio =&((*sitio)->prox);

    }
    //inserir a celula nesse sitio da lista
    nova->prox = *sitio;
    *sitio=nova;

    return l;
}

int removeOrd(Lista l, int x){
    Lista pt, ant;
    //procurar x em l
    pt=l;


    //percorrer lista ate encontrar;
    while(pt!=NULL&& pt->valor<x){
        ant=pt;pt=pt->prox;
    }
    if(pt!=NULL && pt ->valor ==x){
        if(pt!=l)ant->prox = pt->prox;
        else l=l->prox;
        free(pt);
    }
    else{
        //nao existe
    }

    return l;
}

int main(){
    Lista x,y;
    int a[5] = {10,20,30,40,50};
    Lista l = x = fromArray (a,4);
    //y = cloneL(x);
    l = removeOrd(l,30);


    return 0;
}
 */

typedef struct arvore {
    int valor;
    struct arvore *esq, *dir;
} *Arv;

