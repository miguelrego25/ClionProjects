#include <stdio.h>
#include <malloc.h>
Lista fromArray
Lista cloneL(Lista l){
    Lista r;
    if (l==NULL) r = NULL;
    else r =newLista(l->valor, cloneL (l->prox));
    return r;
}

Lista cloneL (Lista l) {
    Lista r, ult, *sitio;

    sitio = &r;

    while (l != NULL) {
        *sitio = malloc(sizeof(struct lista));
        (*sitio)->valor = l->valor;
        l = l->prox;
        sitio = &((*sitio)->prox);
    }
    *sitio = NULL;

    return r;
}

Lista insereORd (List)
int main() {
    printf("Hello, World!\n");
    return 0;
}
