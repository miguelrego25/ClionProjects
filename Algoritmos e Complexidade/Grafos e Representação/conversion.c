

#include "graphs.h"



int readGraphM(GraphM g) {
    for(int i=0; i<MAX;i++)
        for(int j=0; j<MAX;i++)
            malloc(sizeof(e))
    return readGraphM_sol(g);
}



void printGraphM(GraphM g, int n) {
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d",g[i][j]);
        printf("\n");
    }
    //printGraphM_sol(g, n);
}



void printGraphL(GraphL g, int n) {
    int i,j;
    struct edge *p;

    for(i=0;i<n;i++){
        printf("%d",i);
        for(p=g[i];p;p=p->next)
            printf(" -->(%d,%d)",p->dest,p->weight);
        printf("\n");
    }
    //printGraphL_sol(g, n);
}



void graphLtoM(GraphM gm, GraphL gl, int n) {
    int i, j;
    struct edge *p;

    for(i=0, i<n;i++){
        for(j=0, p=gl[i];j<n;j++)
            if (p && p->dest == j){
                gm[i][j] = p->weight;
                p=p->next;
            }
            else{
                gm[i][j] = NE;
            }
    }
    //graphLtoM_sol(gm, gl, n);
}



void graphMtoL(GraphL gl, GraphM gm, int n) {
    int i,j;
    struct edge *head, *new;

    for(i=0;i<n;i++){
        head=NULL;
        for(j=n-1;j>=0;j--)
            if(gm[i][j] != NE ){
                new = malloc(sizeof(struct edge));
                new->dest =j;
                new->weight = gm[i][j];
                new->next = head;
                head=new;
            }
        gl[i] = head;

    }
}


//graphMtoL_sol(gl, gm, n);
}



int inDegree (GraphL g, int j, int n) {
    return inDegree_sol(g, j, n);
}



int outDegree (GraphL g, int j) {
    return outDegree_sol(g, j);
}


int capacidadeL (GraphL g, int v, int n) {
    return  capacidadeL_sol (g, v, n);
}

int maxCap (GraphL g, int n) {
    return maxCap_sol (g, n);
}


