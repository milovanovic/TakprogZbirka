#include <bits/stdc++.h>
#define MAXN 200007
#define MAXL 19
using namespace std;
int d[MAXN], lca[MAXN][MAXL];
int md;
void addChild(int u,int v) {
    d[v] = d[u] + 1;
    md=max(md,d[v]);
    lca[v][0] = u;
    for(int i = 1; i < MAXL; i++) lca[v][i] = lca[lca[v][i - 1]][i - 1];
}
int findLca(int u, int v) {
    if(d[u] > d[v]) swap(u, v);
    int k = MAXL-1;
    while(k>=0) {
        if((d[v]-d[u])&(1<<k)) v = lca[v][k];
        k--;
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
int cnt=0,mp=0;
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
            int cur=0;
            for(auto pr:g[u]) {
                int v=pr.first;
                int w=pr.second;
                if(dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    pq.push({-dist[v],v});
                }
                if(dist[u]==dist[v]+w) {
                    cnt++;
                    cur++;
                    if(par==-1) par=v;
                    else par=findLca(par,v);
                }
            }
            if(u!=1) addChild(par,u);
            mp=max(mp,cur);
        }
    }
}
void Putevi(int N, int M, int Q, int* U, int* V, int* W, int* X, int* Y, int* Ans)
{
    cnt = mp = md = 0;
    for(int i=1;i<=N;i++) {
        vis[i]=false;
        g[i].clear();
    }
    for(int i=1;i<=M;i++) {
        g[U[i]].push_back({V[i],W[i]});
        g[V[i]].push_back({U[i],W[i]});
    }
    dijkstra(N);
    fprintf(stderr,"max_depth = %d, dag_edges = %d, max_in_edges = %d\n",md, cnt, mp);
    for(int i=1;i<=N;i++) assert(vis[i]);
    for(int i=1;i<=Q;i++) Ans[i] = d[findLca(X[i],Y[i])] + 1;
}
char ins[50];
char ous[50];
int main()
{
    int testcases=104;
    for(int tc=1;tc<=testcases;tc++)
    {
        sprintf(ins,"testcases/%d.in",tc);
        sprintf(ous,"testcases/%d.out",tc);
        fprintf(stderr,"Solving from \"%s\" into file: \"%s\"\n",ins,ous);
        FILE* inf = freopen(ins,"r",stdin);
        FILE* ouf = freopen(ous,"w",stdout);
        int N, M, Q;
        fscanf(inf,"%d %d %d",&N,&M,&Q);
        int* U = new int[M+1];
        int* V = new int[M+1];
        int* W = new int[M+1];
        int* X = new int[Q+1];
        int* Y = new int[Q+1];
        int* Ans = new int[Q+1];

        for (int i=1; i<=M; i++) fscanf(inf,"%d %d %d",&U[i],&V[i],&W[i]);
        for (int i=1; i<=Q; i++) fscanf(inf,"%d %d",&X[i],&Y[i]);

        Putevi(N, M, Q, U, V, W, X, Y, Ans);

        for(int i=1;i<=Q;i++) fprintf(ouf, "%d\n", Ans[i]);

        delete[] U;
        delete[] V;
        delete[] W;
        delete[] X;
        delete[] Y;
        delete[] Ans;
    }
}
