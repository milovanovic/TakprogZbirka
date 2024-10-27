#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
long long a[maxn];
int n,k;
long long pref[maxn];
long long suf[maxn];
long long solve() {
    for(int i=1;i<=n;i++) {
        pref[i]=pref[i-1]+a[i];
    }
    for(int i=n;i>=1;i--) {
        suf[i]=suf[i+1]+a[i];
    }
    long long ans=-1e18;
    for(int i=1;i<=n-1;i++) {
        ans=max(ans,pref[i]-suf[i+1]);
    }
    return ans;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    long long ans=solve();
    for(int i=1;i<=n;i++) {
        a[i]=-a[i];
    }
    ans=max(ans,solve());
    printf("%lld",ans);
    return 0;
}
