#include <bits/stdc++.h>
#define MAXN 500007
#define MAXL 20
#define MOD 1000000007
using namespace std;
int a[MAXN],lg[MAXN],rg[MAXN],l[MAXN],r[MAXN],in[MAXN],out[MAXN],p[MAXL][MAXN],t;
long long dp[MAXN],mul[2][MAXL][MAXN],pls[2][MAXL][MAXN];
void dfs(int s)
{
    in[s]=t++;
    if(l[s]) dfs(l[s]);
    if(r[s]) dfs(r[s]);
    if(l[s] || r[s]) dp[s]=(dp[l[s]]*dp[r[s]]+1)%MOD;
    else dp[s]=2;
    out[s]=t++;
}
void Init(int N, int* A)
{
    a[0]=N+2;
    a[N+1]=N+1;
    stack<int> st; st.push(0);
    for(int i=1;i<=N;i++) a[i]=A[i];
    for(int i=1;i<=N;i++)
    {
        while(a[st.top()]<a[i]) st.pop();
        lg[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(N+1);
    for(int i=N;i>=1;i--)
    {
        while(a[st.top()]<a[i]) st.pop();
        rg[i]=st.top();
        st.push(i);
    }
    for(int i=1;i<=N;i++) l[i]=r[i]=0;
    for(int i=1;i<=N;i++)
    {
        if(a[lg[i]]<a[rg[i]])
        {
            p[0][i]=lg[i];
            r[lg[i]]=i;
        }
        else
        {
            p[0][i]=rg[i];
            l[rg[i]]=i;
        }
    }
    dp[0]=1;
    dfs(N+1);
    p[0][N+1]=N+1;
}
int Query(int L,int R)
{
    long long lv=1,ds=1;
    int t=L;
    while(true)
    {
        if(rg[t]>R) break;
        lv=(lv*dp[r[t]]+1)%MOD;
        t=rg[t];
    }
    t=R;
    while(true)
    {
        if(lg[t]<L) break;
        ds=(ds*dp[l[t]]+1)%MOD;
        t=lg[t];
    }
    return (lv*ds+1)%MOD;
}
