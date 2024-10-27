#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma unroll
#pragma comment(linker, "/stack:20000000")

using namespace std;

const int maxi = 1e5 + 10;
int n;
string s;
int sum[10][maxi], best[10][1<<10];
int dp[1<<10];
vector<int> good[10][10];
int main()
{
    //cin>> n;

  //  for (int i = 1;i<=n;i++)
   // s+='0' + i%10;
    cin>>s;
    n = s.size();

    assert(n>0 && n<=(int) 1e5);

    for (int i = 1;i<=n;i++){
        for (int j = 0; j<10;j++)
            sum[j][i] = sum[j][i-1] + 1;
        sum[s[i-1]-'0'][i]--;
    }

    for (int i = 0;i<10;i++)
    for (int j = 0;j<10;j++)
     for (int mask = 0; mask<1<<10;mask++)
     if ((mask&(1<<i)) && (mask&(1<<j)) ==0)
          good[i][j].push_back(mask);

    int ans = n;

    for (int i = 0;i<10;i++){
        best[i][0] = 0 ;
        for (int mask = 1;mask<1<<10;mask++)
        best[i][mask] = 1e9;
    }

    for (int i = 1; i<=n;i++)
    {
        int cif = s[i - 1] - '0';
        for (int mask = (1<<10) - 1;mask>0;mask--)
        if (mask&(1<<cif)){
           dp[mask] = best[cif][mask^(1<<cif)] + sum[cif][i];
        }

        for (int j = 0; j< 10;j++)
          for (auto mask:good[cif][j])
        {
            best[j][mask] = min(dp[mask] - sum[j][i], best[j][mask]);
            ans = min(ans, dp[mask] + sum[j][n] - sum[j][i]);
        }
    }

    cout<<ans<<endl;
}
