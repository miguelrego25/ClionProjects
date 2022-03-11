#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras, Celula;

void libertaLista (Palavras l);
int quantasP (Palavras l);
void listaPal (Palavras l);
char * ultima (Palavras l);
Palavras acrescentaInicio (Palavras l, char *p);
Palavras acrescentaFim (Palavras l, char *p);
Palavras acrescenta (Palavras l, char *p);
struct celula * maisFreq (Palavras l);

void libertaLista (Palavras l) {
    Palavras aux;
    if(l!=NULL){
        aux = l;
        l=l->prox;
    }
    free(aux);
}
void libertaLista2 (Palavras l) {
    if(l){
        libertaLista2(l->prox);
        free(l);

    }
}
int quantasP (Palavras l){
    int counter=0;
    while(l!=NULL){
        counter++;
        l=l->prox;
    }
    return counter;
}
int quantasP2 (Palavras l){
    int counter;
    if(l){
        l=l->prox;
        counter=counter;
        quantasP2(l);
    }
    return counter;
}
void listaPal (Palavras l){
    while(l!=NULL){
        printf("%s :: %d\n",l->palavra, l->ocorr);
        l=l->prox;
    }
}
char * ultima (Palavras l){
    while(l!=NULL && l->prox != NULL){
        l=l->prox;
    }
    if(l) return l->palavra;
    else{return NULL;}
}
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras aux = malloc(sizeof(Celula));

    aux->palavra = strdup(p);
    aux->prox = l;
    aux->ocorr = 1;
    return aux;
}
Palavras acrescentaFim (Palavras l, char *p){
    Palavras aux2=l, aux=malloc(sizeof (Celula));
    aux->palavra = strdup(p);
    aux->prox = NULL;
    aux->ocorr = 1;
    while(l!=NULL && l->prox != NULL){
        l=l->prox;
    }
    if(l) {
        l->prox = aux;
        return aux2;
    }
    else return aux;
}
Palavras acrescenta (Palavras l, char *p) {
    if (l == NULL) l = acrescentaFim(l, p);
    else {
        Palavras last = l;
        for (; last != NULL; last = last->prox) {
            if (last->palavra == p) {
                last->ocorr++;
                return l;
            }
        }
        l = acrescentaFim(l, p);
    }
    return l;
}

struct celula * maisFreq (Palavras l){
    Palavras aux = malloc(sizeof(Celula));
    aux->ocorr=0;
    aux->prox=NULL;
    aux->palavra=NULL;
    if(l!=NULL){
        while(l!=NULL){
            l=l->prox;
            if(l->ocorr > l->prox->ocorr) {
                aux=l;
            }
        }
        return aux;
    }
    else{

    }
}


int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana",
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram",
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    //dic = NULL;

    //srand(42);

   // for (i=0; i<1000; i++)
   //     dic = acrescenta (dic, canto1 [rand() % 44]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    //p = maisFreq (dic);
    //printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);

    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}
