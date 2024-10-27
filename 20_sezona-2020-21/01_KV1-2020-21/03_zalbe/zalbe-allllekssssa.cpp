#include<bits/stdc++.h>

using namespace std;

const int maxi = 1e6+10;

int n, m;

long long a[maxi];

void solve()
{
    cin>>n>>m;

    assert(n<=75000 && m<=75000 && n>0 && m>0);

    long long gc = 0;
    for (int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        assert(a[i]>0 && a[i]<=(long long)1e18);
    }

    sort(a+1, a+n+1);

    for (int i = 1;i<n;i++)
        gc = __gcd(gc, a[i + 1] - a[i]);

    int ok = 1;
    for (int i = 1;i<=m;i++){
        long long x;
        scanf("%lld",&x);
        assert(x > 0 && x <= (long long)1e18);
        if (a[1] % gc == x % gc) ok = 0;
    }

   printf("%d\n", ok);
}

int main()
{
    int t;
    cin>>t;

    assert(t<=5 && t>=1);

    while(t--)
        solve();
}
