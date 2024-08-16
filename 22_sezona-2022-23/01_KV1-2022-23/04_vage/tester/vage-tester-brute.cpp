#include<bits/stdc++.h>
#define maxn 500000
#pragma GCC optimize("O3")
using namespace  std;
int n,m;
int d[maxn];
int u[maxn];
int l[maxn];
int r[maxn];
int x[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&d[i],&u[i]);
    }
    for(int i=1;i<=m;i++) {
        scanf("%d %d %d",&l[i],&r[i],&x[i]);
        int ans=0;
        #pragma unroll
        for(int j=l[i];j<=r[i];j++) {
            if(d[j]<=x[i] && x[i]<=u[j]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
