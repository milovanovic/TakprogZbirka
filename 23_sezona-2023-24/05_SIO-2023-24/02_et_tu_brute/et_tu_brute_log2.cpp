#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000007
using namespace std;
int v[MAXN];
long long fastpow(long long exp, long long base)
{
    if(exp==0) return 1;
    if(exp&1) return (fastpow(exp-1,base)*base)%MOD;
    return fastpow(exp/2,(base*base)%MOD);
}
int Cezar(int N,int K,int* A)
{
    long long cnt=0;
    for(int j=0;j<K;j++)
    {
        for(int i=1;i<=N;i++) v[i]=(A[i]&((1<<(j+1))-1));
        sort(v+1,v+N+1);
        int t1=1,t2=N;
        while(t1<=t2)
        {
            while(t2>=1 && v[t1]+v[t2]>=(1<<(j+1))) t2--;
            if(t2<t1) break;
            cnt+=t2-t1+1;
            t1++;
        }
    }
    cnt+=(N+1LL)*N/2LL;
    return fastpow(cnt,2);
}
