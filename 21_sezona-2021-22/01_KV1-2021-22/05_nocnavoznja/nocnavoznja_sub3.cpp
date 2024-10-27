#include <bits/stdc++.h>
#define MAXN 80007
using namespace std;
vector<int> g[MAXN];
int d[MAXN],n,q,per[MAXN],seg[4*MAXN];
void dfs(int s,int f,int dub)
{
    d[s]=dub;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfs(g[s][i],s,dub+1);
}
void upd(int l,int r,int w,int v,int ind)
{
    if(l==r) {seg[ind]=v; return;}
    int s=(l+r)/2;
    if(w<=s) upd(l,s,w,v,2*ind);
    else upd(s+1,r,w,v,2*ind+1);
    seg[ind]=max(seg[2*ind],seg[2*ind+1]);
}
int nmax(int l,int r,int lt,int rt,int ind)
{
    if(l>=lt && r<=rt) return seg[ind];
    if(r<lt || l>rt) return 0;
    int s=(l+r)/2;
    return max(nmax(l,s,lt,rt,2*ind),nmax(s+1,r,lt,rt,2*ind+1));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&per[i]);
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1,1,0);
    scanf("%d",&q);
    for(int i=1;i<=n;i++) upd(1,n,i,d[per[i]],1);
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            swap(per[x],per[y]);
            upd(1,n,x,d[per[x]],1);
            upd(1,n,y,d[per[y]],1);
        }
        else
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",nmax(1,n,l,r,1));
        }
    }
}
