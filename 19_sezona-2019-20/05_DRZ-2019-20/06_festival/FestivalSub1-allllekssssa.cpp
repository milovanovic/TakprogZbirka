#include<bits/stdc++.h>

using namespace std;

struct inter
{
    int l;
    int r;
};

const int maxi = 1e6+10;
const int maxV = 500;
const int inf = 1e9;

int a[maxi];
inter c[maxi];
vector<int> v[maxi];
int d[600][600];
int n, q;
int cnt[maxi];

int sub(int x, int y)
{
    return c[x].l > c[y].l && c[x].r < c[y].r;
}

int main()
{
    scanf("%d%d",&n,&q);

    assert(n<=maxV && q<=maxV && n>=1 && q>=1);

    for (int i = 1; i<=n;i++)
        cnt[i] = 2;

    for (int i = 1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
        assert(a[i]<=n && a[i]>0 && cnt[a[i]]);
        cnt[a[i]]--;
        if (cnt[a[i]]) c[a[i]].l = i; else c[a[i]].r = i;
    }

    for (int i=1;i<=n;i++)
        for (int j = 1;j<=n;j++)
        if (i!=j && sub(i, j))
    {
        d[i][j] = 1;
        d[j][i] = 1;
    }

    for (int i =1;i<=n;i++)
        for (int j = 1;j<=n;j++)
         if (i!=j && !d[i][j])
           d[i][j] = inf;

    for (int k = 1;k<=n;k++)
      for (int i  =1 ;i<=n;i++)
        for (int  j = 1;j<=n;j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

      while(q--)
      {
          int x, y;
          scanf("%d%d",&x,&y);
          assert(x!=y && x<=n && x>=1 && y<=n && y>=1);

          if (d[x][y] == inf) printf("-1\n"); else printf("%d\n", d[x][y]);
      }

    return 0;
}
