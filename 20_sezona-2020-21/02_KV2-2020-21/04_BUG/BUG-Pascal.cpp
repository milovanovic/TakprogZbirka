#include<bits/stdc++.h>
#define maxn 4001
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
long long binomc[maxn][maxn];
inline void precalc() {
    binomc[0][0]=1;
    for(int i=1;i<maxn;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0 || j==i) binomc[i][j]=1;
            else {
                binomc[i][j]=binomc[i-1][j]+binomc[i-1][j-1];
                if(binomc[i][j]>=mod) binomc[i][j]-=mod;
            }
        }
    }
}
inline long long binom(long long x,long long y) {
    if(y<0 || y>x) return 0;
    return binomc[x][y];
}
inline void input() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
}
inline long long solve() {
    long long ret=0;
    for(int i=0;i<n;i++) {
        ret=(ret+a[i]*((binom(k+i,i)*binom(k+n-1-i,n-1-i))%mod))%mod;
    }
    return ret;
}
int main() {
    precalc();
    input();
    printf("%lld",solve());
    return 0;
}
