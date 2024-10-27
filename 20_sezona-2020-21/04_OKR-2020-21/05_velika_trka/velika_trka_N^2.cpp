#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
long long x[MAXN],y[MAXN];
int main()
{
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&q);
	while(q--)
	{
		long long xt,yt;
		int l,r;
		scanf("%lld%lld%d%d",&xt,&yt,&l,&r);
        for(int i=l;i<=r;i++) xt=2*x[i]-xt;
        for(int i=l;i<=r;i++) yt=2*y[i]-yt;
        printf("%lld %lld\n",xt,yt);
    }
}
