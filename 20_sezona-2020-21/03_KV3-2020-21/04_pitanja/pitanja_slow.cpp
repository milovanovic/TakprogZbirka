#include <bits/stdc++.h>
#define maxN 200005

using namespace std;

long long n,q,i,j,a[maxN],s[maxN],x,y,k,ans;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    cin>>q;
    s[0]=a[0];
    for(i=1;i<n;i++) s[i]=s[i-1]+a[i];
    for(i=0;i<q;i++){
        cin>>x>>y>>k;
        x--;
        y--;
        ans=0;
        if(k>1){
        for(j=x;j<=y;j+=k) ans+=a[j];
        cout<<ans<<"\n";}
        else cout<<s[y]-s[x]+a[x]<<endl;
    }
    return 0;
}
