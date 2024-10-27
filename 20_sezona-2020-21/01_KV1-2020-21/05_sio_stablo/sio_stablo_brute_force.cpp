#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=300050;
vector<pair<int,char>> E[N];
ll ans=0;
void DFS(int u,int p,int st,int S,int I,int O){
	if(st<u&&S==I&&S==O)ans++;
	for(auto e:E[u])if(e.first!=p){
		DFS(e.first,u,st,S+(e.second=='S'),I+(e.second=='I'),O+(e.second=='O'));
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
	for(int i=1;i<=n;i++)DFS(i,0,i,0,0,0);
	printf("%lld\n",ans);
	return 0;
}
