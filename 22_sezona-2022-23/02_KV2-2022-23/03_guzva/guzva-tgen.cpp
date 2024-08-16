#include <bits/stdc++.h>
#include "testlib.h"
#define ll long long
#define inf 1e18
using namespace std;
int n,m,q;
vector<vector<ll> > a,dp_top,dp_bot,pref,suf;
vector<pair<int,int> > inc;
vector<pair<int,int> > sm;
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    q = atoi(argv[3]);
    printf("%d %d\n",n,m);
    a.resize(n+2);dp_top.resize(n+2);dp_bot.resize(n+2);pref.resize(n+2);suf.resize(n+2);
    for(int i=0;i<=n+1;i++) {
        a[i].resize(m+2);dp_top[i].resize(m+2);dp_bot[i].resize(m+2);pref[i].resize(m+2);suf[i].resize(m+2);
        for(int j=0;j<=m+1;j++) a[i][j]=dp_top[i][j]=dp_bot[i][j]=pref[i][j]=suf[i][j]=inf;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            a[i][j] = rnd.next(1,1000000000);
            printf("%lld",a[i][j]);
            if(j==m) printf("\n");
            else printf(" ");
        }
    }
    dp_top[1][1]=a[1][1]; dp_bot[n][m]=a[n][m];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp_top[i][j]=min(dp_top[i][j],min(dp_top[i-1][j],dp_top[i][j-1])+a[i][j]);
    for(int i=n;i>=1;i--) for(int j=m;j>=1;j--) dp_bot[i][j]=min(dp_bot[i][j],min(dp_bot[i+1][j],dp_bot[i][j+1])+a[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) pref[i][j]=min(pref[i-1][j+1],dp_top[i][j]+dp_bot[i][j]-a[i][j]);
    for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) suf[i][j]=min(suf[i+1][j-1],dp_top[i][j]+dp_bot[i][j]-a[i][j]);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if((i==1 && j==1) || (i==n && j==m)) continue;
            if(dp_top[n][m]==min(pref[i-1][j+1],suf[i+1][j-1])) sm.push_back({i,j});
            else inc.push_back({i,j});
        }
    }
    shuffle(sm.begin(),sm.end());
    shuffle(inc.begin(),inc.end());
    printf("%d\n",q);
    int sm_c=0;
    int inc_c=0;
    for(int i=1;i<=q;i++) {
        int t=rnd.next(1,11);
        if(t==1) {
            printf("%d %d\n",sm[sm_c].first,sm[sm_c].second);
            sm_c+=1;
            sm_c%=(int)sm.size();
        }
        else {
            printf("%d %d\n",inc[inc_c].first,inc[inc_c].second);
            inc_c+=1;
            inc_c%=(int)inc.size();
        }
    }
    return 0;
}
