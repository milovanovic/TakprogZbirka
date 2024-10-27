#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
char s[maxn];
int dp[maxn][maxn];
int n;
int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++) {
        assert('a'<=s[i] && s[i]<='z');
    }
    for(int l=1;l<=n;l++) {
        for(int r=l+1;r<=n;r++) {
            dp[l][r]=-n;
            if(l==1) dp[l][r]=0;
        }
    }
    for(int r=3;r<=n;r++) {
        for(int l=3;l+1<=r;l++) {
            int cur=0;
            if(s[l-1]==s[l]) cur++;
            for(int x=l-2;x>=1;x--) {
                if(2*l-x-1<=r && s[x]==s[2*l-x-1]) cur++;
                dp[l][r]=max(dp[l][r],dp[x][l-1]+cur);
            }
        }
    }
    int ans=0;
    for(int l=1;l<=n;l++) ans=max(ans,dp[l][n]);
    printf("%d",ans);
    return 0;
}
