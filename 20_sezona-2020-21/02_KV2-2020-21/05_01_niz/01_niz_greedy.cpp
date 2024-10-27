#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int inf=1e9+7;

char s[N];
int C;

int main(){
	int n,q;
	scanf("%i %i %i",&n,&C,&q);
	assert(1<=n && n<=200000);
	assert(1<=C && C<=n);
	assert(1<=q && q<=200000);

	scanf("%s",s+1);
	assert(strlen(s+1)==n);
	for(int i=1;i<=n;i++)assert(s[i]=='0' || s[i]=='1');

	for(int k=1;k<=q;k++){
		int l,r;
		scanf("%i %i",&l,&r);
		assert(1<=l && l<=r && r<=n);
		for(int i=l;i<=r;i++){
			if(s[i]=='0')s[i]='1';
			else s[i]='0';
		}
		int ans=0,bal=0,one=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				if(bal<C)bal++;
				else ans++;
				one++;
			}else{
				if(bal>0)bal--;
			}
		}
		printf("%i\n",one-ans);
	}
	return 0;
}
