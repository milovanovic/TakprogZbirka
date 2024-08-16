#include <bits/stdc++.h>
#define MAXN (1<<20)+7
using namespace std;
pair<int,int> p[MAXN];
vector<pair<int,int> > queries[MAXN];
int br[2*MAXN],ans[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].first;
    for(int i=0;i<n;i++) p[i].second=i;
    sort(p,p+n,greater<pair<int,int>>());
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        queries[t1-1].push_back({t2,i});
    }
    for(int i=0;i<n;i++)
    {
        int poz=n+p[i].second,t=0;
        sort(queries[p[i].second].begin(),queries[p[i].second].end());
        int k=1;
        while(poz!=1)
        {
            poz/=2;
            int treba=(n-i<(1<<k))?MAXN:br[poz];
            while(t<queries[p[i].second].size() && queries[p[i].second][t].first<treba) {ans[queries[p[i].second][t].second]=k; t++;}
            br[poz]++;
            k++;
        }
    }
    int log=0;
    while((1<<log)!=n) log++;
    for(int i=0;i<queries[p[0].second].size();i++)  ans[queries[p[0].second][i].second]=log+1;
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
}