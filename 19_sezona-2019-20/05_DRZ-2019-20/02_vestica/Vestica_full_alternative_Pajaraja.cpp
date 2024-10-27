#include <bits/stdc++.h>
#define MAXN 10007
using namespace std;
int n,m,dp[MAXN],dpl[MAXN],l[MAXN],r[MAXN],d[MAXN],sk[MAXN],rk[MAXN],lk[MAXN];
void allk(int k)
{
	for(int z=1;z*k<=m;z++)
	{
		int lm=1000000000;
		for(int i=0;i<k && z*k+i<=m;i++) {lm=min(lm,dpl[z*k+i]); rk[z*k+i]=lm;}
		lm=1000000000;
		for(int i=0;i<k && z*k-i>0;i++) {lm=min(lm,dpl[z*k-i]); lk[z*k-i]=lm;}
	}
	for(int i=1;i+k-1<=m;i++) sk[i]=min(lk[i],rk[i+k-1]);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>l[i]>>r[i];
	reverse(l,l+n); reverse(r,r+n);
	for(int i=0;i<n;i++) d[i]=r[i]-l[i];
	fill(dpl,dpl+MAXN,1000000000);
	for(int i=1;i+d[0]<=m;i++) dpl[i]=abs(i-l[0]);
	for(int i=1;i<n;i++)
	{
		fill(dp,dp+MAXN,1000000000);
		allk(d[i]-d[i-1]+1);
		for(int j=1;j+d[i]<=m;j++) dp[j]=min(dp[j],sk[j]+abs(j-l[i]));
		for(int j=1;j<=m;j++) dpl[j]=dp[j];
	}
	int res=100000000; for(int i=0;i<MAXN;i++) res=min(res,dp[i]);
	cout<<res;
}
