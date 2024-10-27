#include <bits/stdc++.h>
#define MAXN 10007
using namespace std;
int n,m,dp[MAXN],dpl[MAXN],l[MAXN],r[MAXN],d[MAXN];
int seg[4*MAXN];
void upd(int l,int r,int v,int poz,int ind)
{
	if(l==r) {seg[ind]=v; return;}
	int s=(l+r)/2;
	if(poz<=s) upd(l,s,v,poz,2*ind);
	else upd(s+1,r,v,poz,2*ind+1);
	seg[ind]=min(seg[2*ind],seg[2*ind+1]);
}
int nmin(int l,int r,int lt,int rt,int ind)
{
	if(lt<=l && r<=rt) return seg[ind];
	if(r<lt || l>rt) return 1000000000;
	int s=(l+r)/2;
	return min(nmin(l,s,lt,rt,2*ind),nmin(s+1,r,lt,rt,2*ind+1)); 
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>l[i]>>r[i];
	for(int i=0;i<n;i++) d[i]=r[i]-l[i];
	fill(dpl,dpl+MAXN,1000000000);
	fill(seg,seg+4*MAXN,1000000000);
	for(int i=1;i+d[0]<=m;i++) dpl[i]=abs(i-l[0]);
	for(int i=1;i<n;i++)
	{
		fill(dp,dp+MAXN,1000000000);
		for(int j=1;j<=m;j++) upd(1,m,dpl[j],j,1);
		for(int j=1;j+d[i]<=m;j++) dp[j]=min(dp[j],nmin(1,m,max(0,j+d[i]-d[i-1]),j,1)+abs(j-l[i]));
		for(int j=1;j<=m;j++) dpl[j]=dp[j];
	}
	int res=100000000; for(int i=0;i<MAXN;i++) res=min(res,dp[i]);
	cout<<res;
}
