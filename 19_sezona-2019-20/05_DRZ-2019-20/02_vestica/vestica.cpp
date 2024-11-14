#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9+10;
const int maxi = 10010;
const int maxN = 10000;
const int maxM = 10000;

int dp[2][maxi];
int n, m;
int l[maxi];
int r[maxi];

int main()
{
    cin>>n>>m;

    assert(n>=1 && n<=maxN);
    assert(m>=1 && m<=maxM);

    for (int i = 1; i<=n; i++)
    {
        cin>>l[i]>>r[i];
        assert(l[i]<=r[i] && l[i]<=m && l[i]>0 && r[i]<=m && r[i]<=m);
    }

    reverse(l+1, l+n+1);
    reverse(r+1, r+n+1);

    for (int i = 1; i<=n; i++)
    {
        int len = r[i] - l[i];

        for (int j =1; j<=m; j++)
            dp[i&1][j] = inf;

        for (int j = 1; j<=m-len; j++)
            for (int k = j; k<=j+len - r[i-1] + l[i-1]; k++)
                dp[i&1][j] = min(dp[i&1][j], dp[(i&1)^1][k] + abs(j - l[i]));
    }

    int ans = inf;

    for (int i=1; i<=m; i++)
        ans = min(ans, dp[n&1][i]);

    cout<<ans<<endl;

    return 0;
}
