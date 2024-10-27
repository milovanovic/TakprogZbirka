#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma unroll

using namespace std;

int n;
string s;
int sum[1<<10][10], ss[1<<10], dp[1<<10][10];
int bits[1<<10][11];
int cur[1<<10];
int main()
{

    cin>>s;
    n = s.size();

    assert(n>0 && n<=(int) 1e5);

    for (int mask = 0; mask<(1<<10);mask++){
        cur[mask] = -1;
        for (int j = 0; j<10;j++)
            if (mask&(1<<j)) bits[mask][++cur[mask]] = j;
    }

    register int i;
    for (i = 1; i<=n;i++)
    {
        int cif = s[i - 1] - '0';
        ss[0] = 1e9 + 10;
        register int mask;
        for (mask = (1<<10)-1;mask>0;mask--){
          ss[mask] = 100000;
          int sz = cur[mask];
          register int idx;
          register int j;
         for  (idx = 0; ; idx++){
                j = bits[mask][idx];
                bool val =  cif ^ j;
                dp[mask][j] = min(dp[mask][j], ss[mask ^ (1<<j)]) + val;
                if (ss[mask] > dp[mask][j]) ss[mask] = dp[mask][j];
                if (!(idx^sz)) break;
            }
        }
    }


    int ans = ss[1];
    for (int mask = 1;mask<(1<<10);mask++)
        ans = min(ans, ss[mask]);

    cout<<ans<<endl;
}
