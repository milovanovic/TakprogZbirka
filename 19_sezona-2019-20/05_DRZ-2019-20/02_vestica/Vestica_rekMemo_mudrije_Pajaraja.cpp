#include <bits/stdc++.h>
#define MAXN 2007
using namespace std;
int n,m,l[MAXN],r[MAXN],d[MAXN],dp[MAXN][MAXN];
int rek(int x,int ld, int rd)
{
	if(x==n) return 0;
	if(dp[x][ld]!=-1) return dp[x][ld];
	int sol=1000000000;
	for(int i=ld;i+d[x]<=rd;i++) sol=min(sol,abs(i-l[x])+rek(x+1,i,i+d[x]));
	dp[x][ld]=sol;
	return sol;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<MAXN;i++) for(int j=0;j<MAXN;j++) dp[i][j]=-1;
	for(int i=0;i<n;i++) cin>>l[i]>>r[i];
	for(int i=0;i<n;i++) d[i]=r[i]-l[i];
	cout<<rek(0,1,m);
}
