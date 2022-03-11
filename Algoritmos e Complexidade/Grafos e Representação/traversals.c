
#include "graphs.h"

int color[MAX];


void df_visit(GraphL g, int s)
{
    df_visit_sol(g, s);

}


void dfs (GraphL g, int n)
{
    dfs_sol(g, n);

}





void bf_visit(GraphL g, int s)
{
    bf_visit_sol(g, s);

}


void bfs (GraphL g, int n)
{
    bfs_sol(g, n);

}


void dists (GraphL g, int s, int dist[])
{
    dists_sol (g, s, dist);
}


void shortestPath (GraphL g, int s, int  d)
{
    struct edge *p;
    intq[MAX], parent[MAX], first=0, last=0, u,v;
    char vis[MAX];

    for (int u = 0; u < MAX; ++u) {
        parent[u] = -1;
        vis[u] = 0;
    }

    while (first<last){
        u=q[first++];
        for (p = g[u];  p ; p=p->next) {
            v=p->dest;
            if (!vis[v]){

            }
        }
    }

    // shortestPath_sol (g, s, d);
}


