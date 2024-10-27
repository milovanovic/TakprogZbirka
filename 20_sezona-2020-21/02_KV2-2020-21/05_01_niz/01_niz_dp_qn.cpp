#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int inf=1e9+7;

char s[N];
int C;

int dp[N][2];

int main(){
	int n,q;
	scanf("%i %i %i",&n,&C,&q);
	assert(1<=n && n<=200000);
	assert(1<=C && C<=n);
	assert(1<=q && q<=200000);

	assert(q==1);

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
		dp[0][0]=0;
		dp[0][1]=C;
		for(int i=1;i<=n;i++){
			dp[i][0]=min(dp[i-1][0],dp[i-1][1])+(s[i]=='1');
			dp[i][1]=min(dp[i-1][0]+C,dp[i-1][1])+(s[i]=='0');
		}
		printf("%i\n",min(dp[n][0],dp[n][1]));
	}
	return 0;
}
