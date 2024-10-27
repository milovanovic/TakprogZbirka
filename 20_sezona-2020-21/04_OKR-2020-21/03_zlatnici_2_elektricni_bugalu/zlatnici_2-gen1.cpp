#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
mt19937 rng(2);
map<int,bool> m;
int a[MAXN];
int main()
{
	int br,n,q,seed,mx;
	scanf("%d%d%d%d%d",&br,&n,&q,&mx,&seed);
	rng=mt19937(seed);
	char ch[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(ch,"w");
	fprintf(fptc,"%d\n",n);
	for(int i=0;i<n;i++)
	{
		int t=uniform_int_distribution<int>(1,mx)(rng);
		while(m[t]) t=uniform_int_distribution<int>(1,mx)(rng);
		a[i]=t;
		m[t]=true;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) {fprintf(fptc,"%d",a[i]); if(i==n-1) fprintf(fptc,"\n"); else fprintf(fptc," ");}
	fprintf(fptc,"%d",q);
	for(int i=0;i<q;i++) fprintf(fptc,"\n%d",uniform_int_distribution<int>(1,mx)(rng));
	fclose(fptc);
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d",br,n,q,mx,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d",br,n,q,mx,seed);
	fclose(fp);
}
