#include <bits/stdc++.h>

using namespace std;
long long int typedef li;

int a[200005];
li pre[200005];
li suf[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    pre[1]=a[1];
    for (int i=2;i<=n;i++) pre[i]=min(pre[i-1],pre[i-2])+a[i];
    suf[n]=a[n];
    for (int i=n-1;i>=1;i--) suf[i]=min(suf[i+1],suf[i+2])+a[i];

    int q; cin>>q;
    while (q--)
    {
        int l,r; cin>>l>>r;
        if (l==1) cout<<min(suf[r+1],suf[r+2])<<"\n";
        else if (r==n) cout<<min(pre[l-1],pre[l-2])<<"\n";
        else cout<<min(min(pre[l-2]+suf[r+1],pre[l-1]+suf[r+2]),pre[l-1]+suf[r+1])<<"\n";
    }
}