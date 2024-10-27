#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
mt19937 rng(2);
map<int,bool> m;
int a[MAXN];
int main()
{
	int br,n,q,seed,mnx,mny,mxx,mxy;
	scanf("%d%d%d%d%d%d%d%d",&br,&n,&q,&mnx,&mxx,&mny,&mxy,&seed);
	rng=mt19937(seed);
	char ch[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(ch,"w");
	fprintf(fptc,"%d\n",n);
	for(int i=0;i<n;i++) fprintf(fptc,"%d %d\n",uniform_int_distribution<int>(mnx,mxx)(rng), uniform_int_distribution<int>(mny,mxy)(rng));
	fprintf(fptc,"%d",q);
	for(int i=0;i<q;i++) 
	{
		int l=uniform_int_distribution<int>(1,n)(rng),r=uniform_int_distribution<int>(1,n)(rng);
		if(l>r) swap(l,r);
		fprintf(fptc,"\n%d %d %d %d",uniform_int_distribution<int>(mnx,mxx)(rng), uniform_int_distribution<int>(mny,mxy)(rng),l,r);
	}
	fclose(fptc);
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d\t%d\t%d\t%d",br,n,q,mnx,mxx,mny,mxy,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d\t%d\t%d\t%d",br,n,q,mnx,mxx,mny,mxy,seed);
	fclose(fp);
}
