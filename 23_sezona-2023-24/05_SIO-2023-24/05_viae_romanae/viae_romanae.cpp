#include <bits/stdc++.h>
#define MAXN 200007
#define MAXL 18
using namespace std;
int d[MAXN], lca[MAXN][MAXL];
void addChild(int u,int v) {
    d[v] = d[u] + 1;
    lca[v][0] = u;
    for(int i = 1; i < MAXL; i++) lca[v][i] = lca[lca[v][i - 1]][i - 1];
}
int findLca(int u, int v) {
    if(d[u] > d[v]) swap(u, v);
    int k = MAXL;
    while(k--) {
        if((d[v]-d[u])&(1<<k)) v = lca[v][k];
    }
    if(u==v) return u;
    k = MAXL - 1;
    while(lca[u][0]!=lca[v][0]) {
        if(lca[u][k]!=lca[v][k]) {
            u = lca[u][k];
            v = lca[v][k];
        }
        k--;
    }
    return lca[u][0];
}
vector<pair<int,int> > g[MAXN];
long long dist[MAXN];
bool vis[MAXN];
priority_queue<pair<long long,int> > pq;
void dijkstra(int n) {
    for(int i=2;i<=n;i++)  dist[i]=1e18;
    pq.push({-dist[1],1});
    while(!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        if(!vis[u]) {
            vis[u]=true;
            int par=-1;
            for(auto pr:g[u]) {
                int v=pr.first;
                int w=pr.second;
                if(dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    pq.push({-dist[v],v});
                }
                if(dist[u]==dist[v]+w) {
                    if(par==-1) par=v;
                    else par=findLca(par,v);
                }
            }
            if(u!=1) addChild(par,u);
        }
    }
}
void Putevi(int N, int M, int Q, int* U, int* V, int* W, int* X, int* Y, int* Ans)
{
    for(int i=1;i<=M;i++) {
        g[U[i]].push_back({V[i],W[i]});
        g[V[i]].push_back({U[i],W[i]});
    }
    dijkstra(N);
    for(int i=1;i<=Q;i++) Ans[i] = d[findLca(X[i],Y[i])] + 1;
}
