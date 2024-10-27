#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
int n,q;
vector<int> a[maxn];
int p[maxn];
int b[maxn];
int col[maxn];
int ans;
void dfs(int u) {
    for(auto v:a[u]) {
        if(v!=p[u]) {
            if(b[v]!=b[u]) ans++;
            p[v]=u;
            dfs(v);
        }
    }
}
void dfsc(int u,int c) {
    if(col[u]==c) {
        return;
    }
    col[u]=c;
    for(auto v:a[u]) {
        if(v!=p[u]) {
            if(b[v]!=b[u]) ans--;
            dfsc(v,c);
        }
    }
    b[u]=c;
}
int main() {
    scanf("%d %d",&n,&q);
    for(int i=0;i<n-1;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&b[i]);
    }
    dfs(1);
    for(int i=0;i<q;i++) {
        int u,c;
        scanf("%d %d",&u,&c);
        if(b[u]!=b[p[u]]) ans--;
        if(c!=b[p[u]]) ans++;
        dfsc(u,c);
        printf("%d\n",ans+1);
    }
    return 0;
}
