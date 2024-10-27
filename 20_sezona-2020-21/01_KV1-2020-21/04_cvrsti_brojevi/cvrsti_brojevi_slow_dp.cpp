#include <bits/stdc++.h>
using namespace std;
int dp[2][10][1024],mx[1024];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<1024;i++) for(int j=0;j<10;j++) dp[0][j][i]=dp[1][j][i]=1000000000;
	int l=1;
	for(int i=0;i<10;i++) dp[0][i][1<<i]=(s[0]==i+'0')?0:1;
	for(int j=1023;j>=0;j--) {mx[j]=1000000; for(int k=0;k<10;k++) if((1<<k)&j) mx[j]=min(mx[j],dp[0][k][j]);}
	for(int i=1;i<s.size();i++)
	{
		int c=s[i]-'0';
		for(int j=1023;j>=0;j--) for(int k=0;k<10;k++) if((1<<k)&j)
		{
			int dif=((s[i]==k+'0')?0:1);
			dp[l][k][j]=dp[l^1][k][j]+dif;
			dp[l][k][j]=min(dp[l][k][j],mx[j^(1<<k)]+dif);
		}
		for(int j=1023;j>=0;j--) {mx[j]=1000000; for(int k=0;k<10;k++) if((1<<k)&j) mx[j]=min(mx[j],dp[l][k][j]);}
		l^=1;
	}
	int x=10000000; for(int i=0;i<1024;i++) for(int j=0;j<10;j++) x=min(x,dp[l^1][j][i]);
	cout<<x;
}
