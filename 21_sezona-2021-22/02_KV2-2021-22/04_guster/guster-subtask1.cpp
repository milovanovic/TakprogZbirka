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
        for(int l=1;l+1<=r;l++) {
            for(int x=1;x+2<=l;x++) {
                int cur=dp[x][l-1];
                for(int y=0;l+y<=r && l-1-y>=x;y++) {
                    if(s[l+y]==s[l-1-y]) cur++;
                }
                dp[l][r]=max(dp[l][r],cur);
            }
        }
    }
    int ans=0;
    for(int l=1;l<=n;l++) ans=max(ans,dp[l][n]);
    printf("%d",ans);
    return 0;
}
