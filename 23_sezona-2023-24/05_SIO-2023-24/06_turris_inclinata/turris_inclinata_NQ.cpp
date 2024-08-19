#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 300007
using namespace std;
long long val[MAXN], dp[MAXN];
void Penjanje(int N,int Q,int *P,int *F,int *U,int *O)
{
    for(int t=1;t<=Q;t++)
    {
        dp[U[t]-1]=0;
        for(int i=U[t];i<=N;i++) dp[i]=(dp[i-1]*P[i]+((1-P[i])*dp[max(F[i],U[t])-1])%MOD+MOD+P[i])%MOD;
        O[t]=dp[N];
    }
}
