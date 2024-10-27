#include<bits/stdc++.h>
#define maxn 2000
using namespace std;
long long mod=1000000007;
inline long long step(long long a,long long b) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
inline long long inverse(long long a) {
    return step(a,mod-2);
}
int n,k;
long long a[maxn];
long long dp[maxn][maxn];
inline void input() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
}
inline long long solve() {
    for(int i=0;i<n;i++) {
        dp[i][i]=a[i];
        for(int j=i+1;j<n;j++) {
            dp[i][j]=(dp[i][j-1]+a[j])%mod;
        }
    }
    for(int t=1;t<=k;t++) {
        for(int l=1;l<n;l++) {
            for(int i=0;i+l<n;i++) {
                int j=i+l;
                dp[i][j]=(dp[i][j]+dp[i][j-1]+dp[i+1][j]+mod-dp[i+1][j-1])%mod;
            }
        }
    }
    return dp[0][n-1];
}
int main() {
    input();
    printf("%lld",solve());
    return 0;
}
