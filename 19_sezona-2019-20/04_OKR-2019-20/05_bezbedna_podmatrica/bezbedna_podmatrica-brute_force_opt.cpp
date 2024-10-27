#include<bits/stdc++.h>

using namespace std;

const int maxN = 1001;
const int maxV = 1001;
int c[maxN][maxN];
int n, m, a, b;
int main()
{
   freopen("09.in","r",stdin);
   scanf("%d%d%d%d",&n,&m,&a,&b);
   assert(n>0 && n<maxN  && m>0 && m<maxN);
   assert(a>0 && a<=n && b>0 && b<=m);

   for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
     scanf("%d",&c[i][j]);
     assert(c[i][j]>0 && c[i][j]<51);
    }

   int ans = 0;

   for (int i=1;i<=min(a, 50);i++)
    for (int j=1;j<=min(b, 50);j++)
    for (int k = max(n - 50, a);k<=n;k++)
    for (int l= max(m -50, b); l<=m;l++)
     ans = max(ans, c[i][j] + c[k][l] + 2*(k +l -i -j) + 4);

   cout<<ans<<endl;
}
