#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
long long a[MAXN],pref[MAXN],suf[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
    long long sol=0;
    for(int i=1;i<n;i++) sol=max(abs(pref[i]-suf[i+1]),sol);
    cout<<sol;
}
