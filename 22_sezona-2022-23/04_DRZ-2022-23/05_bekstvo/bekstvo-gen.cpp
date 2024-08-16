#include <bits/stdc++.h>
#include "testlib.h"
#define maxn 3000000
using namespace std;
int tc;
int n,k;
int b[maxn];
int p[maxn];
int perm[maxn];
vector<pair<int,int>> edges;
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

void print() {
    shuffle(edges.begin(),edges.end());
    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++) {
        perm[i] = i;
    }
    shuffle(perm+1,perm+(n+1));
    for(int i=0;i<n-1;i++) {
        printf("%d %d\n",perm[edges[i].first],perm[edges[i].second]);
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    tc=atoi(argv[2]);

    n=atoi(argv[3]);

    if(strcmp(argv[4],"random")!=0 && strcmp(argv[4],"equidistant")!=0) {
        k=atoi(argv[4]);
    }

    printf("%d\n",tc);

    for(int it=0;it<tc;it++) {
        if(strcmp(argv[4],"equidistant")==0) {
            k = it*n/(tc-1);
        }
        if(strcmp(argv[4],"random")==0) {
            k = rnd.next(n+1);
        }


        if(strcmp(argv[1],"tree")==0) {
            int t=atoi(argv[5]);
            for(int i=2;i<=n;i++) p[i]=rnd.wnext(i-1,t)+1;
        }
        if(strcmp(argv[1],"path")==0) {
            for(int i=2;i<=n;i++) p[i]=i-1;
        }
        if(strcmp(argv[1],"binary")==0) {
            for(int i=2;i<=n;i++) p[i]=i/2;
        }
        edges.clear();
        for(int i=2;i<=n;i++) {
            if(rnd.next(2)&1) {
                edges.push_back({i,p[i]});
            }
            else {
                edges.push_back({p[i],i});
            }
        }
        print();
    }
    
    return 0;
}
