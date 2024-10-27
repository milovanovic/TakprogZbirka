#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int inf=1e9+7;

char s[N];
int C;

int dp[N];

int main(){
	int n,q;
	scanf("%i %i %i",&n,&C,&q);
	assert(1<=n && n<=200000);
	assert(1<=C && C<=n);
	assert(1<=q && q<=200000);

	assert(q==1 && n<=1000);

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
		dp[0]=0;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]+(s[i]=='1');
			int zero=0;
			for(int j=i;j>=1;j--){
				if(s[j]=='0')zero++;
				dp[i]=min(dp[i],dp[j-1]+C+zero);
			}
		}
		printf("%i\n",dp[n]);
	}
	return 0;
}
