#include <bits/stdc++.h>
#define MAXN 3007
#define MAXL 20
using namespace std;
int a[2*MAXN],d[MAXN][MAXN],rs[MAXN],rf[MAXN],lf[MAXN],ls[MAXN],l[MAXN],r[MAXN],p[2*MAXN];
vector<int> g[MAXN];
bool check(int u, int v)
{
	return (l[u]<l[v] && r[v]<r[u]) || (l[v]<l[u] && r[u]<r[v]);
}
int bfs(int u)
{
	queue<int> q; q.push(u); d[u][u]=0;
	while(!q.empty())
	{
		int v=q.front(); q.pop();
		for(int i=0;i<g[v].size();i++)
		{
			int w=g[v][i];
			if(d[u][w]==1000000000) {d[u][w]=d[u][v]+1; q.push(w);}
		}
	}
}
void add(int u,int v)
{
	if(u==-1 || v==-1) return;
	g[u].push_back(v);
	g[v].push_back(u);
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
	int mxl=0; nd=0;
	for(int i=1;i<=2*n;i++) if(p[i]<i)
	{
		if(p[i]<mxl) rs[a[i]]=nd;
		else {rs[a[i]]=-1; mxl=p[i]; nd=a[i];}
	}
	int mnr=2*n+1; nd=0;
	for(int i=2*n;i>=1;i--) if(p[i]<i)
	{
		if(p[i]>mnr) lf[a[i]]=nd;
		else {lf[a[i]]=-1; mnr=p[i]; nd=a[i];}
	}
	int mnl=2*n+1; nd=0;
	for(int i=2*n;i>=1;i--) if(p[i]>i)
	{
		if(p[i]>mnl) ls[a[i]]=nd;
		else {ls[a[i]]=-1; mnl=p[i]; nd=a[i];}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=1000000000;
	for(int i=1;i<=n;i++) {add(i,rs[i]); add(i,rf[i]); add(i,ls[i]); add(i,lf[i]);}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=0;i<q;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		int res=3000000;
		for(int w=1;w<=n;w++) if(check(v,w)) res=min(res,d[u][w]+1);
		if(res==3000000) res=-1;
		printf("%d\n",res);
	}
}
