#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
const int N=300050;
vector<pair<int,char>> E[N];
map<pii,int> cnt[N];
pii add[N];
pii operator + (pii a,pii b){return {a.first+b.first,a.second+b.second};}
pii operator += (pii&a,pii b){return a=a+b;}
pii operator - (pii a,pii b){return {a.first-b.first,a.second-b.second};}
pii operator - (pii a){return {-a.first,-a.second};}
pii get(char c){
	if(c=='S')return {1,1};
	else if(c=='I')return {-1,0};
	else return {0,-1};
}
ll ans;
void DFS(int u,int p){
	cnt[u][{0,0}]++;
	add[u]={0,0};
	for(auto e:E[u])if(e.first!=p){
		DFS(e.first,u);
		add[e.first]+=get(e.second);
		if(cnt[u].size()<cnt[e.first].size())cnt[u].swap(cnt[e.first]),swap(add[u],add[e.first]);
		for(auto it:cnt[e.first]){
			pii now=it.first+add[e.first];
			if(cnt[u].count(-now-add[u]))
				ans+=(ll)cnt[u][-now-add[u]]*it.second;
		}
		for(auto it:cnt[e.first]){
			pii now=it.first+add[e.first];
			cnt[u][now-add[u]]+=it.second;
		}
	}
}
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<n;i++){
		int u,v;char c;
		scanf("%i %i %c",&u,&v,&c);
		E[u].pb({v,c});
		E[v].pb({u,c});
	}
	DFS(1,0);
	printf("%lld\n",ans);
	return 0;
}
