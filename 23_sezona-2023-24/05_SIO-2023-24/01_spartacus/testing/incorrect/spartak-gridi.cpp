#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n,l;
int p[maxn];
int tots[maxn];
int totk[maxn];
int s[maxn];
int k[maxn];
int vis[maxn];
int cnt=1;
vector<int> ch[maxn];
vector<int> rt;
bool av[maxn];
void dfs(int u) {
    tots[u]=s[u];
    totk[u]=k[u];
    for(auto v:ch[u]) {
        dfs(v);
        tots[u]+=tots[v];
        totk[u]+=totk[v];
    }
}
bool greedy1(int u,int v) {
    return s[u]>s[v];
}
bool greedy2(int u,int v) {
    return k[u]<k[v];
}
bool greedy3(int u,int v) {
    return tots[u]>tots[v];
}
bool greedy4(int u,int v) {
    return totk[u]<totk[v];
}
bool greedy5(int u,int v) {
    return s[u]*k[v]>s[v]*k[u];
}
bool greedy6(int u,int v) {
    return 1ll*tots[u]*totk[v]>1ll*tots[v]*totk[u];
}
bool greedy7(int u,int v) {
    return 1ll*tots[u]*k[v]>1ll*tots[v]*k[u];
}
int solve(bool greedy(int,int)) {
    for(int i=1;i<=n;i++) av[i]=false;
    for(auto u:rt) av[u]=true;
    int ret=0;
    int cur=0;
    for(int i=1;i<=n;i++) {
        int u=-1;
        for(int v=1;v<=n;v++) {
            if(av[v]) {
                if(u==-1 || greedy(v,u)) u=v;
            }
        }
        if(u==-1) break;
        av[u]=false;
        if(cur+k[u]<=l) {
            cur+=k[u];
            ret+=s[u];
            for(auto w:ch[u]) {
                av[w]=true;
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l;
    for(int i=1;i<=n;i++) {
        cin>>p[i];
        ch[p[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>k[i];
    }
    for(int i=1;i<=n;i++) {
        int u=i;
        while(true) {
            if(vis[u]) break;
            vis[u]=i;
            if(p[u]==0) break;
            u=p[u];
        }
        if(p[u]==0 || vis[u]==i) {
            rt.push_back(u);
            if(p[u]!=0) {
                int v=u;
                v=p[v];
                while(v!=u) {
                    for(auto w:ch[v]) {
                        if(w!=u) ch[u].push_back(w);
                    }
                    ch[v].clear();
                    s[u]+=s[v];
                    k[u]+=k[v];
                    s[v]=k[v]=0;
                    v=p[v];
                }
            }
            dfs(u);
        }
    }
    int ans=0;
    ans=max(ans,solve(greedy1));
    ans=max(ans,solve(greedy2));
    ans=max(ans,solve(greedy3));
    ans=max(ans,solve(greedy4));
    ans=max(ans,solve(greedy5));
    ans=max(ans,solve(greedy6));
    ans=max(ans,solve(greedy7));
    cout<<ans<<endl;
    return 0;
}
