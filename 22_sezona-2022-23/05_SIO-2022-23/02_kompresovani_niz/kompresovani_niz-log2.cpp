#include <bits/stdc++.h>
#define maxn 100005
#define maxl 31
using namespace std;
int l;
long long dp[maxn];
long long prev_bit[maxl];
set<pair<int,long long> > values[maxn];
set<pair<int,long long> >::iterator it;
long long Resi(int N, int* A, int K)
{
    l=K-1;
    vector<pair<int,int> > v;
    values[0].insert({0,0});
    for(int i=1;i<=N;i++) {
        v.clear();
        for(int j=0;j<maxl;j++) {
            if(A[i]&(1<<j)) prev_bit[j]=i;
            v.push_back({prev_bit[j],j});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        dp[i]=A[i]+dp[i-1];
        int o=0;
        int c=(i-1);
        for(int j=0;j<v.size();j++) {
            if(v[j].first==0) break;
            if(v[j].first==i) {
                o|=(1<<v[j].second);
                continue;
            }
            if(j!=0 && v[j].first==v[j-1].first) {
                o|=(1<<v[j].second);
                continue;
            }
            int rm=c%l;
            int start=c-l*((c-(v[j].first))/l);
            it=values[rm].lower_bound({start,-1});
            dp[i]=min(dp[i],(*it).second+o);
            o|=(1<<v[j].second);
        }
        int rm=c%l;
        int start=c-l*(c/l);
        it=values[rm].lower_bound({start,-1});
        dp[i]=min(dp[i],(*it).second+o);
        int cur_rm=i%l;
        pair<int,long long> new_dp={i,dp[i]};
        while(!values[cur_rm].empty() && (*values[cur_rm].rbegin()).second>=new_dp.second) {
            values[cur_rm].erase(*values[cur_rm].rbegin());
        }
        values[cur_rm].insert(new_dp);
    }
    return dp[N];
}