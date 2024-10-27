#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
char s[maxn];
int dp[maxn][maxn];
int n;
int pref[maxn];
int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    assert(2<=n && n<=3000);
    for(int i=1;i<=n;i++) {
        assert('a'<=s[i] && s[i]<='z');
    }
    for(int l=1;l<=n;l++) {
        for(int r=l;r<=n;r++) {
            dp[l][r]=-n;
            if(l==1) dp[l][r]=0;
        }
    }
    for(int l=3;l<=n;l++) {
        pref[0]=-2*n;
        for(int x=1;x<=l-1;x++) {
            pref[x]=max(pref[x-1],dp[x][l-1]);
        }
        int ad=0;
        int cmax=pref[l-1];
        if(s[l]==s[l-1]) ad++;
        cmax=max(cmax,pref[l-1]+ad);
        for(int r=l+1;r<=n;r++) {
            if(2*l-r-1>=1 && s[r]==s[2*l-r-1]) {
                ad++;
                cmax=max(cmax,pref[2*l-r-1]+ad);
            }
            dp[l][r]=cmax;
        }
    }
    int ans=0;
    for(int l=1;l<=n;l++) ans=max(ans,dp[l][n]);
    printf("%d",ans);
    return 0;
}
