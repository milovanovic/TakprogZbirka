#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
vector<int> g[2*MAXN];
int d[2][2*MAXN];
void bfs(int k,int s)
{
    queue<int> q;
    q.push(s);
    fill(d[k],d[k]+2*MAXN,2*MAXN);
    d[k][s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++) if(d[k][g[u][i]]==2*MAXN)
        {
            d[k][g[u][i]]=d[k][u]+1;
            q.push(g[u][i]);
        }
    }
}
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(0,s);
    bfs(1,t);
    int mindist=2*MAXN;
    for(int i=1;i<=n;i++) if((d[0][i]+d[1][i])%2==0) mindist=min(mindist,(d[0][i]+d[1][i])/2);
    cout<<mindist;
}
