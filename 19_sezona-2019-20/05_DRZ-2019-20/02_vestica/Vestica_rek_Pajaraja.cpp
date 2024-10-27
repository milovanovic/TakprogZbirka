#include <bits/stdc++.h>
#define MAXN 10007
using namespace std;
int n,m,l[MAXN],r[MAXN],d[MAXN];
int rek(int x,int ld, int rd)
{
	if(x==n) return 0;
	int sol=1000000000;
	for(int i=1;i+d[x]<=m;i++) if(i>=ld && i+d[x]<=rd) sol=min(sol,abs(i-l[x])+rek(x+1,i,i+d[x]));
	return sol;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>l[i]>>r[i];
	for(int i=0;i<n;i++) d[i]=r[i]-l[i];
	cout<<rek(0,1,m);
}
