#include <bits/stdc++.h>
using namespace std;
int cnt[300007];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    assert(1<=n*m);
    assert(n*m<=300000);
    assert(1<=q);
    assert(q<=300000);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }
    for(int i=1;i<=n*m;i++) assert(cnt[i]==1);
    while(q--)
    {
        int xa,ya,xb,yb;
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        assert(xa>=1);
        assert(xa<=n);
        assert(xb>=1);
        assert(xb<=n);
        assert(ya>=1);
        assert(ya<=m);
        assert(yb>=1);
        assert(yb<=m);
        assert(xa!=xb || ya!=yb);
    }
    return 0;
}
