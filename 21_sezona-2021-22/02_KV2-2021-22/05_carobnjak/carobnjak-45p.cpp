#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
long long a[maxn];
int n,k;
long long pref[maxn];
long long suf[maxn];
pair<long long,int> b[maxn];
long long solve() {
    for(int i=1;i<=n;i++) {
        pref[i]=pref[i-1]+a[i];
    }
    for(int i=n;i>=1;i--) {
        suf[i]=suf[i+1]+a[i];
    }
    long long ans=-1e18;
    for(int i=1;i<=n-1;i++) {
        long long t=0;
        for(int j=1;j<=n;j++) {
            if(j<=i) b[j]={a[j],1};
            else b[j]={-a[j],0};
        }
        sort(b+1,b+n+1);
        int pc=0,sc=0;
        int tc=0;
        for(int j=1;tc<n-k;j++) {
            if(pc+b[j].second<i && sc+1-b[j].second<n-i) {
                tc++;
                pc+=b[j].second;
                sc+=(1-b[j].second);
                t+=b[j].first;
            }
        }
        ans=max(ans,pref[i]-suf[i+1]-t);
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
