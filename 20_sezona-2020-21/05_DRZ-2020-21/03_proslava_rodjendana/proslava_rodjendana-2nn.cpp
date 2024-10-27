#include<bits/stdc++.h>
#define maxn 100000
using namespace std;
int n,m;
long long a[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    long long ans=0;
    for(int msk=0;msk<(1<<n);msk++) {
        int x=__builtin_popcount(msk);
        long long y=0;
        if(x%m!=0) continue;
        for(int i=0;i<n;i++) {
            if(msk&(1<<i)) y+=a[i];
        }
        if(y%m==0) ans=max(ans,y);
    }
    printf("%lld",ans);
    return 0;
}
