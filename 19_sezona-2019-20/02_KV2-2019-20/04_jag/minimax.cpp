#include<bits/stdc++.h>
using namespace std;
bool tkn[100];
bool fs[100];
vector<int> a[100];
int n;
int dfs(int u,int p,int d=0) {
    int rt=0;
    if(fs[u]) rt=d;
    for(v:a[u]) {
        if(v!=p) rt=max(rt,dfs(v,u,d+1));
    }
    return rt;
}
int dist() {
    int d=0;
    for(int i=1;i<=n;i++) {
        if(fs[i]) d=max(d,dfs(i,-1));
    }
    return d;
}
int value(int i) {
    if(i>n) {
        return dist();
    }
    int rt;
    if(i%2==1) rt=1000;
    else rt=0;
    for(int j=1;j<=n;j++) {
        if(!tkn[j]) {
            if(i%2==1) {
                tkn[j]=true;
                fs[j]=true;
            }
            else {
                tkn[j]=true;
                fs[j]=false;
            }
            if(i%2==1) rt=min(rt,value(i+1));
            else rt=max(rt,value(i+1));
            tkn[j]=false;
            fs[j]=false;
        }
    }
    return rt;
}
int main() {
    scanf("%d",&n);
    int u,v;
    for(int i=0;i<n-1;i++) {
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    printf("%d",value(1));
    return 0;
}
