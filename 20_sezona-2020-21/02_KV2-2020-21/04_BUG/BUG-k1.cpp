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
long long pref[maxn];
inline void input() {
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
}
inline long long solve() {
    long long sum=0;
    pref[0]=0;
    for(int i=1;i<=n;i++) {
        pref[i]=(pref[i-1]+a[i])%mod;
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            sum=(sum+pref[j]+mod-pref[i-1])%mod;
        }
    }
    return sum;
}
int main() {
    input();
    printf("%lld",solve());
    return 0;
}
