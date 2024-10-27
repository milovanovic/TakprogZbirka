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

    int ansUp = -10;

    for (int i = 1;i<=a;i++)
      for (int j =1;j<=b;j++)
         ansUp = max(ansUp, c[i][j] - 2*i - 2*j);

    int ansDown = -10;

    for (int i=a;i<=n;i++)
        for (int j=b;j<=m;j++)
         ansDown = max(ansDown, ansUp + c[i][j] + 2*i + 2*j +4);

    printf("%d\n",ansDown);
}
