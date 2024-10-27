#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
char s[N];
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<n;i++){
		scanf("%*i %*i %c",&s[i]);
	}
	int S=0,I=0,O=0;
	map<pair<int,int>,int> cnt;
	ll ans=0;
	cnt[{0,0}]++;
	for(int i=1;i<n;i++){
		if(s[i]=='S')S++;
		else if(s[i]=='I')I++;
		else O++;
		ans+=cnt[{S-I,S-O}];
		cnt[{S-I,S-O}]++;
	}
	printf("%lld\n",ans);
	return 0;
}
