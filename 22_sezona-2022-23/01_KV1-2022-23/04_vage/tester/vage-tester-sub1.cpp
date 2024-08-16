#include<bits/stdc++.h>
#define maxn 500000
using namespace  std;
int n,m;
int d[maxn];
int u[maxn];
int l[maxn];
int r[maxn];
int x[maxn];
int main() {
    scanf("%d %d",&n,&m);
    assert(1<=n && n<=1000);
    assert(1<=m && m<=1000);
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&d[i],&u[i]);
        assert(0<=d[i] && d[i]<=u[i] && u[i]<=1000000000);
    }
    for(int i=1;i<=m;i++) {
        scanf("%d %d %d",&l[i],&r[i],&x[i]);
        assert(1<=l[i] && l[i]<=r[i] && r[i]<=n);
        assert(0<=x[i] && x[i]<=1000000000);
        int ans=0;
        for(int j=l[i];j<=r[i];j++) {
            if(d[j]<=x[i] && x[i]<=u[j]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
