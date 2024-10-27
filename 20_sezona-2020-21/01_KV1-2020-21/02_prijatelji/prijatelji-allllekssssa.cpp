#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
const int maxi = 1e6+10;
int a[maxi];
int n, m;
map<pii, int> mp;

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);

    assert(n<=100000 && n>0 && m<=100000 && m>0);

    for (int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        assert(a[i]>=(int) - 1e9 && a[i]<= (int) 1e9);
    }

    long long ans = 0;

    for (int i = 1;i<=m;i++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        assert(x!=y);
        int val = mp[{x, y}];
        assert(val == 0);
        mp[{x, y}] = 1;
        mp[{y, x}] = 1;
        ans+=abs(a[x] + a[y]);
    }

    cout<<ans<<endl;
}
