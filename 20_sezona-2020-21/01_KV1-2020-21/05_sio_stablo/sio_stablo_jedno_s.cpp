#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=300050;
vector<pair<int,char>> E[N];
int main(){
	int n;scanf("%i",&n);
	int a,b;
	for(int i=1;i<n;i++){
		int u,v;char c;
		scanf("%i %i %c",&u,&v,&c);
		E[u].pb({v,c});
		E[v].pb({u,c});
		if(c=='S')a=u,b=v;
	}
	ll ans=0;
	for(int u:{a,b}){
		for(auto e:E[u]){
			if(e.second=='O')for(auto d:E[e.first])if(d.second=='I')ans++;
			if(e.second=='I')for(auto d:E[e.first])if(d.second=='O')ans++;
		}
	}
	map<char,int> cnt[2];
	for(auto e:E[a])cnt[0][e.second]++;
	for(auto e:E[b])cnt[1][e.second]++;
	ans+=(ll)cnt[0]['O']*cnt[1]['I']+(ll)cnt[0]['I']*cnt[1]['O'];
	printf("%lld\n",ans);
	return 0;
}
