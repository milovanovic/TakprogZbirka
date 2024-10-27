#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int c[MAXN][MAXN];
int main()
{
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&c[i][j]);
	int mx=0;
	for(int x=1;x<=a;x++) for(int y=1;y<=b;y++) for(int z=a;z<=n;z++) for(int t=b;t<=m;t++) mx=max(mx,c[x][y]+c[z][t]+2*(z+t-x-y)+4);
	printf("%d",mx);
}
