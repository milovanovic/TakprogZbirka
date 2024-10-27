#include <bits/stdc++.h>
#define MAXN 300007
#define MAXL 20
using namespace std;
int a[2*MAXN],rf[MAXN],l[MAXN],r[MAXN],p[2*MAXN];
bool check(int u, int v)
{
	return (l[u]<l[v] && r[v]<r[u]) || (l[v]<l[u] && r[u]<r[v]);
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=2*n;i++)
	{
		if(!l[a[i]]) l[a[i]]=i;
		else r[a[i]]=i;
	}
	for(int i=1;i<=n;i++) {p[l[i]]=r[i]; p[r[i]]=l[i];}
	int mxr=0,nd=0;
	for(int i=1;i<=2*n;i++) if(p[i]>i)
	{
		if(p[i]<mxr) rf[a[i]]=nd;
		else {rf[a[i]]=-1; mxr=p[i]; nd=a[i];}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		if(u==v) {printf("0\n"); continue;}
		if(check(u,v)) {printf("1\n"); continue;}
		if(rf[u]==rf[v] && rf[u]!=-1) {printf("2\n"); continue;}
		else printf("-1\n");
	}
}
