#include <bits/stdc++.h>
using namespace std;
void ckmn(int&a,int b){a=min(a,b);}
void ckmx(int&a,int b){a=max(a,b);}
const int N=100050;
const int M=1<<10;
const int inf=1e9+7;
char s[N];
int dp[10][M],best[M];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	fill(dp[0],dp[0]+M*10,-inf);
	fill(best,best+M,-inf);
	for(int i=0;i<10;++i)dp[i][1<<i]=0,best[1<<i]=0;
	for(int i=1;i<=n;++i){
		int c=s[i]-'0';
		for(int mask=M-1;mask>=0;--mask){
			if(mask>>c&1){
				dp[c][mask]=max(dp[c][mask],best[mask^(1<<c)])+1;
				ckmx(best[mask],dp[c][mask]);
			}
		}
	}
	int ans=-inf;
	for(int i=0;i<M;i++)ckmx(ans,best[i]);
	printf("%i\n",n-ans);
	return 0;
}