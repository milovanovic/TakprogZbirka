#include<bits/stdc++.h>
#define maxn 400000
using namespace std;
int n;
vector<pair<int,char> > a[maxn];
long long ans;
bool centr[maxn];
bool vis[maxn];
int ch[maxn];
vector<int> nodes;
mt19937 rng(time(NULL));
int sz=0;
map<pair<int,pair<int,int> >,int> m;
void dfs(int u) {
    vis[u]=true;
    ch[u]=1;
    sz++;
    for(int i=0;i<a[u].size();i++) {
        int v=a[u][i].first;
        if(!vis[v] && !centr[v]) {
            dfs(v);
            ch[u]+=ch[v];
        }
    }
    vis[u]=false;
}
int find_centr(int u,int p) {
    for(auto tp:a[u]) {
        int v=tp.first;
        if(!centr[v] && v!=p && ch[v]>(sz+1)/2) return find_centr(v,u);
    }
    return u;
}
vector<pair<int,pair<int,int> > > buf;
void solve_dfs(int u,pair<int,pair<int,int> > cx) {
    vis[u]=true;
    int mv=min(cx.first,min(cx.second.first,cx.second.second));
    int mx=max(cx.first,max(cx.second.first,cx.second.second));
    buf.push_back({cx.first-mv,{cx.second.first-mv,cx.second.second-mv}});
    pair<int,pair<int,int> > ppi = {mx-cx.first,{mx-cx.second.first,mx-cx.second.second}};
    ans+=m[ppi];
    for(int i=0;i<a[u].size();i++) {
        int v=a[u][i].first;
        if(!centr[v] && !vis[v]) {
            if(a[u][i].second=='S') solve_dfs(v,{cx.first+1,{cx.second.first,cx.second.second}});
            if(a[u][i].second=='I') solve_dfs(v,{cx.first,{cx.second.first+1,cx.second.second}});
            if(a[u][i].second=='O') solve_dfs(v,{cx.first,{cx.second.first,cx.second.second+1}});
        }
    }
    vis[u]=false;
}
void solve(int u) {
    m[{0,{0,0}}]=1;
    for(int i=0;i<a[u].size();i++) {
        int v=a[u][i].first;
        pair<int,pair<int,int> > cx;
        if(a[u][i].second=='S') cx={1,{0,0}};
        if(a[u][i].second=='I') cx={0,{1,0}};
        if(a[u][i].second=='O') cx={0,{0,1}};
        if(!centr[v]) {
            solve_dfs(v,cx);
            for(auto ppi:buf) m[ppi]+=1;
            buf.clear();
        }
    }
    m.clear();
}
void creat_centr(int u) {
    dfs(u);
    int cent=find_centr(u,-1);
    sz=0;
    centr[cent]=true;
    solve(cent);
    for(auto ne:a[cent]) {
        int v=ne.first;
        if(!centr[v]) creat_centr(v);
    }
}
int main() {
    int u,v,c[2];
    scanf("%d",&n);
    for(int i=0;i<n-1;i++) {
        scanf("%d %d %s",&u,&v,c);
        a[u].push_back({v,c[0]});
        a[v].push_back({u,c[0]});
    }
    creat_centr(1);
    printf("%lld",ans);
    return 0;
}
