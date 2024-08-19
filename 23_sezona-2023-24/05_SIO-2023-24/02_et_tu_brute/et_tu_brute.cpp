#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000007
using namespace std;
pair<int,int> v[MAXN],u[MAXN];
long long fastpow(long long exp, long long base)
{
    if(exp==0) return 1;
    if(exp&1) return (fastpow(exp-1,base)*base)%MOD;
    return fastpow(exp/2,(base*base)%MOD);
}
int Cezar(int N,int K,int* A)
{
    for(int i=1;i<=N;i++) v[i]={0,i};
    long long cnt=0;
    for(int j=0;j<K;j++)
    {
        int t=1,t1=1,t2=N;
        for(int i=1;i<=N;i++) u[i]=v[i];
        for(int i=1;i<=N;i++) if(!(A[u[i].second]&(1<<j))) v[t++]={(A[u[i].second]&(1<<j))+u[i].first,u[i].second};
        for(int i=1;i<=N;i++) if(A[u[i].second]&(1<<j)) v[t++]={(A[u[i].second]&(1<<j))+u[i].first,u[i].second};
        while(t1<=t2)
        {
            while(t2>=1 && v[t1].first+v[t2].first>=(1<<(j+1))) t2--;
            if(t2<t1) break;
            cnt+=t2-t1+1;
            t1++;
        }
    }
    cnt+=(N+1LL)*N/2LL;
    return fastpow(cnt,2);
}
