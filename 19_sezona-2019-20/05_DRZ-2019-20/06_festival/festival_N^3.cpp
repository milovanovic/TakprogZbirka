#include <bits/stdc++.h>
#define MAXN 3007
using namespace std;
long long d[MAXN][MAXN];
int a[2*MAXN],l[MAXN],r[MAXN];
int main()
{
	int n,q; scanf("%d%d",&n,&q);
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=2*n;i++)
	{
		if(!l[a[i]]) l[a[i]]=i;
		else r[a[i]]=i;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j)
	{
		if((l[i]<l[j] && r[j]<r[i]) || (l[j]<l[i] && r[i]<r[j])) d[i][j]=1;
		else d[i][j]=1000000000;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(d[i][j]>=1000000000) d[i][j]=-1;
	for(int i=0;i<q;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		printf("%lld\n",d[u][v]);
	}
}
