#include <bits/stdc++.h>
#define MAXN 1000007
#define MAXL 22
#define MOD 1000000007
using namespace std;
int a[MAXN],lg[MAXN],rg[MAXN],l[MAXN],r[MAXN];
long long dp[MAXN];
void dfs(int s)
{
    if(l[s]) dfs(l[s]);
    if(r[s]) dfs(r[s]);
    if(l[s] || r[s]) dp[s]=(dp[l[s]]*dp[r[s]]+1)%MOD;
    else dp[s]=2;
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
    dp[0]=1;
}
int Query(int L,int R)
{
    int root;
    for(int i=L;i<=R;i++)
    {
        if(lg[i]<L && rg[i]>R) {root=i; continue;}
        if(rg[i]>R || (lg[i]>=L && a[lg[i]]<a[rg[i]])) r[lg[i]]=i;
        else l[rg[i]]=i;
    }
    dfs(root);
    for(int i=L;i<=R;i++) l[i]=r[i]=0;
    return dp[root];
}
