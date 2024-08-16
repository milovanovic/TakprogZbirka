#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
vector<int> g[2*MAXN];
int d[2*MAXN];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    fill(d,d+2*MAXN,2*MAXN);
    d[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++) if(d[g[u][i]]==2*MAXN)
        {
            d[g[u][i]]=d[u]+1;
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
    bfs(s);
    cout<<d[t]/2;
}
