#include<bits/stdc++.h>
#define maxn 2000000
#define maxm 200
using namespace std;
long long dp[maxm][maxm];
long long ndp[maxm][maxm];
int n,m;
int a[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            dp[i][j]=-1e18;
        }
    }
    dp[0][0]=0;
    for(int k=0;k<n;k++) {
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                ndp[i][j]=dp[i][j];
            }
        }
        int dif=a[k]%m;
        for(int i=0;i<m;i++) {
            int ni=i+1;
            if(ni==m) ni=0;
            for(int j=0;j<m;j++) {
                int nj=j+dif;
                if(nj>=m) nj-=m;
                ndp[ni][nj]=max(ndp[ni][nj],dp[i][j]+a[k]);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j]=ndp[i][j];
            }
        }
    }
    printf("%lld",dp[0][0]);
    return 0;
}
