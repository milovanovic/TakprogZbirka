#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxN = 1001;
vector<pair<int,int>> v;
int n,m, a, b;
int c[maxN][maxN];

int main()
{
    cin>>n>>m>>a>>b;

    int mm = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            scanf("%d",&c[i][j]);
            mm = max(mm, c[i][j]);
        }

    for (int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if (mm-c[i][j]<=30)
                v.pb({i,j});
        }

    int ans = 0;
    for (auto i:v)
        for (auto j:v)
            if (max(i.first, j.first)>=a && min(i.first, j.first)<=a && max(i.second, j.second)>=b && min(i.second, j.second)<=b)
                ans = max(ans, 4 + c[i.first][i.second] + c[j.first][j.second] + 2*abs(i.first - j.first) + 2*abs(i.second  - j.second));

    cout<<ans<<endl;
}
