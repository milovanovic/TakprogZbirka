#include <bits/stdc++.h>
#define maxn 1005
#define maxt 700000
#define maxc 27
using namespace std;
int n,q;
int mp[maxn][maxn];
int par[maxt];
bool pc[maxt];
int h[maxt];
inline int get_par(int x) {
    if(par[x]==x) return x;
    par[x]=get_par(par[x]);
    return par[x];
}
inline void merge(int x,int y) {
    x=get_par(x);
    y=get_par(y);
    if(x==y) return;
    if(h[x]<h[y]) {
        par[x]=y;
        pc[y]|=pc[x];
    }
    else {
        if(h[y]<h[x]) {
            par[y]=x;
            pc[x]|=pc[y];
        }
        else {
            par[y]=x;
            pc[x]|=pc[y];
            h[x]++;
        }
    }
}
int cnt=0;
bool col[maxc][maxn];
int incomp[maxc][maxn];
vector<int> comps[maxc][maxn];
bool nbp[maxc][maxn];
vector<pair<int,int> > relevant[maxc];
inline bool path(int u,int v) {
    return pc[get_par(mp[u][v])];
}
int tot[maxc];
inline void add_edge(int u,int v,int c) {
    pc[get_par(mp[u][v])]=true;
    bool ok=false;
    int cu=incomp[c][u];
    int cv=incomp[c][v];
    if(cu!=cv) {
        ok=true;
        int x;
        if(col[c][u]!=col[c][v]) x=0;
        else x=1;
        if(comps[c][cv].size()<comps[c][cu].size()) swap(cu,cv);
        for(auto w:comps[c][cu]) {
            incomp[c][w]=cv;
            comps[c][cv].push_back(w);
            tot[c]++;
            col[c][w]^=x;
        }
        nbp[c][cv]|=nbp[c][cu];
    }
    else {
        if(col[c][u]==col[c][v]) {
            if(!nbp[c][cu]) ok=true;
            nbp[c][cu]=true;
        }
    }
    if(ok) {
        for(auto pr:relevant[c]) {
            int x=pr.first;
            int y=pr.second;
            merge(mp[x][u],mp[y][v]);
            merge(mp[x][v],mp[y][u]);
        }
        relevant[c].push_back({u,v});
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>q;
    for(int u=1;u<=n;u++) {
        for(int v=u;v<=n;v++) {
            par[cnt]=cnt;
            if(u==v) pc[cnt]=true;
            mp[u][v]=cnt++;
            mp[v][u]=mp[u][v];
        }
        for(int j=0;j<26;j++) {
            incomp[j][u]=u;
            comps[j][u].push_back(u);
        }
    }
    for(int i=0;i<q;i++) {
        int t;
        cin>>t;
        if(t==1) {
            int u,v;
            char c;
            cin>>u>>v>>c;
            add_edge(u,v,c-'a');
        }
        else {
            int u,v;
            cin>>u>>v;
            if(path(u,v)) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
