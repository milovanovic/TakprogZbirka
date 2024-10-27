#include <bits/stdc++.h>
#define maxN 200005

using namespace std;

long long n,q,i,j,a[maxN],x,y,k,ans;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    cin>>q;
    for(i=0;i<q;i++){
        cin>>x>>y>>k;
        x--;
        y--;
        ans=0;
        for(j=x;j<=y;j+=k) ans+=a[j];
        cout<<ans<<"\n";
    }
    return 0;
}
