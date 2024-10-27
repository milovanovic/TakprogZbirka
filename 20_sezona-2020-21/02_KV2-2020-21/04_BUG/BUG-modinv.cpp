#include<bits/stdc++.h>
#define maxn 200000
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
long long fact[2*maxn];
long long invfact[2*maxn];
inline void precalc() {
    fact[0]=invfact[0]=1;
    for(int i=1;i<2*maxn;i++) {
        fact[i]=(fact[i-1]*i)%mod;
        invfact[i]=inverse(fact[i]);
    }
}
inline long long binom(long long x,long long y) {
    if(y<0 || y>x) return 0;
    return (((fact[x]*invfact[y])%mod)*invfact[x-y])%mod;
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
