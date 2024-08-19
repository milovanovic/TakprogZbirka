#include <bits/stdc++.h>

using namespace std;
long long typedef ll;
pair<int,int> typedef typ;

ll sum[200005];
int up[200005];
priority_queue<typ,vector<typ>,greater<typ>> stanja[200005]; //(velicina,vreme) za svakog organizma u komponenti
bool impo[200005];

void dsu(int a, int b, int s)
{
    while (up[a]>0) a=up[a];
    while (up[b]>0) b=up[b];
    if (a==b) return;

    if (up[a]!=-1 || sum[a]==s)
    {
        while (true)
        {
            int tt=stanja[a].top().first;
            int ind=stanja[a].top().second;
            int k=-up[a];
            ll ts=sum[a]+(ll)k*tt;
            if (ts>=s+tt) break;
            stanja[a].pop();
            if (impo[ind]) continue;

            int x=(s+tt-ts+k-2)/(k-1);
            stanja[a].push({tt+x,ind});
        }
    }
    else impo[a]=true;

    if (up[a]<up[b]) swap(a,b);
    up[b]+=up[a],sum[b]+=sum[a],up[a]=b;
    while (!stanja[a].empty())
    {
        stanja[b].push(stanja[a].top());
        stanja[a].pop();
    }
}

vector<int> g[200005];

void OdrediVreme(int N, int M, int* S, int *U, int *V, int *T)
{
    for (int i=1;i<=M;i++)
    {
        g[U[i]].push_back(V[i]);
        g[V[i]].push_back(U[i]);
    }

    vector<pair<int,int>> sorta;
    for (int i=1;i<=N;i++) sorta.push_back({S[i],i});
    sort(sorta.begin(),sorta.end());
    vector<int> id(N+1);
    for (int i=0;i<N;i++) id[sorta[i].second]=i;

    for (int i=1;i<=N;i++) up[i]=-1;
    for (int i=1;i<=N;i++) stanja[i].push({0,i});
    for (int i=1;i<=N;i++) sum[i]=S[i];

    for (auto p : sorta)
    {
        for (auto it : g[p.second])
        {
            if (id[it]<id[p.second]) dsu(it,p.second,p.first);
        }
    }

    int root=1;
    while (up[root]>0) root=up[root];
    while (!stanja[root].empty())
    {
        T[stanja[root].top().second]=stanja[root].top().first;
        stanja[root].pop();
    }

    for (int i=1;i<=N;i++) if (impo[i]) T[i]=-1;
}