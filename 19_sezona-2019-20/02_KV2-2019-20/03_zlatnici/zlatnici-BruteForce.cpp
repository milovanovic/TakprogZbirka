#include <bits/stdc++.h>
using namespace std;
int x[10],y[10],p[10],q[10];
int main()
{
	int n,res=100; 
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++) p[i]=i;
	do
	{
		for(int i=0;i<n;i++) q[i]=i;
		do 
		{
			int c=0;
			for(int i=0;i<n;i++) c+=abs(p[i]+1-x[i])+abs(q[i]+1-y[i]);
			res=min(c,res);
		} while(next_permutation(q,q+n));
	} while(next_permutation(p,p+n));
	printf("%d",res);
}
