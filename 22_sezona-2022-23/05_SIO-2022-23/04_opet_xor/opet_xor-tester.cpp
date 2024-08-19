#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
int bit[70][MAXN],n;
void upd(int k,int ind,int s)
{
    while(ind<=n)
    {
        bit[k][ind]+=s;
        ind+=(ind&(-ind));
    }
}
int val(int k,int ind)
{
    int sol=0;
    while(ind)
    {
        sol+=bit[k][ind];
        ind-=(ind&(-ind));
    }
    return sol;
}
int interval(int k,int l,int r)
{
    return val(k,r)-val(k,l-1);
}
void updniz(int poz,int val,int k)
{
    for(int j=0;j<30;j++)if((1<<j)&val)
    {
        if(val>=(1<<(j+1))) upd(j,poz,k);
        else upd(j+35,poz,k);
    }
}
void Resi(int N, int *A, int Q, int *T, int *I, int *X, bool *O)
{
    n=N;
    for(int i=1;i<=N;i++) updniz(i,A[i],+1);
    for(int i=1;i<=Q;i++)
    {
        if(T[i]==1)
        {
            updniz(I[i],A[I[i]],-1);
            updniz(I[i],X[i],+1);
            A[I[i]]=X[i];
        }
        else
        {
            O[i]=true;
            if(X[i]>5) {O[i]=false; continue;}
            for(int j=0;j<30;j++) if(interval(j+35,I[i],I[i]+X[i]-1)>interval(j,I[i],I[i]+X[i]-1)+1) O[i]=false;
        }
    }
}
