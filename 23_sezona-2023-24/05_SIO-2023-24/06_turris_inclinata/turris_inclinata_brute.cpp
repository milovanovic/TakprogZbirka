#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 300007
using namespace std;
long long c[MAXN], dp[MAXN];
void Penjanje(int N,int Q,int *P,int *F,int *U,int *O)
{
    for(int i=1;i<=Q;i++)
    {
        int poz=U[i],t=0;
        while(poz!=N+1)
        {
            c[poz]++;
            t++;
            if(c[poz]%P[poz]==0) poz++;
            else poz=max(U[i],F[poz]);
        }
        O[i]=t;
    }
}
