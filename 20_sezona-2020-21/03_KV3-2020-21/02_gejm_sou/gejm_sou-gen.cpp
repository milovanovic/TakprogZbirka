#include <bits/stdc++.h>
#define MAXN 1000007
using namespace std;
mt19937 rng(2);
vector<pair<int,int>> g;
int main()
{
	int br,n,seed,mx;
	scanf("%d%d%d%d",&br,&n,&mx,&seed);
	rng=mt19937(seed);
	char ch[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(ch,"w");
	fprintf(fptc,"%d\n",n);
	for(int i=0;i<n;i++) fprintf(fptc,"%d %d\n",uniform_int_distribution<int>(-mx,+mx)(rng),uniform_int_distribution<int>(-mx,+mx)(rng));
	fclose(fptc);
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d",br,n,mx,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d",br,n,mx,seed);
	fclose(fp);
}
