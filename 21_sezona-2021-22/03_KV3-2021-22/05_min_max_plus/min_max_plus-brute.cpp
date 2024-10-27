#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int t[N],k[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&t[i]);
	for(int i=1;i<=n;i++)scanf("%i",&k[i]);
	int q;
	scanf("%i",&q);
	while(q--){
		int l,r,x;
		scanf("%i %i %i",&l,&r,&x);
		ll X0=x;
		ll ans=0;
		for(int i=l;i<=r;i++){
			if(t[i]==1)X0=min(X0,(ll)k[i]);
			else if(t[i]==2)X0=max(X0,(ll)k[i]);
			else if(t[i]==3)X0+=k[i];
			ans+=X0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
