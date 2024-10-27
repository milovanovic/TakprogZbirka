#include <bits/stdc++.h>
#define MAXN 1000007
using namespace std;
long long a[MAXN],pref[MAXN],suf[MAXN],bit[MAXN],cnt[MAXN],ub[MAXN];
int n,k;
long long sumk(int z)
{
    long long cur=0,sum=0,sol=0;
    for(int i=20;i>=0;i--)
    {
        if(cur+(1<<i)>=MAXN) continue;
        if(cnt[cur+(1<<i)]+sum<z) {sum+=cnt[cur+(1<<i)]; sol+=bit[cur+(1<<i)]; cur+=(1<<i);}
    }
    return sol+(100000LL-cur)*(z-sum);
}
void upd(long long val,int z)
{
    int br=100001-val;
    while(br<MAXN)
    {
        bit[br]+=z*val;
        cnt[br]+=z;
        br+=br&(-br);
    }
}
long long solve()
{
    pref[1]=a[1]; suf[n]=a[n];
    fill(bit,bit+MAXN,0); fill(cnt,cnt+MAXN,0);
    for(int i=2;i<=n;i++) pref[i]=max(pref[i-1],a[i]);
    for(int i=n-1;i>=1;i--) suf[i]=min(suf[i+1],a[i]);
    for(int i=n-1;i>=2;i--)
    {
        if(suf[i]==suf[i+1]) {upd(-a[i],1); ub[i]=-a[i];}
        else {upd(-suf[i+1],1); ub[i]=-suf[i+1];}
    }
    long long res=0;
    for(int i=1;i<n;i++)
    {
        res=max(res,pref[i]-suf[i+1]+sumk(k-2));
        if(i+1==n) break;
        if(pref[i+1]==pref[i]) upd(a[i+1],1);
        else upd(pref[i],1);
        upd(ub[i+1],-1);
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    long long sol=solve();
    reverse(a+1,a+n+1);
    sol=max(sol,solve());
    cout<<sol;
}
