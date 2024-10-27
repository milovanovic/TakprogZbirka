#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int inf=1e9+7;

char s[N];
int C;

int main(){
	int n,q;
	scanf("%i %i %i",&n,&C,&q);
	assert(1<=n && n<=4000);
	assert(C==n);
	assert(1<=q && q<=4000);

	scanf("%s",s+1);
	assert(strlen(s+1)==n);
	for(int i=1;i<=n;i++)assert(s[i]=='0' || s[i]=='1');

	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%i %i",&l,&r);
		assert(1<=l && l<=r && r<=n);
		for(int j=l;j<=r;j++){
			if(s[j]=='1')s[j]='0';
			else s[j]='1';
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s[j]=='1')ans++;
		}
		printf("%i\n",ans);
	}
	return 0;
}
