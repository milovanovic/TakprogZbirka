#include <bits/stdc++.h>
using namespace std;
int seed;
map<pair<int,int>,bool> mp;
int main()
{
	int n,m,seed;
	scanf("%d%d",&n,&seed);
	mt19937 rng(seed);
	freopen("02.in","w",stdout);
	printf("%d",n);
	m=n;
	while(n)
	{
		int r=uniform_int_distribution<int>(m/2, m)(rng),c=uniform_int_distribution<int>(m/2, m)(rng);
		if(mp[make_pair(r,c)]) continue;
		n--;
		printf("\n%d %d",r,c);
		mp[make_pair(r,c)]=true;
	}
}
