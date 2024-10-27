#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int maxN = 1010;

pii d[5][maxN][maxN];
int n, m, q;
int a[maxN][maxN];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

pii merge(pii x, pii y)
{
    if (!x.first) return y;
    if (!y.first) return x;
    if (x.first  == y.first) return {x.first, x.second + y.second};
    return min(x, y);
}

pii remove(pii x, pii y)
{
    if (x.first == y.first) return {x.first, x.second - y.second};
    return x;
}

int main()
{
   scanf("%d%d%d",&n,&m,&q);

   int startx[4] = {1, 1, n, n};
   int starty[4] = {1, m, 1, m};

   for (int i = 1;i<=n;i++)
    for (int j = 1;j<=m;j++)
    {
     scanf("%d",&a[i][j]);
     a[i][j]++;
    }

   for (int k = 0;k<4;k++)
   for (int i = startx[k];i && i!=n+1;i+=dx[k])
   for (int j = starty[k];j && j!=m+1;j+=dy[k])
     d[k][i][j] = remove(merge(merge(d[k][i-dx[k]][j], d[k][i][j-dy[k]]), {a[i][j], 1}), d[k][i-dx[k]][j-dy[k]]);

   while(q--)
   {
       int x1, y1, x2, y2;
       int h, w;
       scanf("%d%d%d%d",&x1,&y1,&h,&w);
       x2 = x1 + h - 1;
       y2 = y1 + w - 1;
       pii ans = merge(merge(d[0][x1-1][y2], d[1][x2][y2+1]), merge(d[2][x1][y1-1], d[3][x2+1][y1]));

       printf("%d\n",ans.second);
   }
}
