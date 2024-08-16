#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
long long a[MAXN*MAXN],b[MAXN*MAXN];
int main()
{
    int n,m,k,l;
    cin>>n>>m>>k>>l;
    for(int i=0;i<m*n;i++) cin>>a[i];
    sort(a,a+m*n);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        long long kx=min(n,i+k-1)-max(k,i)+1,ky=min(m,j+l-1)-max(l,j)+1;
        b[(i-1)*m+j-1]=kx*ky;
    }
    sort(b,b+m*n);
    long long ans=0;
    for(int i=0;i<n*m;i++) ans+=a[i]*b[i];
    cout<<ans;
}
