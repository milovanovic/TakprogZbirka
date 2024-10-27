#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair<int,int>

const int maxN = 1010;
int a[maxN][maxN];
int n, m, q;
vector<pair<int, pii>> v;

int inside(int a1, int b1, int x1, int x2,int y1, int y2)
{
    return (a1>=x1 && a1<=x2 && b1>=y1 && b1<=y2);
}

int main()
{
    cin>>n>>m>>q;

    for (int  i= 1; i<=n; i++)
        for (int j = 1; j<=m; j++)
        {
            scanf("%d",&a[i][j]);
            v.pb({a[i][j], {i, j}});
        }

    sort(v.begin(), v.end());

    while(q--)
    {
        int x, y, h, w;
        scanf("%d%d%d%d",&x,&y,&h,&w);
        int x1 = x + h - 1;
        int y1 = y + w - 1;

        int ima = 0;
        int cnt = 0;
        for (int i = 0 ; i <n*m ; i++)
            if (i && ima && v[i].first != v[i-1].first ) break;
            else if (!inside(v[i].second.first, v[i].second.second, x, x1, y, y1))
            {
                ima++;
                cnt++;
            }
        printf("%d\n", cnt);
    }
}
