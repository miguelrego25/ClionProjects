

#include "graphs.h"



void printTree(GraphM g, int n, int parent[]) {
    printTree_sol(g, n, parent);


}


void mst(GraphL g, int n, int parent[]) {

    mst_sol(g, n, parent);
    return;


    // Apagar as duas linhas acima.... 

    int status[MAX];
    int fringeLink[MAX];
    int fringeWgt[MAX];
    struct edge *ptr;
    int x,y;
    int fringeList;
    int edgeCount;
    int stuck;
    int sum;

    /* inicializacao */

    x = 0;
    status[0] = INTREE;
    parent[0] = -1;

    stuck = 0;

    edgeCount = 0;

    fringeList = NIL;

    for (y = 1 ; y < n ; y++) status[y] = UNSEEN;

    while(edgeCount<n-1 && !stuck) {

        // ...

        edgeCount++;
    }
}