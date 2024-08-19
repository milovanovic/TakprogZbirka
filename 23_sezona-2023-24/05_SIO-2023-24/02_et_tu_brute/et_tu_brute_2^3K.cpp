#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long sol[300][300], cnt[300];
long long fastpow(long long exp, long long base)
{
    if(exp==0) return 1;
    if(exp&1) return (base*fastpow(exp-1,base))%MOD;
    return fastpow(exp/2,(base*base)%MOD);
}
int Cezar(int N,int K,int* A)
{
    for(int i=0;i<(1<<K);i++) for(int j=0;j<(1<<K);j++) for(int k=0;k<(1<<(K+1));k++) if(((i+j)&k)==(i&k)+(j&k)) sol[i][j]++;
    for(int i=1;i<=N;i++) cnt[A[i]]++;
    long long ans=1;
    for(int i=0;i<(1<<K);i++) ans=(ans*fastpow(cnt[i]*(cnt[i]+1)/2,sol[i][i]))%MOD;
    for(int i=0;i<(1<<K);i++) for(int j=i+1;j<(1<<K);j++) ans=(ans*fastpow(cnt[i]*cnt[j],sol[i][j]))%MOD;
    return ans;
}
