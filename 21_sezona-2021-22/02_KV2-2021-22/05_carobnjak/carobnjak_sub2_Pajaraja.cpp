#include <bits/stdc++.h>
#define MAXN 207
using namespace std;
int n,k,a[MAXN],dp[2][2][MAXN][MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) for(int t=0;t<=n;t++)
    {
        dp[0][0][i][j][t]=dp[1][0][i][j][t]=1000000000;
        dp[0][1][i][j][t]=dp[1][1][i][j][t]=-1000000000;
    }
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
    {
        dp[0][0][i][j][1]=dp[0][1][i][j][1]=a[i];
        dp[1][0][i][j][1]=dp[1][1][i][j][1]=a[j];
    }
    for(int d=n-1;d>0;d--) for(int i=1;i+d<=n;i++) for(int t=0;t<=k;t++)
    {
        int j=i+d;
        dp[0][0][i][j-1][t+1]=min(dp[0][0][i][j-1][t+1],a[i]-dp[1][1][i][j][t]);
        dp[0][1][i][j-1][t+1]=max(dp[0][1][i][j-1][t+1],a[i]-dp[1][0][i][j][t]);
        dp[0][0][i][j-1][t+1]=min(dp[0][0][i][j-1][t+1],dp[0][0][i][j][t]-a[j]);
        dp[0][1][i][j-1][t+1]=max(dp[0][1][i][j-1][t+1],dp[0][1][i][j][t]-a[j]);
        dp[1][0][i+1][j][t+1]=min(dp[1][0][i+1][j][t+1],a[j]-dp[0][1][i][j][t]);
        dp[1][1][i+1][j][t+1]=max(dp[1][1][i+1][j][t+1],a[j]-dp[0][0][i][j][t]);
        dp[1][0][i+1][j][t+1]=min(dp[1][0][i+1][j][t+1],dp[1][0][i][j][t]-a[i]);
        dp[1][1][i+1][j][t+1]=max(dp[1][1][i+1][j][t+1],dp[1][1][i][j][t]-a[i]);
        dp[0][0][i][j-1][t]=min(dp[0][0][i][j-1][t],dp[0][0][i][j][t]);
        dp[0][1][i][j-1][t]=max(dp[0][1][i][j-1][t],dp[0][1][i][j][t]);
        dp[1][0][i+1][j][t]=min(dp[1][0][i+1][j][t],dp[1][0][i][j][t]);
        dp[1][1][i+1][j][t]=max(dp[1][1][i+1][j][t],dp[1][1][i][j][t]);
    }
    int sol=-1000000000;
    for(int i=1;i<=n;i++) sol=max(sol,dp[0][1][i][i][k]);
    for(int i=1;i<=n;i++) sol=max(sol,dp[1][1][i][i][k]);
    cout<<sol;
}
