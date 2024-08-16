#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
int n,m,q;
vector<vector<ll> > a,dp_top;
int main() {
    scanf("%d %d",&n,&m);
    a.resize(n+2);dp_top.resize(n+2);
    for(int i=0;i<=n+1;i++) {
        a[i].resize(m+2);dp_top[i].resize(m+2);
        for(int j=0;j<=m+1;j++) a[i][j]=dp_top[i][j]=inf;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
    scanf("%d",&q);
    while(q--) {
        int x,y;
        scanf("%d %d",&x,&y);
        for(int i=0;i<=n+1;i++) {
            for(int j=0;j<=m+1;j++) dp_top[i][j]=inf;
        }
        dp_top[1][1]=a[1][1];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(i==x && j==y) dp_top[i][j]=inf;
                else dp_top[i][j]=min(dp_top[i][j],min(dp_top[i-1][j],dp_top[i][j-1])+a[i][j]);
            }
        }
        printf("%lld\n",dp_top[n][m]);
    }
    return 0;
}
