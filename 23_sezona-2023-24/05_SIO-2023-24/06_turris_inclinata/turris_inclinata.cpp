#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 300007
using namespace std;
long long val[MAXN], dp[MAXN];
void Penjanje(int N,int Q,int *P,int *F,int *U,int *O)
{
    for(int i=1;i<=N+1;i++) dp[i]=val[i]=0;
    dp[N]=1;
    for(int i=N;i>=1;i--)
    {
        val[i]=(val[i+1]+P[i]*dp[i])%MOD;
        dp[i-1]=(dp[i-1]+P[i]*dp[i])%MOD;
        dp[F[i]-1]=(dp[F[i]-1]+(1+MOD-P[i])*dp[i])%MOD;
    }
    for(int i=1;i<=Q;i++) O[i]=val[U[i]];
}
