#include<bits/stdc++.h>

using namespace std;

const int maxN = 1001;
const int maxV = 1001;
int c[maxN][maxN];
int n, m, a, b;
int main()
{
   scanf("%d%d%d%d",&n,&m,&a,&b);

   assert(n>0 && n<maxN  && m>0 && m<maxN);
   assert(a>0 && a<=n && b>0 && b<=m);

   for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
     scanf("%d",&c[i][j]);
     assert(c[i][j]>0 && c[i][j]<maxV);
    }

   int ans = 0;

   for (int i=1;i<=min(a, 150);i++)
    for (int j=1;j<=min(b, 150);j++)
    for (int k = max(n - 150, a);k<=n;k++)
    for (int l= max(m -150, b); l<=m;l++)
     ans = max(ans, c[i][j] + c[k][l] + 2*(k +l -i -j) + 4);

   cout<<ans<<endl;
}
