#include <bits/stdc++.h>
#include "testlib.h"
#define maxn 3000000
using namespace std;
int t,n,k;
int b[maxn];
vector<int> a[maxn];
bool vis[maxn];

int dfs(int u) {
    int c=1;
    vis[u]=true;
    for(auto v:a[u]) {
        if(!vis[v]) {
            c+=dfs(v);
        }
    }
    return c;
}

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    t = inf.readInt(1, 10, "t");
    inf.readEoln();

    while(t--) {

        n = inf.readInt(1, 5000, "n");
        inf.readSpace();
        k = inf.readInt(0, n, "k");
        inf.readEoln();

        for(int i=0;i<n-1;i++) {
            int u,v;
            u = inf.readInt(1, n, "u");
            inf.readSpace();
            v = inf.readInt(1, n, "v");
            inf.readEoln();
            a[u].push_back(v);
            a[v].push_back(u);
        }

        

        ensuref(dfs(1)==n, "The graph must be a tree!");

        for(int i=1;i<=n;i++) {
            a[i].clear();
            vis[i]=false;
        }
    }

    inf.readEof();
}
