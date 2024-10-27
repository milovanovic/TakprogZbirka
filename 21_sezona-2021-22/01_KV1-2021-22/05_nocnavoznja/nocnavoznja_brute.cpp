#include <bits/stdc++.h>
#define MAXN 80007
using namespace std;
vector<int> g[MAXN];
int d[MAXN],n,q,per[MAXN];
void dfs(int s,int f,int dub)
{
    d[s]=dub;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfs(g[s][i],s,dub+1);
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
    scanf("%d",&q);
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            swap(per[x],per[y]);
        }
        else
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            dfs(x,x,0);
            int mx=0;
            for(int i=l;i<=r;i++) mx=max(mx,d[per[i]]);
            printf("%d\n",mx);
        }
    }
}
